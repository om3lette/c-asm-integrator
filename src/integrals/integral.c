#include "integrals.h"
#include "types.h"

struct res_iter_pair integral(double (*F)(double x), double a, double b, double eps2) {
  return trapezoid(F, a, b, eps2);
}
