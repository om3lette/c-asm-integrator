#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>

#include "roots.h"
#include "utils.h"

static double get_starting_point(afunc *f, afunc *g, afunc *f_d, afunc *g_d, double a, double b) {
  return get_der_mult_sign(f, g, f_d, g_d, a, b) ? b : a;
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
  double x = get_starting_point(f, g, f_d, g_d, a, b);

  struct res_iter_pair res = {NAN, -1};

  for (uint32_t i = 0; i < MAX_ITER; ++i) {
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
