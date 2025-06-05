#include <argp.h>
#include <stdbool.h>
#include <stdlib.h>

#include "parsers.h"

error_t parse_opt(int key, char *arg, struct argp_state *state) {
  struct arguments *args = state->input;

  switch (key) {
  case 'h':
    args->help = true;
    break;
  case 'I':
    args->integral_data = malloc(sizeof(struct integral_args));
    *args->integral_data = parse_integral_args(arg);
    break;
  case 'R':
    args->root_data = malloc(sizeof(struct root_args));
    *args->root_data = parse_root_args(arg);
    break;
  case 'r':
    args->root = true;
    break;
  case 'i':
    args->iterations = true;
    break;
  case ARGP_KEY_ARG:
    argp_usage(state);
    break;
  default:
    return ARGP_ERR_UNKNOWN;
  }
  return 0;
}
