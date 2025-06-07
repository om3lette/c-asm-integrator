#ifndef UTILS_H
#define UTILS_H

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

afunc *get_function_by_index(int idx);

afunc *get_function_der_by_index(int idx);

struct errors get_calculation_errors(double answer, double expected_answer);

int get_der_mult_sign(afunc f, afunc g, afunc f_d, afunc g_d, double a,
                      double b);

double func_sub(afunc *f, afunc *g, double x);

int get_sign(double x);
#endif
