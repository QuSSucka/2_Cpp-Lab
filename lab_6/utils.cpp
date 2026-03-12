#include "utils.h"
#include <iostream>

void printIter(const char* label, Iterator* it) {
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
