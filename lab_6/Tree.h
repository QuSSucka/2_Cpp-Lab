#pragma once
#include "Collection.h"

class Tree : public Collection {
public:
  struct Node {
    double value;
    Node* left;
    Node* right;
    Node(double v) : value(v), left(nullptr), right(nullptr) {}
  };

private:
  Node* root;

  Node* insert(Node* n, double val);
  bool  findNode(Node* n, double val) const;
  Node* minNode(Node* n) const;
  Node* deleteNode(Node* n, double val, bool& ok);
  void  destroy(Node* n);

public:
  Tree();
  ~Tree() override;

  void Add(double value)        override;
  bool Find(double value) const override;
  bool Delete(double value)     override;
  void DeleteAll()              override;

  Node* getRoot() const;

  class DFSIterator : public Iterator {
    Node** stack;
    int    top, cap;
    double curVal;
    bool   valid;

    void   grow();
    void   pushLeft(Node* n);
    void   advance();

  public:
    explicit DFSIterator(Node* root);
    ~DFSIterator();
    double GetElem() const override;
    bool   IsNext()  const override;
    void   Next()          override;
  };

  class BFSIterator : public Iterator {
    Node** queue;
    int    head, tail, cap;
    double curVal;
    bool   valid;

    bool   empty()        const;
    void   enqueue(Node* n);
    Node* dequeue();
    void   advance();

  public:
    explicit BFSIterator(Node* root);
    ~BFSIterator();
    double GetElem() const override;
    bool   IsNext()  const override;
    void   Next()          override;
  };

  Iterator* begin()    const override;
  Iterator* end()      const override;
  Iterator* beginDFS() const;
  Iterator* beginBFS() const;
};
