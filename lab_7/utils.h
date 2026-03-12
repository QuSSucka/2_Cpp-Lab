#pragma once
#include <iostream>
#include "Iterator.h"

// Печатает все элементы через итератор и освобождает его
template<typename T>
void printIter(const char* label, Iterator<T>* it) {
  std::cout << label << ": ";
  bool any = false;
  while (it->IsNext()) {
    if (any) std::cout << "  ";
    std::cout << it->GetElem();
    any = true;
    it->Next();
  }
  std::cout << (any ? "" : "(empty)") << "\n";
  delete it;
}
