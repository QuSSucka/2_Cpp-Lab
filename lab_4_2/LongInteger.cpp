#include "LongInteger.h"
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Сравнение абсолютных значений: -1, 0, 1
static int cmpAbs(const int* a, int sa, const int* b, int sb) {
  if (sa != sb) return sa > sb ? 1 : -1;
  for (int i = sa - 1; i >= 0; i--) {
    if (a[i] != b[i]) return a[i] > b[i] ? 1 : -1;
  }
  return 0;
}

// |a| + |b|, результат в новый массив (размер max(sa,sb)+1)
static void addAbs(const int* a, int sa, const int* b, int sb,
  int*& res, int& sr) {
  sr = max(sa, sb) + 1;
  res = new int[sr]();
  int carry = 0;
  for (int i = 0; i < sr; i++) {
    int sum = carry;
    if (i < sa) sum += a[i];
    if (i < sb) sum += b[i];
    res[i] = sum % 10;
    carry = sum / 10;
  }
}

// |a| - |b|, предполагается |a| >= |b|
static void subAbs(const int* a, int sa, const int* b, int sb,
  int*& res, int& sr) {
  sr = sa;
  res = new int[sr]();
  int borrow = 0;
  for (int i = 0; i < sr; i++) {
    int diff = (i < sa ? a[i] : 0) - (i < sb ? b[i] : 0) - borrow;
    if (diff < 0) { diff += 10; borrow = 1; }
    else            borrow = 0;
    res[i] = diff;
  }
}

void LongInteger::removeLeadingZeros() {
  while (size > 1 && digits[size - 1] == 0)
    size--;
  if (size == 1 && digits[0] == 0)
    negative = false;
}

// конструкторы / деструктор

LongInteger::LongInteger() : size(1), negative(false) {
  digits = new int[1]();
}

LongInteger::LongInteger(int value) : negative(value < 0) {
  string s = to_string(abs(value));
  size = s.size();
  digits = new int[size];
  for (int i = 0; i < size; i++)
    digits[i] = s[size - 1 - i] - '0';
}

LongInteger::LongInteger(const LongInteger& other)
  : size(other.size), negative(other.negative) {
  digits = new int[size];
  for (int i = 0; i < size; i++)
    digits[i] = other.digits[i];
}

LongInteger::LongInteger(const string& s) : digits(nullptr), size(0), negative(false) {
  set(s);
}

LongInteger::~LongInteger() {
  delete[] digits;
}

// set / print

void LongInteger::set(const string& s) {
  delete[] digits;
  int start = 0;
  negative = false;
  if (!s.empty() && s[0] == '-') { negative = true; start = 1; }
  else if (!s.empty() && s[0] == '+') { start = 1; }

  size = (int)s.size() - start;
  if (size <= 0) { size = 1; digits = new int[1](); negative = false; return; }
  digits = new int[size];
  for (int i = 0; i < size; i++)
    digits[i] = s[s.size() - 1 - i] - '0';
  removeLeadingZeros();
}

void LongInteger::print() const {
  if (negative) cout << '-';
  for (int i = size - 1; i >= 0; i--)
    cout << digits[i];
}

// operator=

LongInteger& LongInteger::operator=(const LongInteger& other) {
  if (this == &other) return *this;
  delete[] digits;
  size = other.size;
  negative = other.negative;
  digits = new int[size];
  for (int i = 0; i < size; i++)
    digits[i] = other.digits[i];
  return *this;
}

// сложение / вычитание

LongInteger LongInteger::operator+(const LongInteger& other) const {
  LongInteger result;
  delete[] result.digits;

  if (negative == other.negative) {
    // одинаковые знаки — складываем абсолютные значения
    addAbs(digits, size, other.digits, other.size,
      result.digits, result.size);
    result.negative = negative;
  }
  else {
    // разные знаки — вычитаем меньшее из большего
    int cmp = cmpAbs(digits, size, other.digits, other.size);
    if (cmp == 0) {
      result.digits = new int[1](); result.size = 1; result.negative = false;
    }
    else if (cmp > 0) {
      subAbs(digits, size, other.digits, other.size,
        result.digits, result.size);
      result.negative = negative;
    }
    else {
      subAbs(other.digits, other.size, digits, size,
        result.digits, result.size);
      result.negative = other.negative;
    }
  }
  result.removeLeadingZeros();
  return result;
}

LongInteger LongInteger::operator-(const LongInteger& other) const {
  LongInteger tmp(other);
  tmp.negative = !other.negative;
  if (tmp.size == 1 && tmp.digits[0] == 0) tmp.negative = false;
  return *this + tmp;
}

// 2) LongInteger ± int
LongInteger LongInteger::operator+(int value) const { return *this + LongInteger(value); }
LongInteger LongInteger::operator-(int value) const { return *this - LongInteger(value); }

// 3) int ± LongInteger (дружественные)
LongInteger operator+(int value, const LongInteger& li) { return LongInteger(value) + li; }
LongInteger operator-(int value, const LongInteger& li) { return LongInteger(value) - li; }

// инкремент / декремент

LongInteger& LongInteger::operator++() { *this = *this + 1; return *this; }
LongInteger  LongInteger::operator++(int) { LongInteger tmp(*this); ++(*this); return tmp; }
LongInteger& LongInteger::operator--() { *this = *this - 1; return *this; }
LongInteger  LongInteger::operator--(int) { LongInteger tmp(*this); --(*this); return tmp; }

// сравнения

bool LongInteger::operator==(const LongInteger& o) const {
  if (negative != o.negative) return false;
  if (size != o.size) return false;
  for (int i = 0; i < size; i++)
    if (digits[i] != o.digits[i]) return false;
  return true;
}
bool LongInteger::operator!=(const LongInteger& o) const { return !(*this == o); }
bool LongInteger::operator<(const LongInteger& o) const {
  if (negative != o.negative) return negative; // отрицательное < положительного
  int cmp = cmpAbs(digits, size, o.digits, o.size);
  return negative ? (cmp > 0) : (cmp < 0);
}
bool LongInteger::operator<=(const LongInteger& o) const { return !(o < *this); }
bool LongInteger::operator>(const LongInteger& o) const { return o < *this; }
bool LongInteger::operator>=(const LongInteger& o) const { return !(*this < o); }

// << и >>

ostream& operator<<(ostream& os, const LongInteger& li) {
  if (li.negative) os << '-';
  for (int i = li.size - 1; i >= 0; i--)
    os << li.digits[i];
  return os;
}

istream& operator>>(istream& is, LongInteger& li) {
  string s;
  is >> s;
  li.set(s);
  return is;
}
