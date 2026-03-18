#include "utils.h"
#include <iostream>
#include <memory>

void printIter(const char* label, Iterator* it) {
  std::unique_ptr<Iterator> up(it);
  std::cout << label << ": ";
  bool any = false;
  while (up->IsNext()) {
    if (any) std::cout << "  ";
    std::cout << up->GetElem();
    any = true;
    up->Next();
  }
  std::cout << (any ? "" : "(empty)") << "\n";
}

std::ostream& operator<<(std::ostream& os, Iterator* it) {
  std::unique_ptr<Iterator> up(it);
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
