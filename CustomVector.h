#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

#include <cstddef>       // For size_t
#include <stdexcept>     // For std::out_of_range exception

template <typename T>
class CustomVector {
private:
    T* data;
    size_t _size;
    size_t _capacity;

public:
    explicit CustomVector(size_t initial_capacity = 3);
    ~CustomVector();

    void push_back(const T& value);
    void pop_back();
    T& operator[](size_t index);
    T& at(size_t index);
    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t capacity() const;
    void resize(size_t new_capacity);

    [[nodiscard]] bool empty() const;
    void clear();
    T& front();
    T& back();
};

// Constructor
template <typename T>
CustomVector<T>::CustomVector(size_t initial_capacity)
    : _size(0), _capacity(initial_capacity) {
    data = new T[_capacity];
}

// Destructor
template <typename T>
CustomVector<T>::~CustomVector() {
    delete[] data;
}

// Add an element to the end of the vector
template <typename T>
void CustomVector<T>::push_back(const T& value) {
    if (_size == _capacity) {
        resize(_capacity * 2);  // Double the capacity if full
    }
    data[_size] = value;
    _size++;
}

// Remove the last element
template <typename T>
void CustomVector<T>::pop_back() {
    if (_size > 0) {
        _size--;
    }
}

// Access element at a specific index with no bounds checking
template <typename T>
T& CustomVector<T>::operator[](size_t index) {
    return data[index];
}

// Access element at a specific index with bounds checking
template <typename T>
T& CustomVector<T>::at(size_t index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Get the current size (number of elements)
template <typename T>
size_t CustomVector<T>::size() const {
    return _size;
}

// Get the current capacity (allocated memory)
template <typename T>
size_t CustomVector<T>::capacity() const {
    return _capacity;
}

// Resize the vector to a new capacity
template <typename T>
void CustomVector<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < _size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    _capacity = new_capacity;
}

// Check if the vector is empty
template <typename T>
bool CustomVector<T>::empty() const {
    return _size == 0;
}

// Clear all elements in the vector
template <typename T>
void CustomVector<T>::clear() {
    _size = 0;
}

// Get the first element
template <typename T>
T& CustomVector<T>::front() {
    if (_size == 0) throw std::out_of_range("Vector is empty");
    return data[0];
}

// Get the last element
template <typename T>
T& CustomVector<T>::back() {
    if (_size == 0) throw std::out_of_range("Vector is empty");
    return data[_size - 1];
}

#endif // CUSTOMVECTOR_H
