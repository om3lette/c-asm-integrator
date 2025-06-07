#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include <stdint.h>

typedef double afunc(double);
typedef double funccomp(afunc, afunc, double); // Function composition

struct errors {
  double absolute;
  double relative;
};

struct res_iter_pair {
  double res;
  uint32_t iter;
};

struct integral_args {
  double a;
  double b;
  double eps;
  double answer;
  int func_idx;
};

struct arguments {
  struct root_args *root_data;
  struct integral_args *integral_data;
  bool help;
  bool root;
  bool iterations;
};

struct root_args {
  double a;
  double b;
  double eps;
  double answer;
  int func_1_idx;
  int func_2_idx;
};

#endif
