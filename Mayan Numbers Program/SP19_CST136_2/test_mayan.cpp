// Do NOT change this file.
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

#include "test_mayan.h"
#include "mayan.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

bool get_print_all()
{
	bool print_all = false;
#if VERBOSE
	print_all = true;
#endif
	return print_all;
}
void print_rules()
{
	// Note how I'm doing the " in the last two lines.
	//   Its a raw string and you can have embedded quotes in it.
	cout << "=== Mayan Numbers must be between ";
	cout << "0-9 or a-j, ";
	cout << "4 characters long and";
	cout << " padded with 0\'s" << endl;
	cout << R"( For example "0bed" or "jade")";
	cout << R"( or "0009" or "0123")" << endl;
}

// note that in the prototype there is a default test_name.
void print_skipped(const std::string & test_name)
{
	cout << " ++ SKIPPED " << test_name << endl << endl;
}

// created so everything lines up nice.
void print_pass_fail(bool passed)
{
	if (get_print_all() && passed)
		cout << " (PASSED) " << endl;
	else if (!passed)
		cout << " **** FAILED *************  " << endl;  // trying to make this really stand out.  :)
}

void tester_print(int dec, const char t[], bool passed)
{
	if (get_print_all() || !passed)
		cout << "  " << std::setw(8) << dec << " -> " << t << " in Mayan. ";
	print_pass_fail(passed);
}

//  I decided to do this with characters so that you could use 
//    test_is_valid even if == wasn't available.
bool all_zeros(const char temp[])
{
	return (strcmp(temp,"0000")==0);

}
void test_is_valid()
{
	cout << "Testing is_valid()" << endl;
	const bool k_print_all = get_print_all();

#if ! TEST_IS_VALID
	print_skipped("is_valid");
#else
	char bad_values[6][MAYAN_SIZE] = { "0","W000","0X00","00L0","000Z" };
	bool passed_test = true;

	for (int i = 0;  i < 5 ; i++) {
		Mayan m1(bad_values[i]);
		passed_test = !is_valid(bad_values[i]) && all_zeros(m1.get_mayan());
		if (k_print_all || !passed_test) {
			cout << "\tTesting " << bad_values[i] << " is NOT valid [" << is_valid(bad_values[i]) << "] ";
			cout << "and was properly zeroed (" << m1.get_mayan() << ") ";
		}

		print_pass_fail(passed_test);
	}

	for (int i = 0; i < 5 ; i++) {
		Mayan m1(test_mayan_values[i]);
		passed_test = is_valid(m1.get_mayan());
		if (k_print_all || !passed_test)
			cout << "\tTesting " << m1.get_mayan() << " IS valid [" << is_valid(m1.get_mayan()) << "] ";
		print_pass_fail(passed_test);
	}
	cout << "++Finished++" << endl << endl;
#endif
}

void test_equal(const Mayan & test_mayan, const int & int_result)
{
	bool good = true;

	if (!is_valid(test_mayan.get_mayan()))
		good = false;
	else
		if ((MayanToInteger(test_mayan.get_mayan())) != int_result)
			good = false;

	tester_print(int_result, test_mayan.get_mayan(), good);
}

