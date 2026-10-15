#ifndef VECTOR_H
#define VECTRE_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <string>

template <typename T>
class Vector{
private:
    T* data_;
    size_t size_;
    size_t capacity_;
public:
    Vector() : data_(nullptr), size_(0), capacity_(0){}

    ~Vector(){delete[] data_;}

    Vector(const Vector &other){
        data_ = new T[other.capacity()];
        for(int i = 0; i < other.size(); ++i)
            data_[i] = other.data_[i];
        capacity_ = other.capacity();
        size_ = other.size();
    }

    Vector& operator=(Vector other){
        swap(other);
        return *this;
    }

    void swap(Vector &other) noexcept {
        using std::swap;
        swap(data_, other.data_);
        swap(size_, other.size_);
        swap(capacity_, other.capacity_);
    }

    Vector(Vector &&other) noexcept : data_(other.data_), size_(other.size_),capacity_(other.capacity_){
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    Vector& operator=(Vector &&other) noexcept {
        if(this != &other){
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    bool operator==(const Vector &other) const {
        if(size() != other.size()) return false;
        for(size_t i = 0; i < size(); ++i)
            if(data_[i] != other.data_[i])
                return false;
        return true;
    }

    void push_back(const T& num){
        if(size_ == capacity_){
            size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
            T* new_data = new T[new_capacity];
            for(size_t i = 0; i < size_; ++i)
                new_data[i] = data_[i];
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        data_[size_] = num;
        size_++;   
    }

    void push_back(const T&& num){
        if(size_ == capacity_){
            size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
            T* new_data = new T[new_capacity];
            for(size_t i = 0; i < size_; ++i)
                new_data[i] = std::move(data_[i]);
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        data_[size_] = std::move(num);
        size_++;
    }

    void pop_back(){
        if(size_ > 0)
            size_--;
    }

    void clear(){       
        size_ = 0;
    }

    void reserve(size_t new_capacity){
        if(new_capacity > capacity_){
            T* new_data = new T[new_capacity];
            for(size_t i = 0; i < size_; ++i)
                new_data[i] = std::move(data_[i]);
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
    }

    void resize(size_t new_size){
         if(new_size > size_){
            if(new_size > capacity_)
                reserve(new_size);
            for(size_t i = size_; i < new_size; ++i)
                data_[i] = T();
        }
        size_ = new_size;
    }

    template <typename... Args>
    void emplace_back(Args&&... args){
        if(size_ == capacity_){
            size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
            T* new_data = new T[new_capacity];
            for(size_t i = 0; i < size_; ++i)
                new_data[i] = std::move(data_[i]);
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        new (data_ + size_) T(std::forward<Args>(args)...);
        size_++;
    }

    using iterator = T*;
    using const_iterator = const T*;
    iterator begin() { return data_; }
    iterator end() { return data_ + size_; }
    const_iterator begin() const { return data_; }
    const_iterator end() const { return data_ + size_; }

    size_t size() const { return size_;}
    size_t capacity() const { return capacity_;}
    bool empty() const { return size_ == 0;}
    T* data() { return data_;}

    T& operator[](size_t i) {return data_[i];}
    const T& operator[](size_t i) const {return data_[i];}

    T& front() { return at(0);}
    const T& front() const { return at(0);}
    T& back() { if(size() == 0) throw std::out_of_range("Index out of range"); return data_[size() - 1];}
    const T& back() const { if(size() == 0) throw std::out_of_range("Index out of range"); return data_[size() - 1];}

    T& at(size_t i){
        if(i >= size_)
            throw std::out_of_range("Index out of range");
        return data_[i];
    }

    const T& at(size_t i) const {
        if(i >= size_)
            throw std::out_of_range("Index out of range");
        return data_[i];
    }
};
#endif
