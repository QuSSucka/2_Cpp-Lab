#pragma once
#include "Iterator.h"

class Collection {
public:
    virtual void      Add(double value)        = 0;
    virtual bool      Find(double value) const = 0;
    virtual bool      Delete(double value)     = 0;
    virtual void      DeleteAll()              = 0;
    virtual Iterator* begin() const            = 0;  // итератор на первый элемент
    virtual Iterator* end()   const            = 0;  // итератор "за последним"
    virtual ~Collection() = default;
};
