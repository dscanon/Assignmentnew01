#include<string>
class Date{
	int date;
	string month;
	int year;
	void Date(){
	date = 1;
	month = "January";
	year = 2000;
	}
	void Date(string month,int a,int b){
		if(a>b){
			year = a;
			date = b;
		}
		else{
			date = a;
			year = b;
		}
	this->month = month;
	}
	void Date(int a,string month,int b){
		if(a>b){
			year = a;
			date = b;
		}
		else{
			date = a;
			year = b;
		}
	this->month = month;
	}
	void Date(int a, int b, string month){
		if(a>b){
			year = a;
			date = b;
		}
		else{
			date = a;
			year = b;
		}
	this->month = month;
	}
	
	int getDate(int a){return a;}
	string getMonth(string str){return str;}
	int getYear(int b){return b;}
	string toString(){
	return date+"-"+month+"-"+year;
	}
	int dayInMonth(string month,int year){
		if(month =="January"||"March"||"July"||"August"||"October"||"December"){
		return 31;
		}
		if(month =="April"||"May"||"June"||"September"||"November"){
		return 30;
		}
		if(month=="Febuary"){
			if(year%4==0){return 29;}
			return 28;
		}
		bool isLeapYear(int year01){
			if(year01%4==0){
			return true;
			}
			else{
			return false;
			}
		}
}