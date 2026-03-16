#pragma once
#include "Iterator.h"

template<typename T>
class Collection {
public:
  virtual void Add(const T& value) = 0;
  virtual bool Find(const T& value) const = 0;
  virtual bool Delete(const T& value) = 0;
  virtual void DeleteAll() = 0;
  virtual Iterator<T>* begin() const = 0;
  virtual Iterator<T>* end() const = 0;
  virtual ~Collection() = default;
};
