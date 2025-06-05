#include <stdio.h>
#include <stdlib.h>

#include "types.h"

struct integral_args parse_integral_args(char *input) {
  /*
    Input example: 1:3.0:5.0:0.0001:8.0
    func_idx = 1
    a = 3.0, b = 5.0, e = 0.0001
    ans = 8.0

    |  Token name  | idx |
    ----------------------
    |  func_idx  |  0  |
    |       a      |  2  |
    |       b      |  3  |
    |      eps     |  4  |
    |     answer   |  5  |
    ----------------------
  */
  struct integral_args result;
  if (sscanf(
          input, "%d:%lf:%lf:%lf:%lf", &result.func_idx, &result.a, &result.b, &result.eps,
          &result.answer
      ) != 5) {
    fprintf(stderr, "[ERROR]: Invalid format for integral args.\n");
    exit(1);
  }
  return result;
}
