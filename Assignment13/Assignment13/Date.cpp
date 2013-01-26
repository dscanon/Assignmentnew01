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

bool operator<(Date d1, Date d2){
	if (d1.year < d2.year) return true;
	else {
		if(d1.month < d2.month && d1.year == d2.year) return true;
		else if (d1.month == d2.month && d1.year == d2.year && d1.day < d2.day) return true;
		else return false;
	}
}

bool operator<=(Date d1, Date d2){
	return d1<d2 || d1==d2;
}

bool operator>(Date d1, Date d2){
	return !(d1<=d2);
}

bool operator>=(Date d1, Date d2){
	return d1 > d2 || d1==d2;
}
Date operator+(Date d1, int n){
	if(d1.day+n<=daysInMonth(d1.month))
	{
		d1.day += n;
		return d1;
	}
	else{	
		int m=d1.day+n;
		while(m>daysInMonth(d1.month)){
			m=m-dayInMonth(d1.month);
			Month(d1.month++);
  				while(d1.month>12){
				d1.month=1;
				year++;	
				}	
		}	
	}		
}
Date operator-(Date d1, int n){
	if(n<d1.day){
		d1.day = d1.day-n;
		return d1;
	}
	else{	
		int m=n-d1.day;
		while(m>0){
			d1.month--;
			while(m>daysInMonth(month)){
				m = m-daysInMonth(month);
				month--;
			}
			d1.day = daysInMonth(month)-m;
			return d1;
		}
		
	}
	
}
