#pragma once
#include "Collection.h"
#include <stdexcept>

// Требование к T: операторы <, >, ==
template<typename T>
class Tree : public Collection<T> {
public:
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
  };

private:
  Node* root;

  Node* insert(Node* n, const T& val) {
    if (!n) return new Node(val);
    if (val < n->value) n->left = insert(n->left, val);
    else if (val > n->value) n->right = insert(n->right, val);
    return n;
  }

  bool findNode(Node* n, const T& val) const {
    if (!n) return false;
    if (val == n->value) return true;
    return val < n->value ? findNode(n->left, val) : findNode(n->right, val);
  }

  Node* minNode(Node* n) const { while (n->left) n = n->left; return n; }

  Node* deleteNode(Node* n, const T& val, bool& ok) {
    if (!n) return nullptr;
    if (val < n->value) n->left = deleteNode(n->left, val, ok);
    else if (val > n->value) n->right = deleteNode(n->right, val, ok);
    else {
      ok = true;
      if (!n->left) { Node* r = n->right; delete n; return r; }
      if (!n->right) { Node* l = n->left; delete n; return l; }
      Node* mn = minNode(n->right);
      n->value = mn->value;
      bool dummy = false;
      n->right = deleteNode(n->right, mn->value, dummy);
    }
    return n;
  }

  void destroy(Node* n) {
    if (!n) return;
    destroy(n->left); destroy(n->right); delete n;
  }

public:
  Tree() : root(nullptr) {}
  ~Tree() override { DeleteAll(); }
  Tree(const Tree&) = delete;
  Tree& operator=(const Tree&) = delete;

  void Add(const T& value) override { root = insert(root, value); }
  bool Find(const T& value) const override { return findNode(root, value); }
  bool Delete(const T& value) override {
    bool ok = false; root = deleteNode(root, value, ok); return ok;
  }
  void  DeleteAll() override { destroy(root); root = nullptr; }
  Node* getRoot() const { return root; }

  class DFSIterator : public Iterator<T> {
    Node** stack;
    int top, cap;
    T curVal;
    bool valid;

    void grow() {
      cap *= 2; Node** ns = new Node * [cap];
      for (int i = 0; i <= top; ++i) ns[i] = stack[i];
      delete[] stack; stack = ns;
    }
    void pushLeft(Node* n) {
      while (n) { if (top == cap - 1) grow(); stack[++top] = n; n = n->left; }
    }
    void advance() {
      if (top < 0) { valid = false; return; }
      Node* n = stack[top--];
      curVal = n->value; valid = true;
      pushLeft(n->right);
    }
  public:
    explicit DFSIterator(Node* r) : top(-1), cap(16), valid(false) {
      stack = new Node * [cap]; pushLeft(r); advance();
    }
    ~DFSIterator() { delete[] stack; }

    T GetElem() const override {
      if (!valid) throw std::out_of_range("DFSIterator: no element");
      return curVal;
    }
    bool IsNext() const override { return valid; }
    void Next() override { advance(); }
  };

  class BFSIterator : public Iterator<T> {
    Node** queue;
    int head, tail, cap;
    T curVal;
    bool valid;

    bool  isEmpty()        const { return head == tail; }
    void  enqueue(Node* n) {
      if ((tail + 1) % cap == head) {
        int nc = cap * 2; Node** nq = new Node * [nc]; int cnt = 0;
        for (int i = head; i != tail; i = (i + 1) % cap) nq[cnt++] = queue[i];
        delete[] queue; queue = nq; head = 0; tail = cnt; cap = nc;
      }
      queue[tail] = n; tail = (tail + 1) % cap;
    }
    Node* dequeue() { Node* n = queue[head]; head = (head + 1) % cap; return n; }
    void  advance() {
      if (isEmpty()) { valid = false; return; }
      Node* n = dequeue(); curVal = n->value; valid = true;
      if (n->left)  enqueue(n->left);
      if (n->right) enqueue(n->right);
    }
  public:
    explicit BFSIterator(Node* r) : head(0), tail(0), cap(16), valid(false) {
      queue = new Node * [cap]; if (r) enqueue(r); advance();
    }
    ~BFSIterator() { delete[] queue; }

    T GetElem() const override {
      if (!valid) throw std::out_of_range("BFSIterator: no element");
      return curVal;
    }
    bool IsNext() const override { return valid; }
    void Next() override { advance(); }
  };

  Iterator<T>* begin() const override { return new DFSIterator(root); }
  Iterator<T>* end() const override { return new DFSIterator(nullptr); }
  Iterator<T>* beginDFS() const { return new DFSIterator(root); }
  Iterator<T>* beginBFS() const { return new BFSIterator(root); }
};
