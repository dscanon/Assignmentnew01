#include <iostream>
#include <string>
#include <sstream>
#include "Date.h"
using namespace std;

Date::Date(){
	this->day = 1;
	this->month = JANUARY;
	this->year = 2000;
}

Date::Date(int day, Month month, int year){
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(Month month, int day, int year){
	this->month = month;
	this->day = day;
	this->year = year;
}

int Date::getDay(){
	return day;
}

Month Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}

string Date::toString(){
	string str;
	ostringstream stream(str);
	stream << day << "-" << monthToString(month).substr(0,3) << "-" <<year;
	return stream.str();
}

string Date::monthToString(Month month){
	switch(month){
		case JANUARY: return "January";
		case FEBRUARY: return "February";
		case MARCH: return "March";
		case APRIL: return "April";
		case MAY: return "May";
		case JUNE: return "June";
		case JULY: return "July";
		case AUGUST: return "August";
		case SEPTEMBER: return "September";
		case NOVEMBER: return "November";
		case DECEMBER: return "December";
		default: return "";
	}
}

int Date::daysInMonth(Month month, int year){
	return month==2?(28+isLeapYear(year)):31-(month-1)%7%2;		
}

bool Date::isLeapYear(int year){
	return (year%4==0 && year%100!=0)||(year%100==0 && year%400==0);
}

ostream & operator<<(ostream & os, Date d1){
	return os << d1.toString();
}

bool operator==(Date d1, Date d2){
	return d1.day == d2.day && d1.month == d2.month && d1.year == d1.year;
}

bool operator!=(Date d1, Date d2){
	return !(d1==d2);
}
