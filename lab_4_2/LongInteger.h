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

  friend std::ostream& operator<<(std::ostream& os, const LongInteger& li);
  friend std::istream& operator>>(std::istream& is, LongInteger& li);

  friend LongInteger operator+(int value, const LongInteger& li);
  friend LongInteger operator-(int value, const LongInteger& li);
};

#endif
