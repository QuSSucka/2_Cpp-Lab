#pragma once
#include "Collection.h"

class Vector : public Collection {
private:
  double* data;
  int     size;
  int     capacity;

  void resize();

public:
  Vector();
  ~Vector() override;

  void   Add(double value)        override;
  bool   Find(double value) const override;
  bool   Delete(double value)     override;
  void   DeleteAll()              override;

  int    getSize()      const;
  double getAt(int idx) const;

  class VectorIterator : public Iterator {
    const Vector* vec;
    int           index;
  public:
    VectorIterator(const Vector* v, int idx);
    double GetElem() const override;
    bool   IsNext()  const override;
    void   Next()          override;
  };

  Iterator* begin() const override;
  Iterator* end()   const override;
};
