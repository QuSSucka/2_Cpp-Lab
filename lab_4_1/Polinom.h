#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <locale.h>
using namespace std;

class Polinom {
private:
  int n;
  double* a;
  static double round2(double x);

public:
  Polinom();
  Polinom(int n);
  Polinom(const double* arr, int n);
  Polinom(const Polinom& other);
  ~Polinom();

  void print() const;
  double value(double x) const;

  void read();

  Polinom& operator=(const Polinom& other);
  Polinom operator+(const Polinom& other) const;
  Polinom operator-(const Polinom& other) const;
  Polinom operator*(const Polinom& other) const;
  Polinom operator/(const Polinom& other) const;

  Polinom operator+(double k) const;
  Polinom operator-(double k) const;
  Polinom operator*(double k) const;
  Polinom operator/(double k) const;

  friend Polinom operator+(double k, const Polinom& p);
  friend Polinom operator-(double k, const Polinom& p);
  friend Polinom operator*(double k, const Polinom& p);
  friend Polinom operator/(double k, const Polinom& p);

  friend ostream& operator<<(ostream& os, const Polinom& p);
  friend istream& operator>>(istream& is, Polinom& p);

};

#endif
