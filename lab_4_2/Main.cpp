#include <iostream>
#include "LongInteger.h"
using namespace std;

int main() {
  setlocale(LC_ALL, "");

  LongInteger a;// ("");
  LongInteger b;// ("");

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  cout << "a + b = " << (a + b) << endl;
  cout << "a - b = " << (a - b) << endl;

  cout << "a + 100 = " << (a + 100) << endl;
  cout << "a - 100 = " << (a - 100) << endl;

  cout << "100 + b = " << (100 + b) << endl;
  cout << "100 - b = " << (100 - b) << endl;

  LongInteger c("100000000000000000000000");
  cout << "c = " << c << endl;
  cout << "c++ = " << c++ << ", после: " << c << endl;
  cout << "++c = " << ++c << endl;
  cout << "c-- = " << c-- << ", после: " << c << endl;
  cout << "--c = " << --c << endl;

  LongInteger x("500000000000000000000000000"), y("30000000000000000000000000000");
  cout << boolalpha;
  cout << "x == y: " << (x == y) << endl;
  cout << "x != y: " << (x != y) << endl;
  cout << "x >  y: " << (x > y) << endl;
  cout << "x >= y: " << (x >= y) << endl;
  cout << "x <  y: " << (x < y) << endl;
  cout << "x <= y: " << (x <= y) << endl;

  LongInteger d;
  d = x;
  cout << "d = x -> d = " << d << endl;

  cout << "Введите длинное целое: ";
  LongInteger input;
  cin >> input;
  cout << "Вы ввели: " << input << endl;

  return 0;
}
