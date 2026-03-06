#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "Date.h"
#include <iostream>
#include <ctime>


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
    if (d < 1 || d > daysInMonth(m, y)) return false;
    return true;
}

void Date::setCurrentDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now->tm_year + 1900;
}

Date::Date() {
    setCurrentDate();
}

Date::Date(int d, int m, int y) {
    if (isValid(d, m, y)) {
        day = d;
        month = m;
        year = y;
    }
    else {
        setCurrentDate();
    }
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
        catch (...) {
            ok = false;
        }
    }

    if (ok && isValid(d, m, y)) {
        day = d;
        month = m;
        year = y;
    }
    else {
        setCurrentDate();
    }
}

void Date::print() const {
    if (day < 10) cout << "0";
    cout << day << ".";
    if (month < 10) cout << "0";
    cout << month << ".";
    cout << year << endl;
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}



void Date::setDay(int d) {
    if (isValid(d, month, year)) day = d;
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12 && day <= daysInMonth(m, year))
        month = m;
}

void Date::setYear(int y) {
    if (y >= 1 && day <= daysInMonth(month, y))
        year = y;
}
