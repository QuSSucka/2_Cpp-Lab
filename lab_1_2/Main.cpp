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

  return 0;
}
