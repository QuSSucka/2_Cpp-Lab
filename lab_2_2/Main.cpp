#include <iostream>
#include "LongInteger.h"
#include <locale.h>
using namespace std;

int main() {
  setlocale(LC_ALL, "");
  LongInteger a("123456789876543210123456789");
  cout << "Число a = ";
  a.print();
  cout << endl;

  LongInteger b = a;
  cout << "Число b = ";
  b.print();
  cout << endl;

  LongInteger c;
  c.set("999999999999999999999999999999");
  cout << "Число c = ";
  c.print();
  cout << endl;

  return 0;
}
