#ifndef INTEGRALS_H
#define INTEGRALS_H

#include "types.h"
#include <stdint.h>

static const uint32_t START_FRAGMENTS_NUMBER = 10;
static const uint32_t MAX_RUNGE_ITERATIONS = 25;

struct res_iter_pair integral(afunc *F, double a, double b, double eps2);

struct res_iter_pair trapezoid(afunc *func, double a, double b, double eps);

#endif
