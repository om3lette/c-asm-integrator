#include <stdio.h>
#include <stdlib.h>

#include "types.h"

struct root_args parse_root_args(char *input) {
  /*
  Input example: 1:2:3.0:5.0:0.0001:4.0
  func_1_idx = 1, func_2_idx = 2
  a = 3.0, b = 5.0, e = 0.0001
  r = 4.0

  |  Token name  | idx |
  ----------------------
  |  func_1_idx  |  0  |
  |  func_2_idx  |  1  |
  |       a      |  2  |
  |       b      |  3  |
  |      eps     |  4  |
  |     answer   |  5  |
  ----------------------
  */
  struct root_args result;
  if (sscanf(
          input, "%d:%d:%lf:%lf:%lf:%lf", &result.func_1_idx, &result.func_2_idx, &result.a,
          &result.b, &result.eps, &result.answer
      ) != 6) {
    fprintf(stderr, "[ERROR]: Invalid format for root args.\n");
    exit(1);
  }
  return result;
}
