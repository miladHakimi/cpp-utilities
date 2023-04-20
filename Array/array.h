#ifndef ARRAY_H
#define ARRAY_H

#include <memory>

template<typename T, size_t N>
class Array {
 public:
    Array(): data_(std::make_unique<T[]>(N)) {}

    // Copy constructor.
    Array(const Array &other):  data_(std::make_unique<T[]>(N)) {
        for (int i = 0; i < N; ++i) {
            data_[i] = other.data_[i];
        }
    }
    
    // Move constructor.
    Array(Array &&other) {
        data_ = std::move(other.data_);
        assert(other.data_ == nullptr);
    }

    ~Array() = default;
    
    size_t Size() const {
        return N;
    }

    T& operator[](size_t index) {
        return data_[index];
    }
    
    const T& operator[](size_t index) const {
        return data_[index];
    }

    T* Data() {
        return data_.get();
    }

    // Copy assignment.
    Array &operator=(const Array &other) {
        assert(N == other.Size());
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < N; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }

    // Move assignment.
    Array operator=(Array &&other) {
        if (this == &other) {
            return *this;
        }
        data_ = std::move(other.data_);
        assert(other.data_ == nullptr);
        return *this;
    }

 private:
    std::unique_ptr<T[]> data_;
};

#endif  // ARRAY_H
