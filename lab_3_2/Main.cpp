#include <iostream>
#include <ctime>
#include <locale.h>
#include "TriangleArray.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "");
  srand(time(0));

  TriangleArray arr(1000);
  arr.print();

  cout << "\nAcute-angled: " << arr.countAcute() << endl;
  cout << "Obtuse-angled: " << arr.countObtuse() << endl;
  cout << "Right-angled: " << arr.countRight() << endl;

  cout << "Similar triangles: " << arr.countSimilar() << endl;
  cout << "With the same area: " << arr.countEqualArea() << endl;
  cout << "With the same perimeter: " << arr.countEqualPerimeter() << endl;

  Triangle t1(3, 4, 5);
  Triangle t2(6, 8, 10);

  cout << "t1 = " << t1 << endl;
  cout << "t2 = " << t2 << endl;

  cout << "\n=== Сравнение по площади ===\n";
  cout << "t1 < t2 : " << (t1 < t2) << endl;
  cout << "t1 == t2 : " << (t1 == t2) << endl;

  cout << "\n=== Масштабирование ===\n";
  Triangle t3 = t1 * 2;
  cout << "t1 * 2 = " << t3 << endl;

  Triangle t4 = t3 / 2;
  cout << "t3 / 2 = " << t4 << endl;

  
  cout << "=== Ввод треугольника ===\n";
  Triangle t(1, 1, 1);
  while (true) {
    cout << "Введите три стороны: ";

    try {
      cin >> t;
      break;
    }
    catch (const invalid_argument& e) {
      cout << "Ошибка: " << e.what() << endl;

      cin.clear();
      cin.ignore(10000, '\n');
    }
  }

  cout << "Вы ввели: " << t << endl;


  return 0;
}
