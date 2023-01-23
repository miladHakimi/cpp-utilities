#ifndef VECTOR_VECTOR_H_
#define VECTOR_VECTOR_H_

#include <iostream>

template <typename T>
class VectorIterator
{
public:
  VectorIterator(T *ptr) : ptr_(ptr) {}
  VectorIterator &operator++()
  {
    ptr_++;
    return *this;
  }

  VectorIterator operator++(int)
  {
    VectorIterator tmp = *this;
    ++*this;
    return tmp;
  }

  bool operator!=(const VectorIterator &other) const
  {
    return ptr_ != other.ptr_;
  }

  bool operator==(const VectorIterator &other) const
  {
    return ptr_ == other.ptr_;
  }

  T &operator*()
  {
    return *ptr_;
  }

private:
  T *ptr_;
};

template <typename T>
class Vector
{
public:
  using iterator = VectorIterator<T>;

  Vector(int size = 0) : size_(size), capacity_(size + 1)
  {
    data_ = new T[capacity_];
  }

  void Extend(int size)
  {
    T *new_data = new T[size];
    for (int i = 0; i < size_; ++i)
    {
      new_data[i] = std::move(data_[i]);
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = size;
  }

  void PushBack(T &value)
  {
    if (size_ == capacity_)
    {
      Extend(capacity_ * 2);
    }
    data_[size_++] = value;
  }

  void PushBack(T &&value)
  {
    if (size_ == capacity_)
    {
      Extend(capacity_ * 2);
    }
    data_[size_++] = std::move(value);
  }

  template <typename... Args>
  void EmplaceBack(Args &&...args)
  {
    if (size_ == capacity_)
    {
      Extend(capacity_ * 2);
    }
    new (&data_[size_++]) T(std::forward<Args>(args)...);
  }

  Vector &operator=(Vector other)
  {
    std::cout << "Copy assignment" << std::endl;
    if (this == other)
    {
      return *this;
    }
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    for (int i = 0; i < size_; ++i)
    {
      this->data_[i] = other.data_[i];
    }
  }

  Vector &operator=(Vector &&other)
  {
    std::cout << "Move assignment" << std::endl;
    if (this == other)
    {
      return *this;
    }
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    this->data_ = other.data_;
    other.data_ = nullptr;
  }

  T &operator[](int index)
  {
    return data_[index];
  }

  const T &operator[](int index) const
  {
    return data_[index];
  }

  size_t Size() const
  {
    return size_;
  }

  void Clear()
  {
    for (int i = 0; i < size_; ++i)
    {
      data_[i].~T();
    }
    data_ = nullptr;
    size_ = 0;
  }

  void Pop()
  {
    if (size_ == 0)
      return;
    data_[--size_].~T();
  }

  T &Back()
  {
    return data_[size_ - 1];
  }

  iterator begin()
  {
    return data_;
  }

  iterator end()
  {
    return data_ + size_;
  }

  ~Vector()
  {
    Clear();
    delete[] data_;
  }

private:
  T *data_;
  int size_;
  int capacity_;
};

#endif // VECTOR_VECTOR_H_