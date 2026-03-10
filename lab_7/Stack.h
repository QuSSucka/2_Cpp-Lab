#pragma once
#include "Collection.h"
#include <stdexcept>

template<typename T>
class Stack : public Collection<T> {
private:
    struct Node {
        T     value;
        Node* next;
        Node(const T& v, Node* n = nullptr) : value(v), next(n) {}
    };
    Node* topNode;
    int   size;

public:
    Stack() : topNode(nullptr), size(0) {}
    ~Stack() override { DeleteAll(); }
    Stack(const Stack&)            = delete;
    Stack& operator=(const Stack&) = delete;

    void Add(const T& value) override {
        topNode = new Node(value, topNode);
        ++size;
    }

    bool Find(const T& value) const override {
        for (Node* n = topNode; n; n = n->next)
            if (n->value == value) return true;
        return false;
    }

    bool Delete(const T& value) override {
        Node *curr = topNode, *prev = nullptr;
        while (curr) {
            if (curr->value == value) {
                (prev ? prev->next : topNode) = curr->next;
                delete curr; --size;
                return true;
            }
            prev = curr; curr = curr->next;
        }
        return false;
    }

    void DeleteAll() override {
        while (topNode) { Node* t = topNode; topNode = topNode->next; delete t; }
        size = 0;
    }

    // ── Итератор ────────────────────────────────────────────────────────────
    class StackIterator : public Iterator<T> {
        Node* current;
    public:
        explicit StackIterator(Node* start) : current(start) {}

        T GetElem() const override {
            if (!current) throw std::out_of_range("StackIterator: out of range");
            return current->value;
        }
        bool IsNext() const override { return current != nullptr;            }
        void Next()         override { if (current) current = current->next; }
    };

    Iterator<T>* begin() const override { return new StackIterator(topNode); }
    Iterator<T>* end()   const override { return new StackIterator(nullptr); }
};
