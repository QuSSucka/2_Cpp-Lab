
files = {}

# ── Iterator.h ────────────────────────────────────────────────────────────────
files["Iterator.h"] = """\
#pragma once

class Iterator {
public:
    // Возвращает текущий элемент
    virtual double GetElem() const = 0;
    // true — текущая позиция валидна (есть что читать)
    virtual bool   IsNext()  const = 0;
    // Переход к следующему элементу
    virtual void   Next()          = 0;
    virtual ~Iterator() = default;
};
"""

# ── Collection.h ──────────────────────────────────────────────────────────────
files["Collection.h"] = """\
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
"""

# ── Vector.h ──────────────────────────────────────────────────────────────────
files["Vector.h"] = """\
#pragma once
#include "Collection.h"

class Vector : public Collection {
private:
    double* data;
    int     size;
    int     capacity;

    void resize();

public:
    Vector();
    ~Vector() override;

    void   Add(double value)        override;
    bool   Find(double value) const override;
    bool   Delete(double value)     override;
    void   DeleteAll()              override;

    int    getSize()      const;
    double getAt(int idx) const;

    // ── Итератор ────────────────────────────────────────────────────────────
    class VectorIterator : public Iterator {
        const Vector* vec;
        int           index;
    public:
        VectorIterator(const Vector* v, int idx);
        double GetElem() const override;
        bool   IsNext()  const override;
        void   Next()          override;
    };

    Iterator* begin() const override;
    Iterator* end()   const override;
};
"""

# ── Vector.cpp ────────────────────────────────────────────────────────────────
files["Vector.cpp"] = """\
#include "Vector.h"
#include <stdexcept>

// ── Vector ───────────────────────────────────────────────────────────────────
Vector::Vector() : size(0), capacity(4) {
    data = new double[capacity];
}

Vector::~Vector() { delete[] data; }

void Vector::resize() {
    capacity *= 2;
    double* nd = new double[capacity];
    for (int i = 0; i < size; ++i) nd[i] = data[i];
    delete[] data;
    data = nd;
}

void Vector::Add(double value) {
    if (size == capacity) resize();
    data[size++] = value;
}

bool Vector::Find(double value) const {
    for (int i = 0; i < size; ++i)
        if (data[i] == value) return true;
    return false;
}

bool Vector::Delete(double value) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            for (int j = i; j < size - 1; ++j) data[j] = data[j + 1];
            --size;
            return true;
        }
    }
    return false;
}

void Vector::DeleteAll() { size = 0; }

int    Vector::getSize()      const { return size;    }
double Vector::getAt(int idx) const { return data[idx]; }

Iterator* Vector::begin() const { return new VectorIterator(this, 0);    }
Iterator* Vector::end()   const { return new VectorIterator(this, size); }

// ── VectorIterator ────────────────────────────────────────────────────────────
Vector::VectorIterator::VectorIterator(const Vector* v, int idx)
    : vec(v), index(idx) {}

double Vector::VectorIterator::GetElem() const {
    if (index >= vec->getSize())
        throw std::out_of_range("VectorIterator: out of range");
    return vec->getAt(index);
}

bool Vector::VectorIterator::IsNext() const { return index < vec->getSize(); }
void Vector::VectorIterator::Next()         { if (index < vec->getSize()) ++index; }
"""

# ── Stack.h ───────────────────────────────────────────────────────────────────
files["Stack.h"] = """\
#pragma once
#include "Collection.h"

class Stack : public Collection {
private:
    struct Node {
        double value;
        Node*  next;
        Node(double v, Node* n = nullptr) : value(v), next(n) {}
    };

    Node* topNode;
    int   size;

public:
    Stack();
    ~Stack() override;

    void Add(double value)        override;
    bool Find(double value) const override;
    bool Delete(double value)     override;
    void DeleteAll()              override;

    // ── Итератор ────────────────────────────────────────────────────────────
    class StackIterator : public Iterator {
        Node* current;
    public:
        explicit StackIterator(Node* start);
        double GetElem() const override;
        bool   IsNext()  const override;
        void   Next()          override;
    };

    Iterator* begin() const override;
    Iterator* end()   const override;
};
"""

# ── Stack.cpp ─────────────────────────────────────────────────────────────────
files["Stack.cpp"] = """\
#include "Stack.h"
#include <stdexcept>

// ── Stack ────────────────────────────────────────────────────────────────────
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
    Node *curr = topNode, *prev = nullptr;
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

// ── StackIterator ─────────────────────────────────────────────────────────────
Stack::StackIterator::StackIterator(Node* start) : current(start) {}

double Stack::StackIterator::GetElem() const {
    if (!current) throw std::out_of_range("StackIterator: out of range");
    return current->value;
}

bool Stack::StackIterator::IsNext() const { return current != nullptr;         }
void Stack::StackIterator::Next()         { if (current) current = current->next; }
"""

