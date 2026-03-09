#include "Polinom.h"

int main() {
  setlocale(LC_ALL, "");
  cout << "=== Тест ввода полиномов ===\n";
  Polinom p1, p2;

  cout << "Введите первый полином:\n";
  cin >> p1;

  cout << "Введите второй полином:\n";
  cin >> p2;

  cout << "\n=== Вывод полиномов ===\n";
  cout << "p1 = " << p1 << endl;
  cout << "p2 = " << p2 << endl;

  cout << "\n=== Операции p1 + p2, p1 - p2, p1 * p2, p1 / p2 ===\n";
  cout << "p1 + p2 = " << (p1 + p2) << endl;
  cout << "p1 - p2 = " << (p1 - p2) << endl;
  cout << "p1 * p2 = " << (p1 * p2) << endl;
  try {
    cout << "p1 / p2 = " << (p1 / p2) << endl;
  }
  catch (const invalid_argument& e) {
    cout << e.what() << endl;
  }
  

  cout << "\n=== Операции p1 + число, p1 - число, p1 * число, p1 / число ===\n";
  cout << "p1 + 5 = " << (p1 + 5) << endl;
  cout << "p1 - 5 = " << (p1 - 5) << endl;
  cout << "p1 * 5 = " << (p1 * 5) << endl;
  try {
    cout << "p1 / 5 = " << (p1 / 5) << endl;
  }
  catch (const invalid_argument& e) {
    cout << e.what() << endl;
  }

  cout << "\n=== Операции число + p1, число - p1, число * p1, число / p1 ===\n";
  cout << "5 + p1 = " << (5 + p1) << endl;
  cout << "5 - p1 = " << (5 - p1) << endl;
  cout << "5 * p1 = " << (5 * p1) << endl;
  cout << "5 / p1 = " << (5 / p1) << endl;

  cout << "\n=== Тест присваивания ===\n";
  Polinom p3;
  p3 = p1;
  cout << "p3 = p1 -> p3 = " << p3 << endl;

  cout << "\n=== Проверка значения полинома в точке ===\n";
  double x;
  cout << "Введите x: ";
  cin >> x;
  cout << "p1(" << x << ") = " << p1.value(x) << endl;

  return 0;
}
