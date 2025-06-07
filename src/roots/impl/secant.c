#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>

#include "roots.h"
#include "utils.h"

struct res_iter_pair
secant_root(afunc *f, afunc *g, afunc *f_d, afunc *g_d, double a, double b, double eps1) {
  struct res_iter_pair res = {NAN, -1};

  for (uint32_t i = 0; i < MAX_ITER; i++) {
    double f_left = func_sub(f, g, a);
    double f_right = func_sub(f, g, b);
    double c = (a * f_right - b * f_left) / (f_right - f_left);

    int der_mult_sign = get_der_mult_sign(f, g, f_d, g_d, a, b);
    if (der_mult_sign > 0) {
      a = c;
    } else {
      b = c;
    }

    int sign_1 = func_sub(f, g, c) > 0 ? 1 : -1;
    int sign_2 = func_sub(f, g, c + eps1 * der_mult_sign) > 0 ? 1 : -1;

    if (sign_1 != sign_2) {
      res.res = c + eps1 * der_mult_sign / 2;
      res.iter = i;
      return res;
    };
  }

  res.iter = MAX_ITER;
  // No root found
  return res;
}