void test_a_plus_equals(int lhs_int, int rhs_int)
{

#if TEST_PLUS_EQ 

	const int k_result_integer = lhs_int + rhs_int;
	const Mayan k_lhs(lhs_int);
	const Mayan k_rhs(rhs_int);
	
	Mayan result = k_lhs;
	result += k_rhs;

	if (get_print_all()) {
		cout << "\t" << k_lhs << " (" << lhs_int << ")";
		cout << " + " << k_rhs << " (" << rhs_int << ") = ";
	}
	test_equal(result, k_result_integer);
	
#endif
}
void test_plus_equals()
{
	cout << "Testing Plus Eq (+=)" << endl;

#if ! TEST_PLUS_EQ 
	print_skipped("Testing Plus Eq");
#else

	for (int i = 10285; i < 10290; i++) {
		test_a_plus_equals(i, test_integer_values[5]);
	}
	cout << "++Finished++" << endl << endl;
#endif
}
void test_a_minus_equals(int lhs_int, int rhs_int)
{

#if TEST_MINUS_EQ 
	const Mayan k_lhs(lhs_int);
	const Mayan k_rhs(rhs_int);
	
	const int k_result_int = lhs_int - rhs_int;

	Mayan result = k_lhs;
	result -= k_rhs;

	if (get_print_all()) {
		cout << "\t" << k_lhs << " (" << lhs_int << ")";
		cout << " - " << k_rhs << " (" << rhs_int << ") = ";
	}

	test_equal(result, k_result_int);
#endif

}
void test_minus_equals()
{
	cout << "Testing Minus Eq (-=)" << endl;

#if ! TEST_PLUS_EQ 
	print_skipped("Testing Minus Eq");
#else

	for (int i = 10285; i < 10290; i++) {
		test_a_minus_equals(i, test_integer_values[5]);
	}
	cout << "++Finished++" << endl << endl;
#endif
}
//  requires that the << operator is operational
void test_add_two(int lhs_int, int rhs_int)
{
#if TEST_ADD
	const Mayan k_lhs(lhs_int);
	const Mayan k_rhs(rhs_int);

	const Mayan k_result = k_lhs + k_rhs;

	const int result_int = lhs_int + rhs_int;

	if (get_print_all()) {
		cout << "\t"  << k_lhs << " (" << lhs_int << ")";
	    cout << " + " << k_rhs << " (" << rhs_int<< ") = ";
	}
	test_equal(k_result, result_int);
#endif
}

void test_subtract_two(int lhs_int, int rhs_int)
{
#if TEST_SUBTRACT
	const Mayan k_rhs(rhs_int);
	const Mayan k_lhs(lhs_int);
	const Mayan k_result = k_lhs - k_rhs;

	const int k_result_int = lhs_int - rhs_int;

	if (get_print_all()) {
		cout <<"\t"   << k_lhs.get_mayan() << " (" << lhs_int << ") ";
		cout << " - " << k_rhs.get_mayan() << " (" << rhs_int << ") = " ;
	}
	test_equal(k_result, k_result_int);

#endif
}
// to use this routine you need to have overridden both the << and the >> operators.
void test_user_entry()
{
	cout << "Testing User Entry" << endl;
#if !TEST_ENTRY
	print_skipped("User Entry");
#else
	Mayan first;
	char cnt;

	do {
		cout << "Enter a Mayan number" << endl;
		cout << "First ";
		cin >> first;
		cout << "You entered: " << first;

		while (!is_valid(first.get_mayan())) {
			cout << " which is NOT valid. " << endl;
			print_rules();
			cout << "First ";
			cin >> first;
			cout << "You entered: " << first;
		}
		if (is_valid(first.get_mayan()))   // I know, this is a little overkill.
			cout << " which is valid. " << endl;

		cout << endl;
		cout << "Do you want to enter another number (y/n) ";
		cin >> cnt;

	} while (cnt == 'y' || cnt == 'Y');
#endif
}

