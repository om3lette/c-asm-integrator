#include "functions.h"
#include "roots.h"
#include <CUnit/CUnit.h>

int init_suite_root(void) { return 0; }
int clean_suite_root(void) { return 0; }

void test_root_1_2(void) {
  // e^x + 2 = -2x + 8 => 1.25176
  double intersection_point = 1.25176;
  double l = 1.0L;
  double r = 5.0L;
  // With 1e-5 precision
  CU_ASSERT_DOUBLE_EQUAL(root(f, g, f_d, g_d, l, r, 1e-5).res, intersection_point, 1e-5);
  // With 1e-4 precision
  CU_ASSERT_DOUBLE_EQUAL(root(f, g, f_d, g_d, l, r, 1e-4).res, intersection_point, 1e-4);
  // With 1 precision which is too little
  CU_ASSERT_DOUBLE_NOT_EQUAL(root(f, g, f_d, g_d, l, r, 1).res, intersection_point, 1e-5);

  // Huge numbers far away from the answer -> root not found
  CU_ASSERT_TRUE(isnan(root(f, g, f_d, g_d, 1e+50, 1e+60, 1e-6).res));
  CU_ASSERT_TRUE(isnan(root(f, g, f_d, g_d, -1e+50, -1e+60, 1e-6).res));
}

void test_root_1_3(void) {
  // e^x + 2 = -5/x => -2.39054
  double intersection_point = -2.39054;
  double l = -4.0L;
  double r = 2.0L;
  // With 1e-5 precision
  CU_ASSERT_DOUBLE_EQUAL(root(f, h, f_d, h_d, l, r, 1e-5).res, intersection_point, 1e-5);
  // With 1e-4 precision
  CU_ASSERT_DOUBLE_EQUAL(root(f, h, f_d, h_d, l, r, 1e-4).res, intersection_point, 1e-4);
  // With 1 precision which is too little
  CU_ASSERT_DOUBLE_NOT_EQUAL(root(f, h, f_d, h_d, l, r, 1).res, intersection_point, 1e-5);

  // Huge numbers far away from the answer -> root not found
  CU_ASSERT_TRUE(isnan(root(f, h, f_d, h_d, 1e+50, 1e+60, 1e-6).res));
  CU_ASSERT_TRUE(isnan(root(f, h, f_d, h_d, -1e+50, -1e+60, 1e-6).res));
}

void test_root_2_3(void) {
  // -2x + 8 = -5/x => 4.54951
  double intersection_point = 4.54951;
  double l = 2.0L;
  double r = 6.0L;
  // With 1e-5 precision
  CU_ASSERT_DOUBLE_EQUAL(root(g, h, g_d, h_d, l, r, 1e-5).res, intersection_point, 1e-5);
  // With 1e-4 precision
  CU_ASSERT_DOUBLE_EQUAL(root(g, h, g_d, h_d, l, r, 1e-4).res, intersection_point, 1e-4);
  // With 1 precision which is too little
  CU_ASSERT_DOUBLE_NOT_EQUAL(root(g, h, g_d, h_d, l, r, 1).res, intersection_point, 1e-5);

  // Huge numbers far away from the answer -> root not found
  CU_ASSERT_TRUE(isnan(root(g, h, g_d, h_d, 1e+50, 1e+60, 1e-6).res));
  CU_ASSERT_TRUE(isnan(root(g, h, g_d, h_d, -1e+50, -1e+60, 1e-6).res));
}

int add_root_suite(void) {
  CU_pSuite suite = CU_add_suite("root_suite", init_suite_root, clean_suite_root);
  if (!suite)
    return 1;

  if (!CU_add_test(suite, "Root e^x + 2 = -2x + 8", test_root_1_2))
    return 1;
  if (!CU_add_test(suite, "Root e^x + 2 = -5 / x", test_root_1_3))
    return 1;
  if (!CU_add_test(suite, "Root -2x + 8 = -5 / x", test_root_2_3))
    return 1;

  return 0;
}
