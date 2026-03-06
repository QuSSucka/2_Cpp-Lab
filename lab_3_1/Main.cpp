#include <iostream>
#include <locale.h>
#include <climits>

#include "date.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    Date d1;
    d1.print();

    Date d2(31, 2, 2020);
    d2.print();

    Date d3("15.03.2021");
    d3.print();

    d3.setDay(28);
    d3.setMonth(2);
    d3.setYear(2024);
    d3.print();

    int day, month, year;
    while (true) {
        cout << "Введите дату (день месяц год), например: 15 3 2024 : ";
        if (!(cin >> day >> month >> year)) {
            cout << "Неверный ввод. Введите три целых числа.\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }

        Date userDate(day, month, year);
        if (userDate.getDay() == day && userDate.getMonth() == month && userDate.getYear() == year) {
            cout << "Введённая дата корректна: ";
            userDate.print();
            break;
        }
        else {
            cout << "Неверная дата. Попробуйте ещё раз.\n";
        }
    }

    return 0;
}
