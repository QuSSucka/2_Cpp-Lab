#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
  int day, month, year;

  bool isLeap(int y) const;
  int  daysInMonth(int m, int y) const;
  bool isValid(int d, int m, int y) const;
  void setCurrentDate();

  long long toDays() const;
  void fromDays(long long days);

public:
  Date();
  Date(int d, int m, int y);
  Date(const string& str);

  void print() const;

  int getDay()   const;
  int getMonth() const;
  int getYear()  const;

  void setDay(int d);
  void setMonth(int m);
  void setYear(int y);

  Date  operator+ (int days) const;
  Date  operator- (int days) const;
  Date& operator+=(int days);
  Date& operator-=(int days);

  long long operator-(const Date& other) const;

  Date& operator++();
  Date  operator++(int);
  Date& operator--();
  Date  operator--(int);

  bool operator==(const Date& other) const;
  bool operator!=(const Date& other) const;
  bool operator< (const Date& other) const;
  bool operator> (const Date& other) const;
  bool operator<=(const Date& other) const;
  bool operator>=(const Date& other) const;

  friend ostream& operator<<(ostream& os, const Date& d);
  friend istream& operator>>(istream& is, Date& d);
};
