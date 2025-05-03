#ifndef SCOPEDPOINTER_H
#define SCOPEDPOINTER_H

template <typename T>
class ScopedPointer {
public:
    explicit ScopedPointer(T* ptr = nullptr) : ptr_(ptr) {}
    ~ScopedPointer() { delete ptr_; }

    // Удаляем копирование
    ScopedPointer(const ScopedPointer&) = delete;
    ScopedPointer& operator=(const ScopedPointer&) = delete;

    // Перемещение
    ScopedPointer(ScopedPointer&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    ScopedPointer& operator=(ScopedPointer&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    T* operator->() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* get() const { return ptr_; }

private:
    T* ptr_;
};

#endif // SCOPEDPOINTER_H
