#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <string>

class LongInteger {
private:
  int size;
  int* digits;

public:
  LongInteger();
  LongInteger(const LongInteger& other);
  LongInteger(const std::string& s);
  ~LongInteger();

  void print() const;
  void set(const std::string& s);

  LongInteger& operator=(const LongInteger& other);
};

#endif
