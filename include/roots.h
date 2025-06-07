#ifndef ROOTS_H
#define ROOTS_H

#include <stdint.h>

#include "types.h"

struct res_iter_pair root(afunc *f, afunc *g, afunc *f_d, afunc *g_d, double a,
                          double b, double eps1);

struct res_iter_pair newton_root(afunc *f, afunc *g, afunc *f_d, afunc *g_d,
                                 double a, double b, double eps1);

#endif
