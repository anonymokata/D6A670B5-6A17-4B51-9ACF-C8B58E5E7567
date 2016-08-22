#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <check.h>
#include "roman.h"

/* CASE: simple-addition */
START_TEST(add_I_plus_I)
{
    const char* result = roman_add("I","I");
    
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("II", result);
    
    free((void*)result);
}
END_TEST

START_TEST(add_I_up_to_III)
{
    const char* result;
    
    result = roman_add("I","II");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("III", result);
    free((void*)result);
    
    result = roman_add("II","I");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("III", result);
    free((void*)result);
}
END_TEST

START_TEST(IIII_output_looks_like_IV)
{
    const char* result;
    
    result = roman_add("I","III");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("IV", result);
    free((void*)result);
    
    result = roman_add("III","I");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("IV", result);
    free((void*)result);
    
    result = roman_add("II","II");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("IV", result);
    free((void*)result);
}
END_TEST

START_TEST(IIIII_output_looks_like_V)
{
    const char* result;
    
    result = roman_add("I","IIII");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("V", result);
    free((void*)result);
    
    result = roman_add("IIII","I");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("V", result);
    free((void*)result);
    
    result = roman_add("II","III");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("V", result);
    free((void*)result);
}
END_TEST

START_TEST(IIIIII_output_looks_like_VI)
{
    const char* result;
    
    result = roman_add("III","III");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("VI", result);
    free((void*)result);
}
END_TEST

START_TEST(IV_input_means_IIII)
{
    const char* result;
    
    result = roman_add("IV","I");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("V", result);
    free((void*)result);
    
    result = roman_add("II","IV");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("VI", result);
    free((void*)result);
}
END_TEST

START_TEST(V_input_means_IIIII)
{
    const char* result;
    
    result = roman_add("V","I");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("VI", result);
    free((void*)result);
    
    result = roman_add("I","V");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("VI", result);
    free((void*)result);
}
END_TEST

START_TEST(add_through_VIII)
{
    const char* result;
    
    result = roman_add("III","IV");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("VII", result);
    free((void*)result);
    
    result = roman_add("III","V");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("VIII", result);
    free((void*)result);
    
    result = roman_add("IV","IV");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("VIII", result);
    free((void*)result);
}
END_TEST

START_TEST(VIIII_output_looks_like_IX)
{
    const char* result;
    
    result = roman_add("V","IV");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("IX", result);
    free((void*)result);
    
    result = roman_add("IV","V");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("IX", result);
    free((void*)result);
    
    result = roman_add("I","VIII");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("IX", result);
    free((void*)result);
}
END_TEST

START_TEST(allow_X_as_an_input)
{
    const char* result;
    
    result = roman_add("X","I");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("XI", result);
    free((void*)result);
    
    result = roman_add("XI","XVI");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("XXVII", result);
    free((void*)result);
    
    result = roman_add("XI","VIII");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("XIX", result);
    free((void*)result);
}
END_TEST

START_TEST(add_to_X)
{
    const char* result;
    
    result = roman_add("V","V");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("X", result);
    free((void*)result);
    
    result = roman_add("I","VIIII");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("X", result);
    free((void*)result);
    
    result = roman_add("VI","IV");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("X", result);
    free((void*)result);
}
END_TEST

START_TEST(add_to_L)
{
    const char* result;
    
    result = roman_add("XXXX","X");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("L", result);
    free((void*)result);
    
    result = roman_add("XXV","XXV");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("L", result);
    free((void*)result);
    
    result = roman_add("X","XXXX");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("L", result);
    free((void*)result);
}
END_TEST

START_TEST(add_to_XL)
{
    const char* result;
    
    result = roman_add("XXX","X");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("XL", result);
    free((void*)result);
    
    result = roman_add("XX","XX");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("XL", result);
    free((void*)result);
    
    result = roman_add("V","XXXV");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("XL", result);
    free((void*)result);
}
END_TEST

START_TEST(allow_L_as_input)
{
    const char* result;
    
    result = roman_add("L","X");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("LX", result);
    free((void*)result);
    
    result = roman_add("VII","L");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("LVII", result);
    free((void*)result);
    
    result = roman_add("LII","III");
    ck_assert_ptr_ne(0, result);
    ck_assert_str_eq("LV", result);
    free((void*)result);
}
END_TEST


/* CASE: handle errors */
START_TEST(null_inputs_should_return_null)
{
    const char* result;
    
    result = roman_add(0,"I");
    ck_assert_ptr_eq(0, result);
    
    result = roman_add("I", 0);
    ck_assert_ptr_eq(0, result);
    
    result = roman_add(0,0);
    ck_assert_ptr_eq(0, result);
}
END_TEST

START_TEST(empty_inputs_should_return_null)
{
    const char* result;
    
    result = roman_add("", "I");
    ck_assert_ptr_eq(0, result);
    
    result = roman_add("I", "");
    ck_assert_ptr_eq(0, result);
    
    result = roman_add("", "");
    ck_assert_ptr_eq(0, result);
}
END_TEST

/* Set up the tests, cases, and suite to be run for this unit */
Suite* roman_suite(void)
{
    Suite* s;
    TCase* c;
    s = suite_create("roman");
    
    c = tcase_create("addition");
    tcase_add_test(c, add_I_plus_I);
    tcase_add_test(c, add_I_up_to_III);
    tcase_add_test(c, IIII_output_looks_like_IV);
    tcase_add_test(c, IIIII_output_looks_like_V);
    tcase_add_test(c, IIIIII_output_looks_like_VI);
    tcase_add_test(c, IV_input_means_IIII);
    tcase_add_test(c, V_input_means_IIIII);
    tcase_add_test(c, add_through_VIII);
    tcase_add_test(c, VIIII_output_looks_like_IX);
    tcase_add_test(c, add_to_X);
    tcase_add_test(c, allow_X_as_an_input);
    tcase_add_test(c, add_to_L);
    tcase_add_test(c, add_to_XL);
    suite_add_tcase(s, c);
    
    c = tcase_create("errors");
    tcase_add_test(c, null_inputs_should_return_null);
    tcase_add_test(c, empty_inputs_should_return_null);
    suite_add_tcase(s, c);
    
    return s;
}

/* Our main function runner takes no arguments and it always runs all tests */
int main(void) 
{
    int failures;
    Suite* s;
    SRunner* r;
    
    s = roman_suite();
    r = srunner_create(s);
    
    srunner_run_all(r, CK_NORMAL);
    failures = srunner_ntests_failed(r);
    srunner_free(r);
    
    return failures;
}