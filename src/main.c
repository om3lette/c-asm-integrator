#include <argp.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "integrals.h"
#include "parsers.h"
#include "roots.h"
#include "utils.h"

int main(int argc, char *argv[]) {

  struct arguments args = {false, NULL, NULL, false, false};
  argp_parse(&argp, argc, argv, 0, 0, &args);

  if (args.help) {
    argp_help(&argp, stdout, ARGP_HELP_LONG | ARGP_HELP_DOC, argv[0]);
    free_args(&args);
    return 0;
  }

  if (args.integral_data && args.root_data) {
    fprintf(
        stderr, "[ERROR]: --test-integral and --test-root cannot be specified at the same time\n"
    );
    free_args(&args);
    return 1;
  }

  if (args.integral_data) {
    struct integral_args i_args = *args.integral_data;
    struct res_iter_pair answer =
        integral(get_function_by_index(i_args.func_idx), i_args.a, i_args.b, i_args.eps);
    struct errors errs = get_calculation_errors(answer.res, i_args.answer);
    printf("%lf %lf %lf\n", answer.res, errs.absolute, errs.relative);

    if (args.iterations) {
      printf("Iterations (Runge): %d\n", answer.iter);
    }
    free_args(&args);
    return 0;
  }

  if (args.root_data) {
    struct root_args r_args = *args.root_data;
    struct res_iter_pair answer = root(
        get_function_by_index(r_args.func_1_idx), get_function_by_index(r_args.func_2_idx),
        get_function_der_by_index(r_args.func_1_idx), get_function_der_by_index(r_args.func_2_idx),
        r_args.a, r_args.b, r_args.eps
    );

    struct errors errs = get_calculation_errors(answer.res, r_args.answer);
    printf("%lf %lf %lf\n", answer.res, errs.absolute, errs.relative);

    if (args.root && !isnan(answer.res)) {
      printf("Root: %lf\n", answer.res);
    } else if (args.root && isnan(answer.res)) {
      printf("Root: Not found.\n");
    }
    if (args.iterations) {
      printf("Iterations: %d\n", answer.iter);
    }
    free_args(&args);
    return 0;
  }

  struct res_iter_pair root_1_2 = root(f, g, f_d, g_d, 0.0L, 2.0L, 1e-6);
  struct res_iter_pair root_2_3 = root(g, h, g_d, h_d, -2.0L, -0.1L, 1e-6);
  struct res_iter_pair root_1_3 = root(f, h, f_d, h_d, -4.0L, -2.0L, 1e-6);

  struct res_iter_pair i_1 = integral(f, root_1_3.res, root_1_2.res, 1e-6);
  struct res_iter_pair i_2 = integral(g, root_2_3.res, root_1_2.res, 1e-6);
  struct res_iter_pair i_3 = integral(h, root_1_3.res, root_2_3.res, 1e-6);

  double answer = i_2.res + i_3.res - i_1.res;
  static const double EXPECTED_ANSWER = 9.8069449336;

  struct errors errs = get_calculation_errors(answer, EXPECTED_ANSWER);
  printf("%lf %lf %lf\n", answer, errs.absolute, errs.relative);

  if (args.root) {
    printf(
        "========================== Roots ===========================\n"
        "Root 1-2: %lf\nRoot 2-3: %lf\nRoot 1-3: %lf\n",
        root_1_2.res, root_2_3.res, root_1_3.res
    );
  }
  if (args.iterations) {
    printf(
        "===================== Iterations roots =====================\n"
        "Iterations 1-2: %d\nIterations 2-3: %d\nIterations 1-3: %d\n",
        root_1_2.iter, root_2_3.iter, root_1_3.iter
    );
  }

  if (args.iterations) {
    printf(
        "=============== Iterations integrals (Runge) ===============\n"
        "Iterations 1-2: %d\nIterations 2-3: %d\nIterations 1-3: %d\n",
        i_1.iter, i_2.iter, i_2.iter
    );
  }
  free_args(&args);
  return 0;
}
