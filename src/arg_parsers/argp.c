#include <argp.h>
#include <stdlib.h>

#include "parsers.h"

char doc[] = "Command line tool for integrating and finding roots";
char args_doc[] = "";

static struct argp_option options[] = {
    {"help", 'h', 0, 0, "Display this information", 0},
    {"test-root", 'R', "F1:F2:A:B:E:R", 0, "Root args", 0},
    {"test-integral", 'I', "F:A:B:E:R", 0, "Integral args", 0},
    {"root", 'r', 0, 0, "Show calculated root", 0},
    {"iterations", 'i', 0, 0, "Show iteration count", 0},
    {0}
};

struct argp argp = {options, parse_opt, args_doc, doc, NULL, 0, 0};

void free_args(const struct arguments *args) {
  free(args->integral_data);
  free(args->root_data);
}
