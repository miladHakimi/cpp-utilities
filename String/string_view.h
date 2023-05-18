#ifndef STRING_VIEW_H
#define STRING_VIEW_H

#include <string>

namespace utilities {

class StringView {
 public:
    StringView(const char *data) : data_(data), size_(strlen(data)) {}
    
    StringView(const std::string &str) : data_(str.data()), size_(str.size()) {}
    
    StringView(const StringView &other) : data_(other.data_), size_(other.size_) {}

    char operator[](size_t index) const { 
        assert(index < size_ && "Index out of range");
        return data_[index]; 
    }
    
    const char *data() const { return data_; }

    size_t size() const { return size_; }
 
 private:
    const char *data_;
    size_t size_;
};
} // namespace utilities
#endif  // STRING_VIEW_H