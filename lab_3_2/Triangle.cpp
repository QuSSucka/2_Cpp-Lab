#include "Triangle.h"
#include <cstdlib>

bool Triangle::isValid(double x, double y, double z) const {
  return (x + y > z && x + z > y && y + z > x);
}

void Triangle::generateRandom() {
  do {
    a = 1 + rand() % 100;
    b = 1 + rand() % 100;
    c = 1 + rand() % 100;
  } while (!isValid(a, b, c));
}

void Triangle::determineType() {
  double x = a, y = b, z = c;

  double maxSide = max(x, max(y, z));
  double minSide = min(x, min(y, z));
  double midSide = x + y + z - maxSide - minSide;

  double A = minSide * minSide;
  double B = midSide * midSide;
  double C = maxSide * maxSide;

  if (fabs(A + B - C) < 1e-6)
    triangleType = RIGHT;
  else if (A + B > C)
    triangleType = ACUTE;
  else
    triangleType = OBTUSE;
}

Triangle::Triangle(double x, double y, double z) {
  if (isValid(x, y, z)) {
    a = x;
    b = y;
    c = z;
  }
  else {
    generateRandom();
  }
  determineType();
}

void Triangle::print() const {
  cout << "Triangle: " << a << ", " << b << ", " << c << " — ";

  switch (triangleType) {
  case ACUTE:  cout << "acute-angled"; break;
  case OBTUSE: cout << "obtuse-angled"; break;
  case RIGHT:  cout << "right-angled"; break;
  }

  cout << endl;
}

double Triangle::perimeter() const {
  return a + b + c;
}

double Triangle::area() const {
  double p = perimeter() / 2.0;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool Triangle::isSimilar(const Triangle& other) const {
  double s1[3] = { a, b, c };
  double s2[3] = { other.a, other.b, other.c };

  sort(s1, s1 + 3);
  sort(s2, s2 + 3);

  double k1 = s1[0] / s2[0];
  double k2 = s1[1] / s2[1];
  double k3 = s1[2] / s2[2];

  return fabs(k1 - k2) < 1e-6 && fabs(k2 - k3) < 1e-6;
}

bool Triangle::operator<(const Triangle& other) const {
  return this->area() < other.area();
}

bool Triangle::operator<=(const Triangle& other) const {
  return this->area() <= other.area();
}

bool Triangle::operator>(const Triangle& other) const {
  return this->area() > other.area();
}

bool Triangle::operator>=(const Triangle& other) const {
  return this->area() >= other.area();
}

bool Triangle::operator==(const Triangle& other) const {
  return fabs(this->area() - other.area()) < 1e-6;
}

bool Triangle::operator!=(const Triangle& other) const {
  return !(*this == other);
}

Triangle Triangle::operator*(double k) const {
  return Triangle(a * k, b * k, c * k);
}

Triangle Triangle::operator/(double k) const {
  return Triangle(a / k, b / k, c / k);
}

ostream& operator<<(ostream& os, const Triangle& t) {
  os << "Triangle(" << t.a << ", " << t.b << ", " << t.c << ")";
  return os;
}

istream& operator>>(istream& is, Triangle& t) {
  
  double x, y, z;
  is >> x >> y >> z;

  if (x + y > z && x + z > y && y + z > x) {
    t.a = x;
    t.b = y;
    t.c = z;
    t.determineType();
  }
  else {
    throw invalid_argument("Такого треугольника не существует!");
  }

  return is;
}

