#include "Vector.h"

namespace utilities {
template<typename T>
void Vector<T>::Extend(int size) {
    T *new_data = new T[size];
    for (int i = 0; i < size_; ++i) {
      new_data[i] = std::move(data_[i]);
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = size;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> &&other) {
    if (this == other) {
      return *this;
    }
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    this->data_ = other.data_;
    other.data_ = nullptr;
}
}  // namespace utilities
