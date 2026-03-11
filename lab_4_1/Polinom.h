#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

class Polinom {
private:
  int n;
  double* a;

public:
  Polinom();
  Polinom(int n);
  Polinom(const double* arr, int n);
  Polinom(const Polinom& other);
  ~Polinom();

  static double round2(double x);
  void print() const;
  double value(double x) const;
  void read();

  int getN() const { return n; }
  double getCoeff(int i) const { return a[i]; }

  void setCoeffs(int deg, const double* coeffs);

  Polinom& operator=(const Polinom& other);
  Polinom operator+(const Polinom& other) const;
  Polinom operator-(const Polinom& other) const;
  Polinom operator*(const Polinom& other) const;
  Polinom operator/(const Polinom& other) const;

  Polinom operator+(double k) const;
  Polinom operator-(double k) const;
  Polinom operator*(double k) const;
  Polinom operator/(double k) const;
};

Polinom operator+(double k, const Polinom& p);
Polinom operator-(double k, const Polinom& p);
Polinom operator*(double k, const Polinom& p);
Polinom operator/(double k, const Polinom& p);

std::ostream& operator<<(std::ostream& os, const Polinom& p);
std::istream& operator>>(std::istream& is, Polinom& p);

#endif
