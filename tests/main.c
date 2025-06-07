#include "tests.h"
#include <CUnit/Basic.h>

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main() {
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  int return_code = add_root_suite() || add_integral_suite();
  if (return_code)
    return CU_get_error();

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
