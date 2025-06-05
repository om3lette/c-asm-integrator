section .data
  mtwo dd -2.0
  eight dd 8.0

section .text
global g
g:
  ; f_2(x) = −2x + 8
  push ebp
  mov ebp, esp

  finit
  ; -2x
  fld qword [ebp + 8]
  fld dword [mtwo]
  fmulp

  ; + 8
  fld dword [eight]
  faddp

  leave
  ret
