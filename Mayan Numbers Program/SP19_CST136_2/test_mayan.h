#pragma once
#include "mayan.h"

// What testing do I want to do now.  1 = on, 0 = off

#define MAYAN_TEST  1          // the top check.  Does not print anything if this is off.
#define VERBOSE  1             // adds of extra printouts.  If you have any fails, then turn this back on.

#define TEST_IS_VALID 1         // tests the is_valid method

#define TEST_INTEGER_TO_MAYAN 1  // tests converting an Integer to a Mayan number
#define TEST_MAYAN_TO_INTEGER 1 // tests converting a Mayan number to an Integer

#define TEST_ENTRY  0         // test user entry of a mayan number  Needs << and >> to work

//  At this point integer to mayan and mayan to integer routines must be working. 
#define TEST_ADD 1             //  test addition.  Uses conversion routines to test.
#define TEST_SUBTRACT  1       //  test subtraction
#define TEST_PLUS_EQ   1      //   test +=  TEST_ADD must also be on
#define TEST_MINUS_EQ  1       //   test -=  TEST_SUBTRACT must also be on
#define TEST_COMPARISON 1     // Note:  this tests all the comparison operators at once  ==, != and > 

#define TEST_OVER_UNDER 1           // Makes sure you are properly handling overflow and aren't doing negative numbers.

//  Don't change anything below this line.

//  These are two parallel arrays that have the decimal and the Mayan text values.
const int test_integer_values[6] = { MAX_INTEGER,745,   152414, 84653, 8864,19 };
const char test_mayan_values[6][5] = { "jjjj",     "01h5","j10e","abcd","1234","000J" };
// Here are all the function protypes in test_mayan.cpp
bool get_print_all();
void print_rules(); // prints rules about what a mayan number should look like.  Used by test_entry
void print_skipped(const std::string & test_name = "");
void print_pass_fail(bool passed);
void tester_print(int dec, const char t[], bool passed);
bool all_zeros(const char temp[]);

void test_is_valid();
void test_equal(const Mayan & test_mayan, const int & int_result);
void test_a_plus_equals(int lhs_int, int rhs_int);
void test_plus_equals();
void test_a_minus_equals(int lhs_int, int rhs_int);
void test_minus_equals();
void test_add_two(int lhs_int, int rhs_int);
void test_subtract_two(int lhs_int, int rhs_int);
void test_user_entry();
void test_subtract();
void test_add();
void test_compare_two(int lhs_int, int rhs_int);
void test_comparisons();
void test_single_MayanToInteger(int correct_d, const char source[]);
void test_single_IntegerToMayan(int d, const char CorrectValue[]);
void test_from_integer();
void test_to_integer();
void single_test(int lhs_int, int rhs_int);
void test_integer_to_Mayan();
void test_mayan_to_integer();
void test_over_under();
void test_mayan();