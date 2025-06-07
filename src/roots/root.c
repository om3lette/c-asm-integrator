#include "roots.h"

#define METHOD_BISECTION 1
#define METHOD_SECANT 2
#define METHOD_NEWTON 3
#define METHOD_COMBINED 4

struct res_iter_pair root(
    afunc *f, afunc *g, __attribute__((unused)) afunc *f_d, __attribute__((unused)) afunc *g_d,
    double a, double b, double eps1
) {
#if ROOT_METHOD == METHOD_NEWTON
  return newton_root(f, g, f_d, g_d, a, b, eps1);
#elif ROOT_METHOD == METHOD_SECANT
  return secant_root(f, g, f_d, g_d, a, b, eps1);
#elif ROOT_METHOD == METHOD_BISECTION
  return bisection_root(f, g, a, b, eps1);
#elif ROOT_METHOD == METHOD_COMBINED
  return combined_root(f, g, f_d, g_d, a, b, eps1);
#else
#error "Unknown ROOT_METHOD"
#endif
}
