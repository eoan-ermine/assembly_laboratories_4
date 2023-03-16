global IntegerLogical_
extern _g_Val1

IntegerLogical_:
    ; edi for 1st argument, esi for 2nd argument
    ; edx for 3rd argument, ecx for 4rd argument

    mov eax, edi
    and eax, esi ; eax = a & b
    or eax, edx ; eax = (a & b) | c
    xor eax, ecx ; eax = ((a & b) | c) ^ d
    add eax, [_g_Val1] ; eax = (((a & b) | c) ^ d) + g_Val1

    ret