// sometimes it is useful to loop through a bunch of records to see how it goes.
void test_subtract()
{
	cout << "Testing Subtract" << endl;
	
#if !TEST_SUBTRACT
	print_skipped("Subtract");
#else

	// do a couple of easy ones first.
	test_subtract_two(10, 5);
	test_subtract_two(99, 97);
	
	int rhs_int = rand() % MAX_INTEGER - 20;

	const int k_start = rand() % MAX_INTEGER - 20; // i don't want any negatives 
	const int k_end = k_start + 10;

	if (rhs_int > k_start)
		rhs_int = k_start - 5; // No negative numbers.

	for (int lhs_int = k_start; lhs_int < k_end; lhs_int++) {
		test_subtract_two(lhs_int, rhs_int);	
	}
	
	cout << "++Finished++" << endl << endl;
#endif
}
// sometimes it is useful to loop through a bunch of records to see how it goes.
void test_add()
{
	cout << "Testing Add" << endl;

#if ! TEST_ADD
	print_skipped("Add");
#else
	// test a couple of easy ones first.
	test_add_two(10, 5);
	test_add_two(99, 3);
	
	const int k_rhs_int = rand() % 2500;

	const int k_start = rand() % (4999 - k_rhs_int - 100); // I don't want any overflow .
	const int k_end = k_start + 10;

	for (int lhs_int = k_start; lhs_int < k_end; lhs_int++) {
		test_add_two(lhs_int,k_rhs_int);
	}

	cout << "++Finished++" << endl << endl;
#endif
}
void test_compare_two(int lhs_int, int rhs_int)
{
	const bool k_print_all = get_print_all();
#if TEST_COMPARISON
	const Mayan k_rhs(rhs_int);
	const Mayan k_lhs(lhs_int);

	bool passed_test = (k_lhs > k_rhs) == (lhs_int > rhs_int);

	if (k_print_all || !passed_test)
	{
		cout << "\tGreater Than (>): " << k_lhs << " (" << lhs_int << ") ";
		cout << " > " << k_rhs << " (" << rhs_int << ") " << "  = [" << (k_lhs > k_rhs) <<"]";
		print_pass_fail(passed_test);
	}
	passed_test = (k_lhs == k_rhs) == (lhs_int == rhs_int);

	if (k_print_all || !passed_test)
	{
		cout << "\tEquals (==):      " << k_lhs << " (" << lhs_int << ") ";
		cout << " == " << k_rhs << " (" << rhs_int << ") " << " = [" << (k_lhs == k_rhs) << "]";
		print_pass_fail(passed_test);
	}

	passed_test = (k_lhs != k_rhs) == (lhs_int != rhs_int);

	if (k_print_all || !passed_test)
	{
		cout << "\tNot Equals (!=):  " << k_lhs << " (" << lhs_int << ") ";
		cout << " != " << k_rhs << " (" << rhs_int << ") " << " = [" << (k_lhs != k_rhs) << "]";
		print_pass_fail(passed_test);
	}

#endif
}
void test_comparisons()
{
	cout << "Testing Comparisons" << endl;

#if ! TEST_COMPARISON
	print_skipped("Comparison");
#else
	test_compare_two( 10, 5);
	test_compare_two( 5, 10);
	test_compare_two(10, 10);
	for (int i = 0; i < 4; i++)
		test_compare_two(test_integer_values[i], test_integer_values[i + 1]);

	cout << "++Finished++" << endl << endl;
#endif
	
}

//  This function will run a single test for me comparing what you compute
//     in MayanToInteger to what it should be (passed in as correct_d)
void test_single_MayanToInteger(int correct_d, const char source[])
{

#if TEST_MAYAN_TO_INTEGER

	const int k_result = MayanToInteger(source);

	// notice how I'm checking whether or not the test passed.  
	//   result == correct_d goes into the parameter "passed"
	tester_print(k_result, source, k_result == correct_d);

#endif
}
//  This function will run a single test for me comparing what you compute
//     in ConvertFrom Decimal to what it should be (passed in as CorrectValue)
void test_single_IntegerToMayan(int d, const char CorrectValue[])
{
	bool passed = true;
#if TEST_INTEGER_TO_MAYAN
	char result[MAYAN_SIZE] = { "" };

	IntegerToMayan(result, d);
	passed = strcmp(result, CorrectValue) == 0;
	tester_print(d, result, passed);
#endif
}
//  This function runs through 0-19 to make sure it computes correctly.
void test_from_integer()
{
#if TEST_INTEGER_TO_MAYAN

	char tester[MAYAN_SIZE] = "0000";

	for (int i = 0; i < 20; i++) {
		if (i < 10)
			tester[3] = ASCII_ZERO + i;
		else
			tester[3] = ASCII_A + i - 10;

		test_single_IntegerToMayan(i, tester);
	}

	int tester_values[3] = { 128000,6400,320 };
	char valid_values[3][MAYAN_SIZE] = { "g000","0g00","00g0" };

	//   The goal of this test is to make sure you are properly calculating each position
	//    so you can see that I test 00g0, 0g00, g000		
	for (int i = 0; i < MAYAN_SIZE - 2; i++)
	{
		test_single_IntegerToMayan(tester_values[i], valid_values[i]);
	}
	cout << "++Finished++" << endl << endl;
#endif

}

