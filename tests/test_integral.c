#include <CUnit/CUnit.h>

#include "functions.h"
#include "integrals.h"

int init_suite_integral(void) { return 0; }
int clean_suite_integral(void) { return 0; }

void test_integral_1(void) {
  // https://www.wolframalpha.com/input?i2d=true&i=Integrate%5BPower%5Be%2Cx%5D%2B2%2C%7Bx%2C1%2C2%7D%5D
  double area = 6.67077427;
  CU_ASSERT_DOUBLE_EQUAL(integral(f, 1, 2, 1e-3).res, area, 1e-3);
  CU_ASSERT_DOUBLE_EQUAL(integral(f, 1, 2, 1e-8).res, area, 1e-8);

  // https://www.wolframalpha.com/input?i2d=true&i=Integrate%5BPower%5Be%2Cx%5D%2B2%2C%7Bx%2C-100%2C20%7D%5D
  area = 485165435.40979027;
  CU_ASSERT_DOUBLE_EQUAL(integral(f, -100, 20, 1e-1).res, area, 1e-1);
}

void test_integral_2(void) {
  // https://www.wolframalpha.com/input?i2d=true&i=Integrate%5B-2x%2B8%2C%7Bx%2C1%2C2%7D%5D
  double area = 5.0;
  CU_ASSERT_DOUBLE_EQUAL(integral(g, 1, 2, 1e-3).res, area, 1e-3);
  CU_ASSERT_DOUBLE_EQUAL(integral(g, 1, 2, 1e-8).res, area, 1e-8);

  // https://www.wolframalpha.com/input?i2d=true&i=Integrate%5B-2x%2B8%2C%7Bx%2C-100%2C20%7D%5D
  area = 10560.0;
  CU_ASSERT_DOUBLE_EQUAL(integral(g, -100, 20, 1e-1).res, area, 1e-1);
}

void test_integral_3(void) {
  // https://www.wolframalpha.com/input?i2d=true&i=Integrate%5B-Divide%5B5%2Cx%5D%2C%7Bx%2C1%2C2%7D%5D
  double area = -3.46573590;
  CU_ASSERT_DOUBLE_EQUAL(integral(h, 1, 2, 1e-3).res, area, 1e-3);
  CU_ASSERT_DOUBLE_EQUAL(integral(h, 1, 2, 1e-8).res, area, 1e-8);

  // https://www.wolframalpha.com/input?i2d=true&i=Integrate%5B-Divide%5B5%2Cx%5D%2C%7Bx%2C-100%2C20%7D%5D
  area = 8.95879734;
  CU_ASSERT_DOUBLE_EQUAL(integral(h, -120, -20, 1e-1).res, area, 1e-1);
}

int add_integral_suite(void) {
  CU_pSuite suite = CU_add_suite("integral_suite", init_suite_integral, clean_suite_integral);
  if (!suite)
    return 1;

  if (!CU_add_test(suite, "Integrating e^x + 2", test_integral_1))
    return 1;
  if (!CU_add_test(suite, "Integrating -2x + 8", test_integral_2))
    return 1;
  if (!CU_add_test(suite, "Integrating -5 / x", test_integral_3))
    return 1;

  return 0;
}
