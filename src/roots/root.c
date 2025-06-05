#include "roots.h"

struct res_iter_pair
root(afunc *f, afunc *g, afunc *f_d, afunc *g_d, double a, double b, double eps1) {
  return newton_root(f, g, f_d, g_d, a, b, eps1);
}
