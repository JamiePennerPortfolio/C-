#pragma once
#include<iostream>
#include <locale>

const int MAYAN_SIZE = 5;  // 4 characters of numbers, + 1 for '\0'
const int MAX_INTEGER = 159999;  // with 4 characters we can get up to jjjj which is 159999

//  here is a hint... I used these constants in my conversion process.  
const int ASCII_ZERO = '0';
const int ASCII_A = 'a';
const int ASCII_J = 'j';

int MayanToInteger(const char * );
void IntegerToMayan(char result[], int source);
bool is_valid(const char m[]);

//  Add your class and any helper function prototypes here.  

// Here is an empty class to start with
//  This allows the initial code I give you to compile / link.  
//    Update as you need to (including deleting these comment lines.)
class Mayan
{
	char mayan_array[MAYAN_SIZE];

public:

	friend Mayan operator+(const Mayan  & lhs, const Mayan & rhs);
	friend Mayan operator-(const Mayan  & lhs, const Mayan & rhs);
	Mayan & operator+=(const Mayan & rhs);
	Mayan & operator-=(const Mayan & rhs);
	friend bool operator==(const Mayan & lhs, const Mayan & rhs);
	friend bool operator!=(const Mayan & lhs, const Mayan & rhs);
	friend bool operator>(const Mayan & lhs, const Mayan & rhs);
	friend std::ostream & operator <<(std::ostream & out, const Mayan & rhs);
	friend std::istream & operator >>(std::istream & in, Mayan & rhs);

	Mayan() : mayan_array("0000") { ; }
	Mayan(const char * temp);
	Mayan(int i) { IntegerToMayan(mayan_array, i); }
	const char* get_mayan() const { return mayan_array;}
	
};