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
