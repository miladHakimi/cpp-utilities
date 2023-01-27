#ifndef VECTOR_VECTOR_H_
#define VECTOR_VECTOR_H_

#include <iostream>

namespace utilities {

// This class defines the traversal, comparison, and dereference behaviors of an
// iterator for the Vector class so that it can be used in a range-based for
// loop.
// Example:
// Vector<int> my_vector(10);
// for (int &num: my_vector)
//  num = 1;
template <typename T>
class VectorIterator {
 public:
  VectorIterator(T *ptr) : ptr_(ptr) {}
  VectorIterator &operator++() {
    ptr_++;
    return *this;
  }

  VectorIterator operator++(int) {
    VectorIterator tmp = *this;
    ++*this;
    return tmp;
  }

  bool operator!=(const VectorIterator &other) const {
    return ptr_ != other.ptr_;
  }

  bool operator==(const VectorIterator &other) const {
    return ptr_ == other.ptr_;
  }

  T &operator*() { return *ptr_; }

 private:
  T *ptr_;
};

// This class is a container for contigious elements in memory of various types,
// like std::vector. It currently does not support shrinking properly.
template <typename T>
class Vector {
 public:
  using iterator = VectorIterator<T>;

  Vector(int size = 0) : size_(size), capacity_(size + 1) {
    data_ = new T[capacity_];
  }

  void Extend(int size);

  void PushBack(T &value) {
    if (size_ == capacity_) {
      Extend(capacity_ * 2);
    }
    data_[size_++] = value;
  }

  void PushBack(T &&value) {
    if (size_ == capacity_) {
      Extend(capacity_ * 2);
    }
    data_[size_++] = std::move(value);
  }

  template <typename... Args>
  void EmplaceBack(Args &&...args) {
    if (size_ == capacity_) {
      Extend(capacity_ * 2);
    }
    new (&data_[size_++]) T(std::forward<Args>(args)...);
  }

  // Copy assignment.
  Vector &operator=(Vector &other) {
    if (this == &other) {
      return *this;
    }
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    for (int i = 0; i < size_; ++i) {
      this->data_[i] = other.data_[i];
    }
    return *this;
  }

  // Move assignment.
  Vector& operator=(Vector &&other);

  T &operator[](int index) { return data_[index]; }

  const T &operator[](int index) const { return data_[index]; }

  size_t Size() const { return size_; }

  void Clear() {
    for (int i = 0; i < size_; ++i) {
      data_[i].~T();
    }
    data_ = nullptr;
    size_ = 0;
  }

  void Pop() {
    if (size_ == 0) return;
    data_[--size_].~T();
  }

  T &Back() { return data_[size_ - 1]; }

  iterator begin() { return data_; }

  iterator end() { return data_ + size_; }

  ~Vector() {
    Clear();
    delete[] data_;
  }

 private:
  T *data_;
  int size_;
  int capacity_;
};
}  // namespace utilities

#endif  // VECTOR_VECTOR_H_
