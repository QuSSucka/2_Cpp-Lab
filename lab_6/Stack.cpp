#include "Stack.h"
#include <stdexcept>

Stack::Stack() : topNode(nullptr), size(0) {}

Stack::~Stack() { DeleteAll(); }

void Stack::Add(double value) {
  topNode = new Node(value, topNode);
  ++size;
}

bool Stack::Find(double value) const {
  for (Node* n = topNode; n; n = n->next)
    if (n->value == value) return true;
  return false;
}

bool Stack::Delete(double value) {
  Node* curr = topNode, * prev = nullptr;
  while (curr) {
    if (curr->value == value) {
      (prev ? prev->next : topNode) = curr->next;
      delete curr;
      --size;
      return true;
    }
    prev = curr; curr = curr->next;
  }
  return false;
}

void Stack::DeleteAll() {
  while (topNode) { Node* t = topNode; topNode = topNode->next; delete t; }
  size = 0;
}

Iterator* Stack::begin() const { return new StackIterator(topNode); }
Iterator* Stack::end()   const { return new StackIterator(nullptr); }

Stack::StackIterator::StackIterator(Node* start) : current(start) {}

double Stack::StackIterator::GetElem() const {
  if (!current) throw std::out_of_range("StackIterator: out of range");
  return current->value;
}

bool Stack::StackIterator::IsNext() const { return current != nullptr; }
void Stack::StackIterator::Next() { if (current) current = current->next; }
