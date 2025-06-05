#include "functions.h"

static const double DERIVATIVE_PRECISION = 1e-6;

double f_d(double x) { return derivative(f, x, DERIVATIVE_PRECISION); }
double g_d(double x) { return derivative(g, x, DERIVATIVE_PRECISION); }
double h_d(double x) { return derivative(h, x, DERIVATIVE_PRECISION); }

// Returns whether f''(x) > 0 on section [a; b]
int get_second_der_sign(double (*f)(double), double a, double b) {
  return f((a + b) / 2) > (f(a) + f(b)) / 2 ? -1 : 1;
}
