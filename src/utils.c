#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

afunc *get_function_by_index(int idx) {
  switch (idx) {
  case 1:
    return f;
  case 2:
    return g;
  case 3:
    return h;
  default:
    fprintf(stderr, "Invalid function index: %d.\n", idx);
    exit(1);
  }
}

afunc *get_function_der_by_index(int idx) {
  switch (idx) {
  case 1:
    return f_d;
  case 2:
    return g_d;
  case 3:
    return h_d;
  default:
    fprintf(stderr, "Invalid function derivative index: %d.\n", idx);
    exit(1);
  }
}

struct errors get_calculation_errors(double answer, double expected_answer) {
  struct errors errs;
  errs.absolute = expected_answer - answer;
  errs.relative = errs.absolute / expected_answer;
  return errs;
}

double func_sub(afunc *f, afunc *g, double x) { return f(x) - g(x); }

int get_der_mult_sign(afunc f, afunc g, afunc f_d, afunc g_d, double a, double b) {
  if (func_sub(f_d, g_d, a) * get_second_der_sign(f, g, a, b) > 0) {
    return 1;
  }
  return -1;
}

int get_sign(double x) { return x > 0 ? 1 : -1; }
