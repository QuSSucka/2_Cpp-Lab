#ifndef POLINOM_H
#define POLINOM_H

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

  void print() const;
  double value(double x) const;

  void read();

  Polinom& operator=(const Polinom& other);
};

#endif
