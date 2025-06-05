section .data
  two dd 2.0

section .text
global f
f:
    ; f(x) = exp(x) + 2
    push    ebp
    mov     ebp, esp

    finit
    ; Thanks: https://stackoverflow.com/a/44970882/20957519
    fldl2e
    fmul qword [ebp + 8]

    fld1
    fld st1

    fprem
    f2xm1
    faddp st1, st0
    fscale
    fstp st1

    fld dword [two]
    faddp st1, st0

    leave
    ret
