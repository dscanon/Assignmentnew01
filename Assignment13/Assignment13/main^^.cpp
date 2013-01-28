#include<iostream>
#include"Date.h"
#include<string>
#include<sstream>
using namespace std;
int main(){
Date a;
Date b(20,JULY,2000);
Date c (JULY,20,2000);
cout << "Date a = " << a << endl << endl;
cout << "Date b = " << b << endl << endl;
cout << "Date c = " << c << endl << endl;
cout << "a.getDay() / a.getMonth() / a.getYear() = " << a.getDay()<<" / "<<a.getMonth()<<" / "<<a.getYear()<<endl << endl;
cout << "a.toString() = "<<a.toString()<< endl << endl;
cout << "daysInMonth(a.getMonth(),a.getYear()) = " << Date::daysInMonth(a.getMonth(),a.getYear())<<endl << endl;
cout << "isLeapYear(a.getYear()) = " << Date::isLeapYear(a.getYear())<<endl << endl;
cout << "monthToString(a.getMonth()) = " << Date::monthToString(a.getMonth())<<endl << endl;
cout << "b=c -> " <<(b==c) << endl << endl;
cout << "a!=b -> " << (a!=b) << endl << endl;
cout << "a<b -> " << (a<b) << endl << endl;
cout << "a<=b -> " << (a<=b) << endl << endl;
cout << "a>b -> " << (a>b) << endl << endl;
cout << "a>=b -> " << (a>=b) << endl << endl;
cout << "a+5 -> " << a+5 << endl << endl;
cout << "b-6 -> " << b-6 << endl << endl;
cout << "b-a -> " << b-a << endl << endl;
cout << "a-b -> " << (a=b) << endl << endl;
cout << "a+=5 -> " << (a+=5) << endl << endl;
cout << "a-=5 -> " << (a-=5) << endl << endl;
cout << "a++ -> " << endl << endl;
a++;
cout << "a -> " << a << endl << endl;
cout << "++a -> " <<endl << endl;
++a;
cout << "a -> " << a << endl << endl;
cout << "a-- -> " << a-- << endl << endl;
a--;
cout << "a -> " << a << endl << endl;
cout << "--a -> " << endl << endl;
--a;
cout << "a -> " << a << endl << endl;
return 0 ;
}