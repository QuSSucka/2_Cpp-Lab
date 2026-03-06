#include "TriangleArray.h"
#include <cmath>

TriangleArray::TriangleArray(int n) {
  size = n;
  arr = new Triangle * [size];

  for (int i = 0; i < size; i++) {
    double a = 1 + rand() % 50;
    double b = 1 + rand() % 50;
    double c = 1 + rand() % 50;

    arr[i] = new Triangle(a, b, c);
  }
}

TriangleArray::~TriangleArray() {
  for (int i = 0; i < size; i++)
    delete arr[i];
  delete[] arr;
}

void TriangleArray::print() const {
  for (int i = 0; i < size; i++)
    arr[i]->print();
}

int TriangleArray::countAcute() const {
  int cnt = 0;
  for (int i = 0; i < size; i++)
    if (arr[i]->getType() == ACUTE) cnt++;
  return cnt;
}

int TriangleArray::countObtuse() const {
  int cnt = 0;
  for (int i = 0; i < size; i++)
    if (arr[i]->getType() == OBTUSE) cnt++;
  return cnt;
}

int TriangleArray::countRight() const {
  int cnt = 0;
  for (int i = 0; i < size; i++)
    if (arr[i]->getType() == RIGHT) cnt++;
  return cnt;
}

int TriangleArray::countSimilar() const {
  int cnt = 0;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i]->isSimilar(*arr[j]))
        cnt++;
    }
  }
  return cnt;
}

int TriangleArray::countEqualArea() const {
  int cnt = 0;

  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (fabs(arr[i]->area() - arr[j]->area()) < 1e-6)
        cnt++;

  return cnt;
}

int TriangleArray::countEqualPerimeter() const {
  int cnt = 0;

  for (int i = 0; i < size; i++)
    for (int j = i + 1; j < size; j++)
      if (fabs(arr[i]->perimeter() - arr[j]->perimeter()) < 1e-6)
        cnt++;

  return cnt;
}
