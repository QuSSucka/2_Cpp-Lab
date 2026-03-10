#pragma once
#include "Collection.h"
#include <stdexcept>

template<typename T>
class Vector : public Collection<T> {
private:
    T*  data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        T* nd = new T[capacity];
        for (int i = 0; i < size; ++i) nd[i] = data[i];
        delete[] data;
        data = nd;
    }

public:
    Vector() : size(0), capacity(4) { data = new T[capacity]; }
    ~Vector() override { delete[] data; }
    Vector(const Vector&)            = delete;
    Vector& operator=(const Vector&) = delete;

    void Add(const T& value) override {
        if (size == capacity) resize();
        data[size++] = value;
    }

    bool Find(const T& value) const override {
        for (int i = 0; i < size; ++i)
            if (data[i] == value) return true;
        return false;
    }

    bool Delete(const T& value) override {
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                for (int j = i; j < size - 1; ++j) data[j] = data[j + 1];
                --size;
                return true;
            }
        }
        return false;
    }

    void     DeleteAll()      override { size = 0; }
    int      getSize()        const    { return size;      }
    const T& getAt(int idx)   const    { return data[idx]; }

    // ── Итератор ────────────────────────────────────────────────────────────
    class VectorIterator : public Iterator<T> {
        const Vector<T>* vec;
        int              index;
    public:
        VectorIterator(const Vector<T>* v, int idx) : vec(v), index(idx) {}

        T GetElem() const override {
            if (index >= vec->getSize())
                throw std::out_of_range("VectorIterator: out of range");
            return vec->getAt(index);
        }
        bool IsNext() const override { return index < vec->getSize(); }
        void Next()         override { if (index < vec->getSize()) ++index; }
    };

    Iterator<T>* begin() const override { return new VectorIterator(this, 0);    }
    Iterator<T>* end()   const override { return new VectorIterator(this, size); }
};
