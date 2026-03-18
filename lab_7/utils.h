#pragma once
#include <iostream>
#include <memory>
#include "Iterator.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, Iterator<T>* it) {
  std::unique_ptr<Iterator<T>> up(it);
  bool any = false;
  while (up->IsNext()) {
    if (any) os << "  ";
    os << up->GetElem();
    any = true;
    up->Next();
  }
  if (!any) os << "(empty)";
  return os;
}
