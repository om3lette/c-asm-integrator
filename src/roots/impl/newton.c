#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>

#include "functions.h"
#include "roots.h"

double get_newton_starting_point(double (*f)(double), double (*f_d)(double), double a, double b) {
  return f_d(a) * get_second_der_sign(f, a, b) > 0 ? b : a;
}

struct res_iter_pair
newton_root(afunc *f, afunc *g, afunc *f_d, afunc *g_d, double a, double b, double eps1) {
  // Pseudo code
  // for i from 1 to N_max:
  //     f_val_x = f(x) - g(x)
  //     f_der_x ← f(x) - g(x)

  //     if f_der_x = 0:
  //         exit
  //
  //     new_x = x - f_val_x / f_prime_x
  //
  //     if |new_x - x| < eps:
  //         return new_x
  //     x = new_x
  double x = get_newton_starting_point(f, f_d, a, b);
  static const uint32_t MAX_ITER = 100;

  struct res_iter_pair res;
  res.res = NAN;
  res.iter = -1;

  for (uint32_t i = 0; i < MAX_ITER; i++) {
    double f_val_x = f(x) - g(x);
    double f_der_x = f_d(x) - g_d(x);

    double new_x = x - f_val_x / f_der_x;

    if (fabs(new_x - x) < eps1) {
      res.res = new_x;
      res.iter = i + 1;
      return res;
    }
    x = new_x;
  }

  res.iter = MAX_ITER;
  // No root found
  return res;
}
