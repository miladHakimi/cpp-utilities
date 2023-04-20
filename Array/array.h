#ifndef ARRAY_H
#define ARRAY_H

template<typename T, size_t N>
class Array {
 public:
    // using iterator = ArrayIterator<T>;
    Array() {
        data_ = new T[N];
    }

    // Copy constructor.
    Array(const Array &other) {
        data_ = new T[N];
        for (int i = 0; i < N; ++i) {
            data_[i] = other.data_[i];
        }
    }
    
    // Move constructor.
    Array(Array &&other) {
        data_ = other.data_;
        other.data_ = nullptr;
    }

    ~Array() {
        delete[] data_;
    }
    
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
        return data_;
    }

    // Copy assignment.
    Array &operator=(const Array &other) {
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
        data_ = other.data_;
        other.data_ = nullptr;
        return *this;
    }

 private:
    T *data_;
};

#endif  // ARRAY_H