# ── Tree.h ────────────────────────────────────────────────────────────────────
files["Tree.h"] = """\
#pragma once
#include "Collection.h"

class Tree : public Collection {
public:
    struct Node {
        double value;
        Node*  left;
        Node*  right;
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

    // ── DFS-итератор (обход в глубину, in-order) ────────────────────────────
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

    // ── BFS-итератор (обход в ширину, по уровням) ───────────────────────────
    class BFSIterator : public Iterator {
        Node** queue;
        int    head, tail, cap;
        double curVal;
        bool   valid;

        bool   empty()        const;
        void   enqueue(Node* n);
        Node*  dequeue();
        void   advance();

    public:
        explicit BFSIterator(Node* root);
        ~BFSIterator();
        double GetElem() const override;
        bool   IsNext()  const override;
        void   Next()          override;
    };

    Iterator* begin()    const override;   // DFS по умолчанию
    Iterator* end()      const override;
    Iterator* beginDFS() const;
    Iterator* beginBFS() const;
};
"""

# ── Tree.cpp ──────────────────────────────────────────────────────────────────
files["Tree.cpp"] = """\
#include "Tree.h"
#include <stdexcept>

// ── Tree ─────────────────────────────────────────────────────────────────────
Tree::Tree() : root(nullptr) {}
Tree::~Tree() { DeleteAll(); }

Tree::Node* Tree::insert(Node* n, double val) {
    if (!n) return new Node(val);
    if      (val < n->value) n->left  = insert(n->left,  val);
    else if (val > n->value) n->right = insert(n->right, val);
    return n;
}

bool Tree::findNode(Node* n, double val) const {
    if (!n) return false;
    if (val == n->value) return true;
    return val < n->value ? findNode(n->left, val) : findNode(n->right, val);
}

Tree::Node* Tree::minNode(Node* n) const {
    while (n->left) n = n->left;
    return n;
}

Tree::Node* Tree::deleteNode(Node* n, double val, bool& ok) {
    if (!n) return nullptr;
    if      (val < n->value) n->left  = deleteNode(n->left,  val, ok);
    else if (val > n->value) n->right = deleteNode(n->right, val, ok);
    else {
        ok = true;
        if (!n->left)  { Node* r = n->right; delete n; return r; }
        if (!n->right) { Node* l = n->left;  delete n; return l; }
        Node* mn = minNode(n->right);
        n->value = mn->value;
        bool dummy = false;
        n->right = deleteNode(n->right, mn->value, dummy);
    }
    return n;
}

void Tree::destroy(Node* n) {
    if (!n) return;
    destroy(n->left); destroy(n->right); delete n;
}

void Tree::Add(double value) { root = insert(root, value); }

bool Tree::Find(double value) const { return findNode(root, value); }

bool Tree::Delete(double value) {
    bool ok = false; root = deleteNode(root, value, ok); return ok;
}

void Tree::DeleteAll() { destroy(root); root = nullptr; }

Tree::Node* Tree::getRoot() const { return root; }

Iterator* Tree::begin()    const { return new DFSIterator(root);    }
Iterator* Tree::end()      const { return new DFSIterator(nullptr); }
Iterator* Tree::beginDFS() const { return new DFSIterator(root);    }
Iterator* Tree::beginBFS() const { return new BFSIterator(root);    }

// ── DFSIterator ───────────────────────────────────────────────────────────────
void Tree::DFSIterator::grow() {
    cap *= 2;
    Node** ns = new Node*[cap];
    for (int i = 0; i <= top; ++i) ns[i] = stack[i];
    delete[] stack; stack = ns;
}

void Tree::DFSIterator::pushLeft(Node* n) {
    while (n) { if (top == cap - 1) grow(); stack[++top] = n; n = n->left; }
}

void Tree::DFSIterator::advance() {
    if (top < 0) { valid = false; return; }
    Node* n = stack[top--];
    curVal = n->value; valid = true;
    pushLeft(n->right);
}

Tree::DFSIterator::DFSIterator(Node* r) : top(-1), cap(16), valid(false) {
    stack = new Node*[cap];
    pushLeft(r);
    advance();
}

Tree::DFSIterator::~DFSIterator() { delete[] stack; }

double Tree::DFSIterator::GetElem() const {
    if (!valid) throw std::out_of_range("DFSIterator: no element");
    return curVal;
}

bool Tree::DFSIterator::IsNext() const { return valid;    }
void Tree::DFSIterator::Next()         { advance();       }

// ── BFSIterator ───────────────────────────────────────────────────────────────
bool Tree::BFSIterator::empty() const { return head == tail; }

void Tree::BFSIterator::enqueue(Node* n) {
    if ((tail + 1) % cap == head) {        // расширить кольцевой буфер
        int nc = cap * 2;
        Node** nq = new Node*[nc];
        int cnt = 0;
        for (int i = head; i != tail; i = (i + 1) % cap) nq[cnt++] = queue[i];
        delete[] queue; queue = nq; head = 0; tail = cnt; cap = nc;
    }
    queue[tail] = n; tail = (tail + 1) % cap;
}

Tree::Node* Tree::BFSIterator::dequeue() {
    Node* n = queue[head]; head = (head + 1) % cap; return n;
}

void Tree::BFSIterator::advance() {
    if (empty()) { valid = false; return; }
    Node* n = dequeue();
    curVal = n->value; valid = true;
    if (n->left)  enqueue(n->left);
    if (n->right) enqueue(n->right);
}

Tree::BFSIterator::BFSIterator(Node* r) : head(0), tail(0), cap(16), valid(false) {
    queue = new Node*[cap];
    if (r) enqueue(r);
    advance();
}

Tree::BFSIterator::~BFSIterator() { delete[] queue; }

double Tree::BFSIterator::GetElem() const {
    if (!valid) throw std::out_of_range("BFSIterator: no element");
    return curVal;
}

bool Tree::BFSIterator::IsNext() const { return valid; }
void Tree::BFSIterator::Next()         { advance();    }
"""

