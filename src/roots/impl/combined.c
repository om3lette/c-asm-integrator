#include "roots.h"
#include "utils.h"
#include <math.h>
#include <stdint.h>

struct res_iter_pair
combined_root(afunc *f, afunc *g, afunc *f_d, afunc *g_d, double a, double b, double eps) {
  struct res_iter_pair res = {NAN, 0};

  for (uint32_t i = 1; i <= MAX_ITER; ++i) {
    double H_A = func_sub(f, g, a);
    double H_B = func_sub(f, g, b);
    double H1_A = func_sub(f_d, g_d, a);
    double H1_B = func_sub(f_d, g_d, b);

    if (get_der_mult_sign(f, g, f_d, g_d, a, b)) {
      a = (a * H_B - b * H_A) / (H_B - H_A);
      b = b - H_B / H1_B;
    } else {
      a = a - H_A / H1_A;
      b = (a * H_B - b * H_A) / (H_B - H_A);
    }

    // Условие выхода: длина отрезка < eps
    if (fabs(b - a) < eps) {
      res.res = 0.5 * (a + b);
      res.iter = i;
      return res;
    }
  }

  // если за MAX_ITER не сошлось — вернём середину последнего отрезка
  res.res = 0.5 * (a + b);
  res.iter = MAX_ITER;
  return res;
}
