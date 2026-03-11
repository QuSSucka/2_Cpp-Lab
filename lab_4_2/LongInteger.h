#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <iostream>
#include <string>

class LongInteger {
private:
  int size;
  int* digits;
  bool negative;

  void removeLeadingZeros();

public:
  LongInteger();
  LongInteger(int value);
  LongInteger(const LongInteger& other);
  LongInteger(const std::string& s);
  ~LongInteger();

  void print() const;
  void set(const std::string& s);

  int getSize() const { return size; }
  int getDigit(int i) const { return digits[i]; }
  bool isNegative() const { return negative; }

  LongInteger& operator=(const LongInteger& other);

  LongInteger operator+(const LongInteger& other) const;
  LongInteger operator-(const LongInteger& other) const;

  LongInteger operator+(int value) const;
  LongInteger operator-(int value) const;

  LongInteger& operator++();
  LongInteger  operator++(int);
  LongInteger& operator--();
  LongInteger  operator--(int);

  bool operator==(const LongInteger& other) const;
  bool operator!=(const LongInteger& other) const;
  bool operator< (const LongInteger& other) const;
  bool operator<=(const LongInteger& other) const;
  bool operator> (const LongInteger& other) const;
  bool operator>=(const LongInteger& other) const;
};

std::ostream& operator<<(std::ostream& os, const LongInteger& li);
std::istream& operator>>(std::istream& is, LongInteger& li);

LongInteger operator+(int value, const LongInteger& li);
LongInteger operator-(int value, const LongInteger& li);

#endif