# ── utils.h ───────────────────────────────────────────────────────────────────
files["utils.h"] = """\
#pragma once
#include "Iterator.h"

// Печатает все элементы через итератор и освобождает его
void printIter(const char* label, Iterator* it);
"""

# ── utils.cpp ─────────────────────────────────────────────────────────────────
files["utils.cpp"] = """\
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
    std::cout << (any ? "" : "(empty)") << "\\n";
    delete it;
}
"""

# ── main.cpp ──────────────────────────────────────────────────────────────────
files["main.cpp"] = """\
#include <iostream>
#include "Vector.h"
#include "Stack.h"
#include "Tree.h"
#include "utils.h"

int main() {
    // ===== Vector =====
    std::cout << "========== Vector ==========\\n";
    Vector vec;
    vec.Add(3.5); vec.Add(1.1); vec.Add(4.2); vec.Add(1.5); vec.Add(9.0);
    printIter("Elements     ", vec.begin());
    std::cout << "Find(4.2): " << (vec.Find(4.2) ? "yes" : "no") << "\\n";
    std::cout << "Find(7.0): " << (vec.Find(7.0) ? "yes" : "no") << "\\n";
    vec.Delete(4.2);
    printIter("Delete(4.2)  ", vec.begin());
    vec.DeleteAll();
    printIter("DeleteAll    ", vec.begin());

    // ===== Stack =====
    std::cout << "\\n========== Stack ==========\\n";
    Stack stk;
    stk.Add(10.0); stk.Add(20.0); stk.Add(30.0); stk.Add(40.0);
    printIter("Elements     ", stk.begin());
    std::cout << "Find(20.0): " << (stk.Find(20.0) ? "yes" : "no") << "\\n";
    stk.Delete(20.0);
    printIter("Delete(20.0) ", stk.begin());
    stk.DeleteAll();
    printIter("DeleteAll    ", stk.begin());

    // ===== Tree =====
    std::cout << "\\n========== Tree ==========\\n";
    //        5
    //       / \\
    //      3   7
    //     / \\ / \\
    //    1  4 6  8
    Tree tree;
    tree.Add(5.0); tree.Add(3.0); tree.Add(7.0);
    tree.Add(1.0); tree.Add(4.0); tree.Add(6.0); tree.Add(8.0);

    printIter("DFS in-order ", tree.beginDFS());  // 1 3 4 5 6 7 8
    printIter("BFS level    ", tree.beginBFS());  // 5 3 7 1 4 6 8
    std::cout << "Find(4.0): " << (tree.Find(4.0) ? "yes" : "no") << "\\n";
    std::cout << "Find(9.0): " << (tree.Find(9.0) ? "yes" : "no") << "\\n";
    tree.Delete(3.0);
    printIter("Del(3) DFS   ", tree.beginDFS());
    printIter("Del(3) BFS   ", tree.beginBFS());
    tree.DeleteAll();
    printIter("DeleteAll DFS", tree.beginDFS());

    return 0;
}
"""

# ── Makefile ──────────────────────────────────────────────────────────────────
files["Makefile"] = """\
CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET   = collection

SRCS = main.cpp Vector.cpp Stack.cpp Tree.cpp utils.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
\t$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
\t$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
\trm -f $(OBJS) $(TARGET)

.PHONY: all clean
"""

# Сохранить все файлы
import os
for fname, content in files.items():
    with open(fname, "w") as f:
        f.write(content)
    print(f"Written: {fname:20s}  ({len(content):5d} chars)")

print(f"\nTotal files: {len(files)}")
