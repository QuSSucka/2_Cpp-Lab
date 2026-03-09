#include "Polinom.h"

double Polinom::round2(double x)
{
  return floor(x * 100 + 0.5) / 100;
}

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
    double rounded = round2(a[i]);
    if (rounded == 0) continue;

    if (!first) {
      cout << (rounded > 0 ? "+" : "");
    }

    if (i == 0) {
      cout << rounded;
    }
    else if (i == 1) {
      if (rounded == 1) cout << "x";
      else if (rounded == -1) cout << "-x";
      else cout << rounded << "x";
    }
    else {
      if (rounded == 1) cout << "x^" << i;
      else if (rounded == -1) cout << "-x^" << i;
      else cout << rounded << "x^" << i;
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

Polinom Polinom::operator+(const Polinom& other) const {
  int maxN = max(n, other.n);
  Polinom result(maxN);

  for (int i = 0; i < maxN; i++) {
    double a1 = (i < n ? a[i] : 0);
    double a2 = (i < other.n ? other.a[i] : 0);
    result.a[i] = a1 + a2;
  }
  return result;
}

Polinom Polinom::operator-(const Polinom& other) const {
  int maxN = max(n, other.n);
  Polinom result(maxN);

  for (int i = 0; i < maxN; i++) {
    double a1 = (i < n ? a[i] : 0);
    double a2 = (i < other.n ? other.a[i] : 0);
    result.a[i] = a1 - a2;
  }
  return result;
}

Polinom Polinom::operator*(const Polinom& other) const {
  Polinom result(n + other.n - 1);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < other.n; j++)
      result.a[i + j] += a[i] * other.a[j];

  return result;
}

Polinom Polinom::operator/(const Polinom& other) const {
  int maxN = max(n, other.n);
  Polinom result(maxN);

  for (int i = 0; i < maxN; i++) {
    double a1 = (i < n ? a[i] : 0);
    double a2 = (i < other.n ? other.a[i] : 0);

    if (a2 == 0) {
      throw invalid_argument("Ошибка: деление на коэффициент 0 в полиноме невозможно!");
    }
    result.a[i] = a1 / a2;
  }
  return result;
}

Polinom Polinom::operator+(double k) const {
  Polinom r(*this);
  r.a[0] += k;
  return r;
}

Polinom Polinom::operator-(double k) const {
  Polinom r(*this);
  r.a[0] -= k;
  return r;
}

Polinom Polinom::operator*(double k) const {
  Polinom r(*this);
  for (int i = 0; i < n; i++) r.a[i] *= k;
  return r;
}

Polinom Polinom::operator/(double k) const {
  if (k == 0) {
    throw invalid_argument("Ошибка: деление полинома на 0 невозможно!");
  }

  Polinom r(*this);
  for (int i = 0; i < n; i++) {
    r.a[i] /= k;
  }
  return r;
}


Polinom operator+(double k, const Polinom& p) {
  return p + k;
}

Polinom operator-(double k, const Polinom& p) {
  Polinom r(p);
  r.a[0] = k - r.a[0];
  return r;
}

Polinom operator*(double k, const Polinom& p) {
  return p * k;
}

Polinom operator/(double k, const Polinom& p) {
  Polinom r(p);

  for (int i = 0; i < p.n; i++) {
    if (p.a[i] == 0) {
      throw invalid_argument("Ошибка: деление числа на коэффициент 0 невозможно!");
    }
    r.a[i] = k / p.a[i];
  }

  return r;
}


ostream& operator<<(ostream& os, const Polinom& p) {
  if (p.n == 0) {
    os << "0";
    return os;
  }

  bool first = true;

  for (int i = p.n - 1; i >= 0; i--) {
    double rounded = Polinom::round2(p.a[i]);
    if (rounded == 0) continue;

    if (!first) {
      os << (rounded > 0 ? "+" : "");
    }

    if (i == 0) {
      os << rounded;
    }
    else if (i == 1) {
      if (rounded == 1) os << "x";
      else if (rounded == -1) os << "-x";
      else os << rounded << "x";
    }
    else {
      if (rounded == 1) os << "x^" << i;
      else if (rounded == -1) os << "-x^" << i;
      else os << rounded << "x^" << i;
    }

    first = false;
  }

  if (first) os << "0";

  return os;
}



istream& operator>>(istream& is, Polinom& p) {
  int deg;
  cout << "Введите степень полинома: ";
  is >> deg;

  p.n = deg + 1;
  delete[] p.a;
  p.a = new double[p.n];

  cout << "Введите коэффициенты от старшего к младшему:\n";
  for (int i = deg; i >= 0; i--)
    is >> p.a[i];

  return is;
}
