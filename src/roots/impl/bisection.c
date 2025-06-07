#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>

#include "roots.h"
#include "types.h"
#include "utils.h"

struct res_iter_pair bisection_root(afunc *f, afunc *g, double a, double b, double eps1) {
  for (uint32_t i = 0; i < MAX_ITER; ++i) {
    double c = (a + b) / 2;
    int c_sign = get_sign(func_sub(f, g, c));

    if (get_sign(func_sub(f, g, a)) != c_sign) {
      b = c;
    } else if (get_sign(func_sub(f, g, b)) != c_sign) {
      a = c;
    } else {
      // Signs are the same. Unable to continue
      break;
    }

    if (fabs(b - a) < eps1)
      return (struct res_iter_pair){a + 0.5 * (b - a), -1};
  }

  return (struct res_iter_pair){NAN, -1};
}
