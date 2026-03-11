#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

// убрали: using namespace std;

enum TriangleType { ACUTE, OBTUSE, RIGHT };

class Triangle {
private:
  double a, b, c;
  TriangleType triangleType;

  bool isValid(double x, double y, double z) const;
  void generateRandom();
  void determineType();

public:
  Triangle(double x, double y, double z);

  void print() const;
  double perimeter() const;
  double area() const;
  TriangleType getType() const { return triangleType; }

  bool isSimilar(const Triangle& other) const;

  double getA() const { return a; }
  double getB() const { return b; }
  double getC() const { return c; }

  void setSides(double x, double y, double z);

  bool operator<(const Triangle& other) const;
  bool operator<=(const Triangle& other) const;
  bool operator>(const Triangle& other) const;
  bool operator>=(const Triangle& other) const;
  bool operator==(const Triangle& other) const;
  bool operator!=(const Triangle& other) const;

  Triangle operator*(double k) const;
  Triangle operator/(double k) const;
};

std::ostream& operator<<(std::ostream& os, const Triangle& t);
std::istream& operator>>(std::istream& is, Triangle& t);

#endif
