#ifndef PARSERS_H
#define PARSERS_H

#include <argp.h>
#include <stdbool.h>

#include "types.h"

struct root_args parse_root_args(char *input);
struct integral_args parse_integral_args(char *input);

error_t parse_opt(int key, char *arg, struct argp_state *state);
void free_args(const struct arguments *args);

extern struct argp argp;
#endif
