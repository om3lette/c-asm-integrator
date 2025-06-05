section .data
  tmp dq 0.0
  first_val dq 0.0
  two dd 2.0

section .text
global derivative
call_func:
  ; double call_func(double (*f)(double x))
  ; Calculates
  push ebp
  mov ebp, esp

  mov edx, dword [ebp + 8] ; f(x)
  push dword [tmp + 4]
  push dword [tmp]
  call edx                 ; f(x - esp) -> st0
  add esp, 8

  leave
  ret
derivative:
  ; double derivative(double (*f)(double), double x, double eps);
  ; (f(x + h) - f(x - h)) / 2eps
  ;
  ; Stack depiction
  ; Rel |   Name    | Size (bytes) |
  ; +20 | eps       |      8       |
  ; +12 | x         |      8       |
  ; +8  | f(x)      |      4       |
  ; +4  | return    |      4       |
  ; ebp | saved ebp |      4       |

  push ebp
  mov ebp, esp

  mov ecx, [ebp + 8]     ; f(x) -> ecx

  finit
  fld qword [ebp + 12]   ; x   -> st0
  fld qword [ebp + 20]   ; eps -> st1
  fsubp
  fstp qword [tmp]       ; x - esp -> st0

  push ecx
  call call_func
  add esp, 4
  fstp qword [first_val] ; f(x - esp) -> first_val

  fld qword [ebp + 12] ; x
  fld qword [ebp + 20] ; eps
  faddp                ; x + esp -> st0
  fstp qword [tmp]     ; x + esp -> tmp

  push ecx
  call call_func
  add esp, 4

  ; f(x + esp) -> st0
  ; f(x - esp) -> st1
  fld qword [first_val]
  fsubp
  fstp qword [tmp] ; f(x + esp) - f(x - esp) -> tmp

  ; 2eps
  fld qword [ebp + 20] ; eps
  fld dword [two]
  fmulp

  fld qword [tmp]
  ; f(x + esp) - f(x - esp) -> st1
  ; 2eps                    -> st0
  fxch

  ; f(x + esp) - f(x - esp) -> st0
  ; 2eps                    -> st1
  fdivp

  leave
  ret
