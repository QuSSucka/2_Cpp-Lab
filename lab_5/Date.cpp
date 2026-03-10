#include "Date.h"
#include <iostream>


bool Date::isLeapYear(int y) const {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::daysInMonth(int m, int y) const {
  static const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
  if (m == 2 && isLeapYear(y)) return 29;
  return days[m - 1];
}

bool Date::isValid(int d, int m, int y) const {
  if (m < 1 || m > 12 || y < 1900) return false;
  return d >= 1 && d <= daysInMonth(m, y);
}

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) {
  if (!isValid(d, m, y))
    throw invalid_argument("Некорректная дата");
  day = d; month = m; year = y;
}

int Date::getDay()   const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear()  const { return year; }

void Date::setDate(int d, int m, int y) {
  if (!isValid(d, m, y))
    throw invalid_argument("Некорректная дата");
  day = d; month = m; year = y;
}

bool Date::operator<=(const Date& other) const {
  if (year != other.year)  return year < other.year;
  if (month != other.month) return month < other.month;
  return day <= other.day;
}

bool Date::operator<(const Date& other) const {
  return (year < other.year) ||
    (year == other.year && month < other.month) ||
    (year == other.year && month == other.month && day < other.day);
}

void Date::print() const {
  cout << (day < 10 ? "0" : "") << day << "."
    << (month < 10 ? "0" : "") << month << "."
    << year;
}

string Date::toString() const {
  return (day < 10 ? "0" : "") + to_string(day) + "." +
    (month < 10 ? "0" : "") + to_string(month) + "." +
    to_string(year);
}
