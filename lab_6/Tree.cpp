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
