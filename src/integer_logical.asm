global IntegerLogical_

IntegerLogical_:
    ; edi for 1st argument, esi for 2nd argument
    ; edx for 3rd argument, ecx for 4rd argument

    mov eax, edi
    and eax, esi ; eax = a & b
    or eax, edx ; eax = (a & b) | c
    xor eax, edx ; eax = ((a & b) | c) ^ d
    add eax, [g_Val1] ; eax = (((a & b) | c) ^ d) + g_Val1
    ret
