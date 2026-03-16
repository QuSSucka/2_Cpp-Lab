#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "Date.h"
#include <ctime>
#include <cmath>

using namespace std;

bool Date::isLeap(int y) const {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const {
  static int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
  if (m == 2 && isLeap(y)) return 29;
  return days[m - 1];
}

bool Date::isValid(int d, int m, int y) const {
  if (y < 1 || m < 1 || m > 12) return false;
  return d >= 1 && d <= daysInMonth(m, y);
}

void Date::setCurrentDate() {
  time_t t = time(nullptr);
  tm* now = localtime(&t);
  day = now->tm_mday;
  month = now->tm_mon + 1;
  year = now->tm_year + 1900;
}

Date::Date() { setCurrentDate(); }

Date::Date(int d, int m, int y) {
  if (isValid(d, m, y)) { day = d; month = m; year = y; }
  else setCurrentDate();
}

Date::Date(const string& str) {
  int d, m, y;
  bool ok = true;
  size_t p1 = str.find('.');
  size_t p2 = str.find('.', p1 + 1);
  if (p1 == string::npos || p2 == string::npos) {
    ok = false;
  }
  else {
    try {
      d = stoi(str.substr(0, p1));
      m = stoi(str.substr(p1 + 1, p2 - p1 - 1));
      y = stoi(str.substr(p2 + 1));
    }
    catch (...) { ok = false; }
  }
  if (ok && isValid(d, m, y)) { day = d; month = m; year = y; }
  else setCurrentDate();
}

void Date::print() const {
  if (day < 10) cout << "0";
  cout << day << ".";
  if (month < 10) cout << "0";
  cout << month << "." << year << endl;
}

int Date::getDay()   const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear()  const { return year; }

void Date::setDay(int d) { if (isValid(d, month, year)) day = d; }
void Date::setMonth(int m) { if (m >= 1 && m <= 12 && day <= daysInMonth(m, year)) month = m; }
void Date::setYear(int y) { if (y >= 1 && day <= daysInMonth(month, y)) year = y; }

long long Date::toDays() const {
  long long days = 0;
  for (int y = 1; y < year; y++) days += isLeap(y) ? 366 : 365;
  for (int m = 1; m < month; m++) days += daysInMonth(m, year);
  days += day;
  return days;
}

void Date::fromDays(long long days) {
  year = 1;
  while (true) {
    int dy = isLeap(year) ? 366 : 365;
    if (days > dy) { days -= dy; year++; }
    else break;
  }
  month = 1;
  while (true) {
    int dm = daysInMonth(month, year);
    if (days > dm) { days -= dm; month++; }
    else break;
  }
  day = (int)days;
}

Date  Date::operator+ (int d) const { Date r = *this; r.fromDays(r.toDays() + d); return r; }
Date  Date::operator- (int d) const { Date r = *this; r.fromDays(r.toDays() - d); return r; }
Date& Date::operator+=(int d) { fromDays(toDays() + d); return *this; }
Date& Date::operator-=(int d) { fromDays(toDays() - d); return *this; }

long long Date::operator-(const Date& other) const { return toDays() - other.toDays(); }

Date& Date::operator++() { *this += 1; return *this; }
Date  Date::operator++(int) { Date t = *this; *this += 1; return t; }
Date& Date::operator--() { *this -= 1; return *this; }
Date  Date::operator--(int) { Date t = *this; *this -= 1; return t; }

bool Date::operator==(const Date& o) const { return day == o.day && month == o.month && year == o.year; }
bool Date::operator!=(const Date& o) const { return !(*this == o); }
bool Date::operator< (const Date& o) const {
  if (year != o.year)  return year < o.year;
  if (month != o.month) return month < o.month;
  return day < o.day;
}
bool Date::operator> (const Date& o) const { return o < *this; }
bool Date::operator<=(const Date& o) const { return !(*this > o); }
bool Date::operator>=(const Date& o) const { return !(*this < o); }

ostream& operator<<(ostream& os, const Date& d) {
  if (d.getDay() < 10) os << "0";
  os << d.getDay() << ".";
  if (d.getMonth() < 10) os << "0";
  os << d.getMonth() << "." << d.getYear();
  return os;
}

istream& operator>>(istream& is, Date& d) {
  string s;
  is >> s;
  Date tmp(s);
  d = tmp;
  return is;
}
