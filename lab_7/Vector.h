#pragma once
#include "Collection.h"
#include <stdexcept>

template<typename T>
class Vector : public Collection<T> {
private:
  T* data;
  int size;
  int capacity;

  void resize();

public:
  Vector();
  ~Vector() override;
  Vector(const Vector&) = delete;
  Vector& operator=(const Vector&) = delete;

  void Add(const T& value) override;
  bool Find(const T& value) const override;
  bool Delete(const T& value) override;
  void     DeleteAll()      override;
  int      getSize()        const;
  const T& getAt(int idx)   const;

  class VectorIterator : public Iterator<T> {
    const Vector<T>* vec;
    int              index;
  public:
    VectorIterator(const Vector<T>* v, int idx);

    T GetElem() const override;
    bool IsNext() const override;
    void Next()         override;
  };

  VectorIterator* begin() const override;
  VectorIterator* end()   const override;
};

template<typename T>
void Vector<T>::resize() {
  capacity *= 2;
  T* nd = new T[capacity];
  for (int i = 0; i < size; ++i) nd[i] = data[i];
  delete[] data;
  data = nd;
}

template<typename T>
Vector<T>::Vector() : size(0), capacity(4) {
  data = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
  delete[] data;
}

template<typename T>
void Vector<T>::Add(const T& value) {
  if (size == capacity) resize();
  data[size++] = value;
}

template<typename T>
bool Vector<T>::Find(const T& value) const {
  for (int i = 0; i < size; ++i)
    if (data[i] == value) return true;
  return false;
}

template<typename T>
bool Vector<T>::Delete(const T& value) {
  for (int i = 0; i < size; ++i) {
    if (data[i] == value) {
      for (int j = i; j < size - 1; ++j) data[j] = data[j + 1];
      --size;
      return true;
    }
  }
  return false;
}

template<typename T>
void Vector<T>::DeleteAll() {
  size = 0;
}

template<typename T>
int Vector<T>::getSize() const { return size; }

template<typename T>
const T& Vector<T>::getAt(int idx) const { return data[idx]; }

template<typename T>
Vector<T>::VectorIterator::VectorIterator(const Vector<T>* v, int idx)
  : vec(v), index(idx) {
}

template<typename T>
T Vector<T>::VectorIterator::GetElem() const {
  if (index >= vec->getSize())
    throw std::out_of_range("VectorIterator: out of range");
  return vec->getAt(index);
}

template<typename T>
bool Vector<T>::VectorIterator::IsNext() const { return index < vec->getSize(); }

template<typename T>
void Vector<T>::VectorIterator::Next() { if (index < vec->getSize()) ++index; }

template<typename T>
typename Vector<T>::VectorIterator* Vector<T>::begin() const {
  return new VectorIterator(this, 0);
}

template<typename T>
typename Vector<T>::VectorIterator* Vector<T>::end() const {
  return new VectorIterator(this, size);
}