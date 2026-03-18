#pragma once
#include "Iterator.h"
#include <ostream>
#include <memory>

void printIter(const char* label, Iterator* it);

std::ostream& operator<<(std::ostream& os, Iterator* it);
