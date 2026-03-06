#ifndef TRIANGLEARRAY_H
#define TRIANGLEARRAY_H

#include "Triangle.h"

class TriangleArray {
private:
  Triangle** arr;
  int size;

public:
  TriangleArray(int n);
  ~TriangleArray();

  void print() const;

  int countAcute() const;
  int countObtuse() const;
  int countRight() const;

  int countSimilar() const;
  int countEqualArea() const;
  int countEqualPerimeter() const;
};

#endif
