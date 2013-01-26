#ifndef _Date_h
#ifndef _Date_h
#define _Date_h
#include <string>
#include <iostream>
enum Month{
 		JANUARY = 1,FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
		};

class Date {
	public:
		Date();
		Date(int day, Month month, int year);
		Date(Month month, int day, int year);
		int getDay();
		Month getMonth();
		int getYear();
		std::string toString();
		int daysInMonth(Month month, int year);
		bool isLeapYear(int year);
		std::string monthToString(Month month);
		friend bool operator==(Date d1, Date d2);
		friend bool operator!=(Date d1, Date d2);
		friend bool operator< (Date d1, Date d2);
		friend bool operator<=(Date d1, Date d2);
		friend bool operator> (Date d1, Date d2);
		friend bool operator>=(Date d1, Date d2);
		friend Date operator+ (Date d1, int n);
		friend Date operator- (Date d1, int n);
		friend Date operator- (Date d1, Date d2);
		friend Date operator+=(Date d1, int n);
		friend Date operator-=(Date d1, int n);
		friend Date operator++(Date d1);
		friend Date operator++(Date d1, int );
		friend Date operator--(Date d1);
		friend Date operator--(Date d1, int);
		friend Date & operator=(Date & date);

 
	private:
		int day;
		Month month;
		int year;
};

std::ostream & operator<<(std::ostream & os, Date dat);
bool operator==(Date d1, Date d2);
bool operator!=(Date d1, Date d2);
bool operator< (Date d1, Date d2);
bool operator<=(Date d1, Date d2);
bool operator> (Date d1, Date d2);
bool operator>=(Date d1, Date d2);
Date operator+ (Date d1, int n);
Date operator- (Date d1, int n);
Date operator- (Date d1, Date d2);
Date operator+=(Date d1, int n);
Date operator-=(Date d1, int n);
Date operator++(Date d1);
Date operator++(Date d1, int );
Date operator--(Date d1);
Date operator--(Date d1, int);
Date & operator=(Date & date);
#endif
