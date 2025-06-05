#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "integrals.h"
#include "types.h"

// I_n = eps(0.5F_0 + F_1 + ... + F_{n - 1} + F_n),
// F_i = F(a + ih)
// eps = (b - a) / n => n = (b - a) / eps

struct res_iter_pair trapezoid(double (*func)(double x), double a, double b, double eps) {
  uint64_t n = START_FRAGMENTS_NUMBER;
  double start_point = 0.5 * (func(a) + func(b));

  double integral = start_point;
  double h = (b - a) / n;

  for (uint32_t i = 1; i < n; i++) {
    integral += func(a + i * h);
  }
  integral *= h; // eps * (...)

  // Apply Runge
  uint32_t i = 0;
  double prev_integral;
  do {
    n *= 2;
    h /= 2;
    prev_integral = integral;
    integral = start_point;

    for (uint32_t i = 1; i < n; i++) {
      integral += func(a + i * h);
    }
    integral *= h;
    i++;
  } while (i < MAX_RUNGE_ITERATIONS && fabs(prev_integral - integral) / 3 >= eps);
  double final_precision = fabs(prev_integral - integral) / 3;
  if (final_precision >= eps)
    fprintf(
        stderr,
        "[WARNING]: Failed to reach desired precision: %lf. Final result: %lf. "
        "Consider increasing iterations limit\n",
        eps, final_precision
    );

  struct res_iter_pair res = {integral, i + 1};
  return res;
}
