#include <iostream>
#include <locale.h>
#include <climits>

#include "date.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    cout << "=== Тест конструкторов ===\n";
    Date d1;                 // текущая дата
    Date d2(15, 3, 2024);    // обычный конструктор
    Date d3("01.01.2000");   // из строки

    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << "d3 = " << d3 << endl;

    cout << "\n=== Тест сложения и вычитания дней ===\n";
    cout << "d2 + 10 = " << (d2 + 10) << endl;
    cout << "d2 - 20 = " << (d2 - 20) << endl;

    d2 += 5;
    cout << "d2 += 5 == " << d2 << endl;

    d2 -= 7;
    cout << "d2 -= 7 == " << d2 << endl;

    cout << "\n=== Тест разницы дат ===\n";
    cout << "Разница между d2 и d3 = " << (d2 - d3) << " дней\n";

    cout << "\n=== Тест инкремента/декремента ===\n";
    Date d4(31, 12, 2023);
    cout << "d4 = " << d4 << endl;

    cout << "++d4 = " << ++d4 << endl;   // 01.01.2024
    cout << "d4++ = " << d4++ << endl;   // выводит старую дату
    cout << "после d4++ = " << d4 << endl;

    cout << "--d4 = " << --d4 << endl;
    cout << "d4-- = " << d4-- << endl;
    cout << "после d4-- = " << d4 << endl;

    cout << "\n=== Тест сравнения ===\n";
    Date a(10, 5, 2020);
    Date b(12, 5, 2020);

    cout << a << " < " << b << " ? " << (a < b) << endl;
    cout << a << " > " << b << " ? " << (a > b) << endl;
    cout << a << " == " << b << " ? " << (a == b) << endl;
    cout << a << " != " << b << " ? " << (a != b) << endl;

    cout << "\n=== Тест ввода даты ===\n";
    Date userDate;
    cout << "Введите дату в формате dd.mm.yyyy: ";
    cin >> userDate;

    cout << "Вы ввели: " << userDate << endl;

    return 0;
}
