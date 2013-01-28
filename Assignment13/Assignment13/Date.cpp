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
		case OCTOBER: return "October";
		case NOVEMBER: return "November";
		case DECEMBER: return "December";
		default: return "";
	}
}

int Date::daysInMonth(Month month,int year){
	return month==2?(28+isLeapYear(year)):31-(month-1)%7%2;		
}

bool Date::isLeapYear(int year){
	return (year%4==0 && year%100!=0)||year%400==0;
}

ostream & operator<<(ostream & os, Date d1){
	return os << d1.toString();
}

bool operator==(Date d1, Date d2){
	return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year;
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
	d1.day += n;
	while(d1.day > Date::daysInMonth(d1.month,d1.year)){
		d1.day -= Date::daysInMonth(d1.month,d1.year);
		(Month)d1.month = Month(d1.month+1);
		if(d1.month > 12){
			d1.month = Month(1);
			d1.year++;
		}
	}
	return d1;
}

Date operator-(Date d1, int n){
	d1.day -= n;
	while(d1.day<=0){
		d1.month = Month (d1.month-1);
		if(d1.month < 1){
			d1.month = Month(12);
			d1.year--;
		}
		d1.day = Date::daysInMonth(d1.month, d1.year)+d1.day;
	}
	
	return d1;
}



int Date::dayPast(){
	int dayPast=0;
	Month mon = JANUARY;
	while(this->month != mon){
		dayPast += Date::daysInMonth(mon,this->year);
		mon = Month (mon+1);
	}
	dayPast += this->day;
	return dayPast;
}
int Date::dayLeft(){
	Month mon = DECEMBER;
	int dayLeft=0;
	while(this->month != mon){
		dayLeft += Date::daysInMonth(mon,this->year);
		mon = Month (mon-1);
	}

	dayLeft+= Date::daysInMonth(mon,this->year)- this->day;
	return dayLeft;
}

int Date::dayBetweenYear(Date d2){
	int days=0;
	for(int i = (this->year)+1 ; i<d2.year ; i++){
		days += Date::isLeapYear(i)?366:365;
	}
	return days;
}

int operator-(Date d1, Date d2){
	int diffDay = 0;
	if (d1 == d2) return diffDay;
	
	else if(d1 > d2){
		diffDay += d1.dayBetweenYear(d2);
		if(d1.year == d2.year) diffDay +=  (d1.dayPast() - ((Date::isLeapYear(d1.year)?366:365)-d2.dayLeft()));
		else diffDay +=  (d1.dayPast() + d2.dayLeft());
	}

	else{
		diffDay += d1.dayBetweenYear(d2);
		if(d2.year == d1.year) diffDay +=  (d2.dayPast() - ((Date::isLeapYear(d2.year)?366:365)-d1.dayLeft()));
		else diffDay +=  (d2.dayPast() + d1.dayLeft());
	}
	return diffDay;

}
Date & Date::operator=(Date d1){
	this->day = d1.day;
	this->month = d1.month;
	this->year = d1.year;
	return *this;
}
Date & Date::operator+=(int n){
	*this = *this+n;
	return *this;
}
Date & Date::operator-=(int n){
	*this = *this-n;
	return *this;
}

Date operator++(Date &d1){
	d1+=1;
	return d1;
}
Date operator++(Date &d1, int x){
	Date old = d1;
	d1+=1;
	return old;
}
Date operator--(Date &d1){
	d1-=1;
	return d1;
}
Date operator--(Date &d1, int){
	Date old = d1;
	d1-=1;
	return old;
	
}
