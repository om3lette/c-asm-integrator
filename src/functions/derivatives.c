#include "functions.h"
#include "types.h"

static const double DERIVATIVE_PRECISION = 1e-6;

double f_d(double x) { return derivative(f, x, DERIVATIVE_PRECISION); }
double g_d(double x) { return derivative(g, x, DERIVATIVE_PRECISION); }
double h_d(double x) { return derivative(h, x, DERIVATIVE_PRECISION); }

// Returns whether f''(x) > 0 on section [a; b]
int get_second_der_sign(afunc *f, afunc *g, double a, double b) {
  double point = (a + b) / 2;
  double f_g_1 = f(point) - g(point);

  double f_g_2 = f(a) + g(a) + f(b) + g(b);
  return f_g_1 > f_g_2 / 2 ? -1 : 1;
}
