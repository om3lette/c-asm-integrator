section .data
  mfive dd -5.0

section .text
global h
h:
  ; f_3(x) = −5/x
  push ebp
  mov ebp, esp

  finit
  fld dword [mfive]
  fld qword [ebp + 8]
  fdivp

  leave
  ret
