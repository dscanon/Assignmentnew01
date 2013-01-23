#ifndef _Date_h
#define _Date_h
#include <string>

class Date {
 public:
  Date();
  Date(int date, Month mon, int year);
  Date(Month mon, )
 
private:
  int date = 1;
  enum Month{
    January = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, NOVEMBER, DECEMBER
  };
  int year = 2000;

}
#endif
