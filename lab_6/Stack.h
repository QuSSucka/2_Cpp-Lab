#pragma once
#include "Collection.h"

class Stack : public Collection {
private:
  struct Node {
    double value;
    Node* next;
    Node(double v, Node* n = nullptr) : value(v), next(n) {}
  };

  Node* topNode;
  int size;

public:
  Stack();
  ~Stack() override;

  void Add(double value) override;
  bool Find(double value) const override;
  bool Delete(double value) override;
  void DeleteAll() override;

  class StackIterator : public Iterator {
    Node* current;
  public:
    explicit StackIterator(Node* start);
    double GetElem() const override;
    bool IsNext() const override;
    void Next() override;
  };

  Iterator* begin() const override;
  Iterator* end() const override;
};