void test_to_integer()
{

#if TEST_MAYAN_TO_INTEGER

	char blank_tester[MAYAN_SIZE] = "0000";

	char tester[MAYAN_SIZE] = "0000";

	//  test 0 - 19
	for (int i = 0; i < 20 ; i++) {

		if (i < 10)
			tester[3] = ASCII_ZERO + i;
		else
			tester[3] = ASCII_A + i - 10;

		test_single_MayanToInteger(i, tester);
	}

	//   The goal of this test is to make sure you are properly calculating each position
	//    so you can see that I test 00g0, 0g00, g000
	int valid_values[3] = { 128000,6400,320 };
	for (int i = 0; i < MAYAN_SIZE - 2; i++)
	{
		strcpy_s(tester, MAYAN_SIZE, blank_tester);
		tester[i] = 'g';
		test_single_MayanToInteger(valid_values[i], tester);
	}
	cout << "++Finished++" << endl << endl;
#endif
}
void single_test(int lhs_int, int rhs_int)
{
	bool passed_test = true;

#if TEST_ADD 
	const Mayan k_lhs(lhs_int), k_rhs(rhs_int);
	const Mayan k_result = k_lhs + k_rhs;

	const int k_result_int = MayanToInteger(k_result.get_mayan());

	passed_test = (k_result_int == (lhs_int + rhs_int));
	if (get_print_all() || !passed_test) {
		cout << "\tTesting:" << std::setw(5) << lhs_int << " + " << std::setw(5) << rhs_int << " = " << lhs_int + rhs_int;
		cout << " Mayan: ";
		cout << k_lhs << " + " << k_rhs << " = " << k_result;
	}
	print_pass_fail(passed_test);
#endif
}

//  test some fixed numbers. 
void test_integer_to_Mayan()
{
	cout << "Testing Integer to Mayan" << endl;

#if ! TEST_INTEGER_TO_MAYAN
	print_skipped("Integer to Mayan");
#else

	for (int i = 0; i < 5 ; i++) {
		test_single_IntegerToMayan(test_integer_values[i], test_mayan_values[i]);
	}

	cout << "++Finished++" << endl << endl;
#endif
}

void test_mayan_to_integer()
{
	cout << "Testing Mayan to Integer" << endl;

#if ! TEST_MAYAN_TO_INTEGER
	print_skipped("Mayan to Integer");
#else
	for (int i = 0;  i < 5 ; i++) {
		test_single_MayanToInteger(test_integer_values[i], test_mayan_values[i]);
	}
	cout << "++Finished++" << endl << endl;
#endif	
}
void test_over_under()
{
cout << "Testing Overflow / Negatives" << endl;
const bool k_print_all = get_print_all();

#if ! TEST_OVER_UNDER
	print_skipped("Over / Under");
#else
	bool passed_test = true;
	const Mayan k_over(MAX_INTEGER + 1);
	passed_test = (strcmp(k_over.get_mayan(),"0000") == 0);
	if (k_print_all || !passed_test) {
		cout << "\tOverflow " << MAX_INTEGER + 1 << " converts to " << k_over.get_mayan();
		print_pass_fail( passed_test);
	}

	const Mayan k_zero;
	const Mayan k_five(5);
	const Mayan r = k_zero - k_five;
	passed_test = (strcmp(r.get_mayan(), "0000") == 0);
	if (k_print_all || !passed_test) {
		cout << "\tNegative " << 0-5 << " converts to " << r.get_mayan();
		print_pass_fail( passed_test);
	}

	cout << "++Finished++" << endl << endl;
#endif
}
void test_mayan()
{
cout << "=== Beginning Standard Tests == " << endl;

#if ! MAYAN_TEST
	print_skipped("ALL TESTS");
#else
	test_is_valid();
	test_user_entry();
	test_integer_to_Mayan();
	test_mayan_to_integer();
	test_add();
	test_subtract();
	test_plus_equals();
	test_minus_equals();
	test_comparisons();
	test_over_under();

	cout << endl;
#endif
	cout << "=== END Standard Tests == " << endl;
}