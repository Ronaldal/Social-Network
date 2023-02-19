#include <iostream>
#include "Exceptions.h"
#ifndef __DATE_H
#define __DATE_H
/*
This class to save the date of birth of member
*/

enum days { FIRST_IN_MONTH = 1, LAST_IN_MONTH = 31 };
enum monthes {JANUARY = 1,DECEMBER = 12};
enum years {FIRST_YEAR_AVAILABLE = 1900,CURRENT_YEAR = 2023};
	
class Date
{
private:
	int day, month, year;
public:
	Date (const int _day = 1 , const int _month=1, const int _year=1991)throw (DateException)
	{
		if (_day < FIRST_IN_MONTH || _day > LAST_IN_MONTH || _month < JANUARY || _month > DECEMBER || _year < FIRST_YEAR_AVAILABLE || _year > CURRENT_YEAR)
			throw DateException();//relevant exception for date class
		else
		{
			day = _day;
			month = _month;
			year = _year;
		}
	}
	//function overloading for date
	friend ostream& operator<<(ostream& os, const Date& date)
	{
		os << date.day << " " << date.month << " " << date.year;
		return os;
	}
	friend istream& operator >>(istream& in, Date& date)
	{
		
		in >> date.day >> date.month >> date.year;
		return in;
	}
};

#endif // !__DATE_H
