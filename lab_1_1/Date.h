#pragma once

#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeap(int y) const;
    int daysInMonth(int m, int y) const;
    bool isValid(int d, int m, int y) const;
    void setCurrentDate();

public:
    Date();                      
    Date(int d, int m, int y);    
    Date(const string& str);     

    void print() const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

};
