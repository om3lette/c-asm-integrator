#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"

double f(double x);
double g(double x);
double h(double x);

double derivative(afunc *func, double x, double eps);
int get_second_der_sign(afunc *f, double a, double b);

double f_d(double x);
double g_d(double x);
double h_d(double x);
#endif
