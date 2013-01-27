#ifndef _Date_h
#define _Date_h
#include <string>
#include <iostream>
enum Month{
			JANUARY = 1,FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER,NOVEMBER, DECEMBER
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
		static int daysInMonth(Month month,int year);
		static bool isLeapYear(int year);
		static std::string monthToString(Month month);
		
		int dayPast();
		int dayLeft();
		int dayBetweenYear(Date d2);
		friend bool operator==(Date d1, Date d2);
		friend bool operator!=(Date d1, Date d2);
		friend bool operator< (Date d1, Date d2);
		friend bool operator<=(Date d1, Date d2);
		friend bool operator> (Date d1, Date d2);
		friend bool operator>=(Date d1, Date d2);
		friend Date operator+ (Date d1, int n);
		friend Date operator- (Date d1, int n);
		friend int operator- (Date d1, Date d2);
		Date & operator=(Date d2);
		Date & operator+=(int n);
		Date & operator-=(int n);
		friend Date operator++(Date &d1);
		friend Date operator++(Date &d1, int );
		friend Date operator--(Date &d1);
		friend Date operator--(Date &d1, int);
		
 
	private:
		int day;
		Month month;
		int year;
};

std::ostream & operator<<(std::ostream & os, Date d1);
bool operator==(Date d1, Date d2);
bool operator!=(Date d1, Date d2);
bool operator< (Date d1, Date d2);
bool operator<=(Date d1, Date d2);
bool operator> (Date d1, Date d2);
bool operator>=(Date d1, Date d2);
Date operator+ (Date d1, int n);
Date operator- (Date d1, int n);
int operator- (Date d1, Date d2);

Date operator++(Date &d1);
Date operator++(Date &d1, int );
Date operator--(Date &d1);
Date operator--(Date &d1, int);

#endif
