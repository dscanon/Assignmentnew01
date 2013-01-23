#ifndef _Date_h
#define _Date_h
#include <string>

class Date {
 public:
 
private:
  int date;
  enum Month{
    January = 1,FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, NOVEMBER, DECEMBER
  }
  int year;

}
#endif
#ifndef _Date_h
#define _Date_h
#include <string>
#include <iostream>
class Date {
 public:
		Date();
		Date(int date, Month mon, int year);
		Date(Month mon, int date, int year);
		int getDay();
		Month getMonth();
		int getYear();
		string toString();
		int daysInMonth(Month mon, int year);
		bool isLeapYear(int year);
		std::string monthToString(Month mon);


 
	private:
		int date = 1;
		enum Month{
			January = 1,FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, NOVEMBER, DECEMBER
		};
		int year = 2000;
		std::ostream & operator<<(std::ostream & os, Date dat);
		friend bool operator==(Date d1, Date d2);
		bool operator!=(Date d1, Date d2);
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
		friend Date operator--(Date dq, int);

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
#endif
