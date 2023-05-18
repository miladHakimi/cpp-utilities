#ifndef __ITERATOR_H__
#define __ITERATOR_H__

template <typename T>
class GenericIterator {
 public:
    GenericIterator(T *ptr) : ptr_(ptr) {}

    virtual ~GenericIterator() = default;

    // virtual GenericIterator operator++() = 0;

    // virtual GenericIterator operator++(int) = 0;

    virtual bool operator!=(const GenericIterator &other) {
        return !(*this == other);
    }

    virtual bool operator==(const GenericIterator &other) {
        return ptr_ == other.ptr_;
    };

    T &operator*() {
        return *ptr_;
    }
//  protected:
    T *ptr_;
};

#endif  // __ITERATOR_H__