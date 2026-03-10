#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class Date {
private:
  int day, month, year;

  bool isLeapYear(int y) const;
  int  daysInMonth(int m, int y) const;
  bool isValid(int d, int m, int y) const;

public:
  Date();
  Date(int d, int m, int y);

  int getDay()   const;
  int getMonth() const;
  int getYear()  const;

  void setDate(int d, int m, int y);

  bool operator<=(const Date& other) const;
  bool operator< (const Date& other) const;

  void        print()    const;
  string toString() const;
};
