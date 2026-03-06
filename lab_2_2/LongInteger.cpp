#include "LongInteger.h"
#include <iostream>
using namespace std;

LongInteger::LongInteger() : size(1) {
  digits = new int[1];
  digits[0] = 0;
}

LongInteger::LongInteger(const LongInteger& other) : size(other.size) {
  digits = new int[size];
  for (int i = 0; i < size; i++)
    digits[i] = other.digits[i];
}

LongInteger::LongInteger(const string& s) {
  set(s);
}

LongInteger::~LongInteger() {
  delete[] digits;
}

LongInteger& LongInteger::operator=(const LongInteger& other) {
  if (this == &other) return *this;

  delete[] digits;

  size = other.size;
  digits = new int[size];
  for (int i = 0; i < size; i++)
    digits[i] = other.digits[i];

  return *this;
}

void LongInteger::set(const string& s) {
  // удаляем старые данные
  delete[] digits;

  size = s.size();
  digits = new int[size];

  // записываем цифры в обратном порядке
  for (int i = 0; i < size; i++) {
    digits[i] = s[size - 1 - i] - '0';
  }
}

void LongInteger::print() const {
  for (int i = size - 1; i >= 0; i--) {
    cout << digits[i];
  }
}
