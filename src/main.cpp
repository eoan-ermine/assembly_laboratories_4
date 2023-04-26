#include <iostream>
#include <iomanip>

using namespace std;

extern "C" int IntegerLogical_(unsigned int a, unsigned int b, unsigned int c, unsigned int d);

extern "C" unsigned int _g_Val1 = 0;

unsigned int IntegerLogical(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
	int t1 = a & b;
	int t2 = t1 | c;
	int t3 = t2 ^ d;

	std::cout << "t1 = " << oct << t1 << '\n';
	std::cout << "t2 = " << oct << t2 << '\n';
	std::cout << "t3 = " << oct << t3 << '\n';

	return t3 + _g_Val1;
}

static void PrintResult(
	const char* msg,
	unsigned int a, unsigned int b, unsigned int c, unsigned int d,
	unsigned int gVal, unsigned int result_1, unsigned int result_2
) {
	cout << msg << '\n';

	const int w = 8;
	cout << setfill('0');

	cout << "a = " << oct << setw(w) << a << " (" << dec << a << ')' << '\n';
	cout << "b = " << oct << setw(w) << b << " (" << dec << b << ')' << '\n';
	cout << "c = " << oct << setw(w) << c << " (" << dec << c << ')' << '\n';
	cout << "d = " << oct << setw(w) << d << " (" << dec << d << ')' << '\n';

	cout << "gVal = " << oct << setw(w) << gVal << " (" << dec << gVal << ')' << '\n';
	cout << "result_1 = " << oct << setw(w) << result_1 << " (" << dec << result_1 << ')' << '\n';
	cout << "result_2 = " << oct << setw(w) << result_2 << " (" << dec << result_2 << ')' << '\n';

	if (result_1 != result_2) {
		cout << "Ошибка сравнения" << '\n';
	}
}

int main() {
	{
		unsigned int a = 0x00223344, b = 0x00775544, c = 0x00555555, d = 0x00998877;
		_g_Val1 = 7;
		unsigned int r1 = IntegerLogical(a, b, c, d), r2 = IntegerLogical_(a, b, c, d);
		PrintResult("Пример 1", a, b, c, d, _g_Val1, r1, r2);
	}
	{
		unsigned int a = 0x70987655, b = 0x55555555, c = 0xAAAAAAAA, d = 0x12345678;
		_g_Val1 = 23;
		unsigned int r1 = IntegerLogical(a, b, c, d), r2 = IntegerLogical_(a, b, c, d);
		PrintResult("Пример 2", a, b, c, d, _g_Val1, r1, r2);
	}
}