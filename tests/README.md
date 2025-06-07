## How to add more tests

1. Create a new file `tests/test_*.c` and paste the following template
2. Add an entry to `include/tests.h`
3. Call a new function in `tests/main.c` to retrieve `return_code`

## The template

```c
#include "functions.h"
#include "roots.h"
#include "integrals.h"
#include <CUnit/CUnit.h>

int init_suite_x(void) { return 0; }
int clean_suite_x(void) { return 0; }

void test_x(void) {}

int add_x_suite(void) {
  CU_pSuite suite = CU_add_suite("x_suite", init_suite_x, clean_suite_x);
  if (!suite)
    return 1;

  if (!CU_add_test(suite, "X test", test_x))
    return 1;

  return 0;
}
```
