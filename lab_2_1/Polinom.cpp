#include <iostream>
#include <cmath>
#include "Polinom.h"

using namespace std;

Polinom::Polinom() : n(0), a(nullptr) {}

Polinom::Polinom(int n) : n(n) {
  a = new double[n];
  for (int i = 0; i < n; i++)
    a[i] = 0.0;
}

Polinom::Polinom(const double* arr, int n) : n(n) {
  a = new double[n];
  for (int i = 0; i < n; i++)
    a[i] = arr[i];
}

Polinom::Polinom(const Polinom& other) : n(other.n) {
  a = new double[n];
  for (int i = 0; i < n; i++)
    a[i] = other.a[i];
}

Polinom::~Polinom() {
  delete[] a;
}

Polinom& Polinom::operator=(const Polinom& other) {
  if (this == &other) return *this;

  delete[] a;

  n = other.n;
  a = new double[n];
  for (int i = 0; i < n; i++)
    a[i] = other.a[i];

  return *this;
}

void Polinom::print() const {
  if (n == 0) {
    cout << "0";
    return;
  }

  bool first = true;

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) continue;

    if (!first) {
      cout << (a[i] > 0 ? "+" : "");
    }

    if (i == 0) {
      cout << a[i];
    }
    else if (i == 1) {
      if (a[i] == 1) cout << "x";
      else if (a[i] == -1) cout << "-x";
      else cout << a[i] << "x";
    }
    else {
      if (a[i] == 1) cout << "x^" << i;
      else if (a[i] == -1) cout << "-x^" << i;
      else cout << a[i] << "x^" << i;
    }

    first = false;
  }

  if (first) cout << "0"; 
}

double Polinom::value(double x) const {
  double result = 0;
  for (int i = 0; i < n; i++)
    result += a[i] * pow(x, i);
  return result;
}

void Polinom::read() {
  cout << "Введите степень полинома: ";
  int deg;
  cin >> deg;

  n = deg + 1;

  delete[] a;
  a = new double[n];

  cout << "Введите коэффициенты от старшего к свободному:\n";

  for (int i = deg; i >= 0; i--) {
    cin >> a[i];
  }
}
