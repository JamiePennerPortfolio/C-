#include "pch.h"
#include <iostream>
#include <istream>
#include "Mayan.h"


Mayan::Mayan(const char * temp)
{
	if(is_valid (temp))
		strcpy_s(mayan_array, MAYAN_SIZE, temp);
	else
		strcpy_s(mayan_array, MAYAN_SIZE, "0000");
	for (int i = 0; i < MAYAN_SIZE - 2; i++)
	{
		mayan_array[i] = tolower(mayan_array[i]);
	}
}


bool is_valid(const char m[])
{
	if (strlen(m) != 4)
		return false;

	for (int i = 0; i < MAYAN_SIZE-1; i++)
	{
		if (m[i] >= '0' && m[i] <= '9')
		{ }
		else if (m[i] >= 'a' && m[i] <= 'j')
		{ }
		else
			return false;	
	}
	return true;
}


int MayanToInteger(const char * source)
{
	char mayan_array[MAYAN_SIZE] = "0000";

	int work = 0;
	int y = 0;

	for (int i = 3; i >= 0; i--)
	{	
		const int ASCII_ZERO = '0';
		const int ASCII_W = 'W';
		int x = 0;
		
		if (isdigit(source[i]))
		{
			x = source[i] - ASCII_ZERO;
		}
		else
		{
			x = source[i] - ASCII_W;
		}
		
		work += x * pow(20, y);
		y++;
	}
	
	return work;   
}


void IntegerToMayan(char result[], int source)
{
	strcpy_s(result, MAYAN_SIZE, "0000");

	int b = source;
	int j = MAYAN_SIZE - 2;

	const int ASCII_ZERO = '0';
	const int ASCII_W = 'W';
	int i = 3;

	if (source > MAX_INTEGER)
	{
		strcpy_s(result, MAYAN_SIZE, "0000");
		return;
	}
		
	while (j > 0 && b > 0)
	{
		j = b % 20;
		b = b / 20;

		if (j > 9)
		{
			j = j + ASCII_W;
		}
		else
		{
			j = j + ASCII_ZERO;
		}

		result[i];
		result[i] = j;
		i--;
	}
	
}


Mayan operator+(const Mayan  &lhs, const Mayan  &rhs)
{
	Mayan m;
	int x, y, result;
	
	x = MayanToInteger(lhs.mayan_array);
	y = MayanToInteger(rhs.mayan_array);

	result = x + y;


	if (result > MAX_INTEGER)
	{
		return "0000";
	}
	else
	{
		IntegerToMayan(m.mayan_array, result);
		return m;
	}
}


Mayan operator-(const Mayan  &lhs, const Mayan &rhs)
{
	Mayan m;
	int x, y, result;

	x = MayanToInteger(lhs.mayan_array);
	y = MayanToInteger(rhs.mayan_array);

	result = x - y;

	if (result < 0)
	{
		return "0000";
	}
	else
	{
		IntegerToMayan(m.mayan_array, result);
		return m;
	}

}


Mayan & Mayan::operator+=(const Mayan & rhs)
{
	*this = *this + rhs.mayan_array;
	return *this;
}


Mayan & Mayan::operator-=(const Mayan & rhs)
{
	*this = *this - rhs.mayan_array;
	return *this;
}


bool operator==(const Mayan & lhs, const Mayan & rhs)
{
	int x, y;
	x = MayanToInteger(lhs.mayan_array);
	y = MayanToInteger(rhs.mayan_array);
	return (x == y);
}


bool operator!=(const Mayan & lhs, const Mayan & rhs)
{
	int x, y;
	x = MayanToInteger(lhs.mayan_array);
	y = MayanToInteger(rhs.mayan_array);
	return (x != y);
}


bool operator>(const Mayan & lhs, const Mayan & rhs)
{
	int x, y;
	x = MayanToInteger(lhs.mayan_array);
	y = MayanToInteger(rhs.mayan_array);
	return (x > y);
}


 std::ostream & operator<<(std::ostream & out,const Mayan & rhs)
{
	 for (int i = 0; i < MAYAN_SIZE; i++)
	 {
		 out << rhs.mayan_array[i];
	 }
	 return out;
}

 
std::istream & operator>>(std::istream & in, Mayan & rhs)
{
	in >> rhs.mayan_array;
	for (int i = 0; i < MAYAN_SIZE; i++)
	{
		rhs.mayan_array[i] = tolower(rhs.mayan_array[i]);
	}
	return in;
}