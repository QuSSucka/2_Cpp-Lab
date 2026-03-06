#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

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
};

#endif
