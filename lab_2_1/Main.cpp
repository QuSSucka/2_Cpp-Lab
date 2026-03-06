#include <iostream>
#include "Polinom.h"
#include <cstdlib>
#include <locale.h>


using namespace std;

int main() {
  setlocale(LC_ALL, "");
  Polinom p;

  cout << "Введите полином:\n";
  p.read();

  cout << "Вы ввели: ";
  p.print();
  cout << endl;

  double x;
  cout << "Введите x: ";
  cin >> x;

  cout << "Значение полинома: " << p.value(x) << endl;

  return 0;
}
