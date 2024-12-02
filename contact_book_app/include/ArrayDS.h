#ifndef ARRAYDS_H
#define ARRAYDS_H
#include <iostream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cassert>
template <typename T>
class ArrayDS {
private:
    T* array;
    int capacity;
    int size;

void resize() {
    capacity *= 2;
    T* newArray = new T[capacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    std::cout << "Resized array to new capacity: " << capacity << std::endl;
}

public:
    ArrayDS(int initialCapacity = 2) : capacity(initialCapacity), size(0) {
        assert(initialCapacity > 0 && "Capacity must be positive");
        array = new T[capacity];
    }

    ~ArrayDS() {
        delete[] array;
    }

    void add(const T& element) {
        if (size == capacity) {
            resize();
        }
        array[size++] = element;
    }

    void Delete(int index) {
        assert(index >= 0 && index < size && "Index out of range in Delete");
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    T& get(int index) {
        assert(index >= 0 && index < size && "Index out of range in get");
        return array[index];
    }

    const T& get(int index) const {
        assert(index >= 0 && index < size && "Index out of range in get");
        return array[index];
    }

    int getSize() const {
        return size;
    }

    T& operator[](int index) {
        return const_cast<T&>(get(index));
    }

    const T& operator[](int index) const {
        return get(index);
    }

    void reverse() {
        for (int i = 0; i < size / 2; ++i) {
            std::swap(array[i], array[size - i - 1]);
        }
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    std::swap(array[j], array[j + 1]);
                }
            }
        }
    }
    void clear() {
    delete[] array;
    array = new T[capacity];
    size = 0;
}

};
#endif // ARRAYDS_H
