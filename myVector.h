#include <iostream>
#include <algorithm>
<<<<<<< HEAD
#include <memory>
#include <string>
=======
>>>>>>> 62f5f307985791666e0ab3a54e62b3980301e1a1

template <typename T>
class Vector{
private:
    T* data_;
    size_t size_;
    size_t capacity_;
public:
    //构造函数
    Vector() : data_(nullptr), size_(0), capacity_(0){}
    //析构函数
    ~Vector(){delete[] data_;}
    //拷贝构造函数
    Vector(const Vector &other){
        data_ = new T[other.capacity()];
        for(int i = 0; i < other.size(); ++i)
            data_[i] = other.data_[i];
        capacity_ = other.capacity();
        size_ = other.size();
    }
    //拷贝赋值
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
    //移动构造函数
    Vector(Vector &&other) noexcept : data_(other.data_), size_(other.size_),capacity_(other.capacity_){
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    //移动赋值
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
    //相等运算符
    bool operator==(const Vector &other) const {
        if(size() != other.size()) return false;
        for(size_t i = 0; i < size(); ++i)
            if(data_[i] != other.data_[i])
                return false;
        return true;
    }
    //添加元素
    void push_back(const T& num){
        if(size_ == capacity_){
            //1.检查容量
            size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
            //2.新的内存
            T* new_data = new T[new_capacity];
            //3.拷贝旧数据到新内存
            for(size_t i = 0; i < size_; ++i)
                new_data[i] = data_[i];
            //4.删除旧内存
            delete[] data_;
            //5.指针指向新内存
            data_ = new_data;
            //6.更新容量
            capacity_ = new_capacity;
        }
        data_[size_] = num;
        size_++;   
    }
    //添加元素（右值引用版）
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
    //删除元素
    void pop_back(){
        if(size_ > 0)
            size_--;
    }
    //清空元素
<<<<<<< HEAD
    void clear(){       
=======
    void clear(){
        std::destroy(data_, data_ + size_);
>>>>>>> 62f5f307985791666e0ab3a54e62b3980301e1a1
        size_ = 0;
    }
    //重新设置容量(和push_back中的扩容逻辑类似，但不添加元素)
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
    //缩小当前大小
    void resize(size_t new_size){
<<<<<<< HEAD
         if(new_size > size_){
            if(new_size > capacity_)
                reserve(new_size);
            for(size_t i = size_; i < new_size; ++i)
                data_[i] = T();
        }
        size_ = new_size;
    }
    //原地构造元素
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
=======
        if(new_size < size_){
            std::destroy(data_ + new_size, data_ + size_);
            size_ = new_size;
        } else if(new_size > size_){
            reserve(new_size);
            for(size_t i = size_; i < new_size; ++i)
                data_[i] = T();
            size_ = new_size;
        }
>>>>>>> 62f5f307985791666e0ab3a54e62b3980301e1a1
    }
    //迭代器支持
    using iterator = T*;
    using const_iterator = const T*;
    iterator begin() { return data_; }
    iterator end() { return data_ + size_; }
    const_iterator begin() const { return data_; }
    const_iterator end() const { return data_ + size_; }
<<<<<<< HEAD
    //元素个数
    size_t size() const { return size_;}
    //元素容量
    size_t capacity() const { return capacity_;}
    //是否为空
    bool empty() const { return size_ == 0;}
    //底层指针，供外部访问
    T* data() { return data_;}
    //下标访问元素
    T& operator[](size_t i) {return data_[i];}
    const T& operator[](size_t i) const {return data_[i];}
    //首尾元素
    T& front() { return at(0);}
    const T& front() const { return at(0);}
    T& back() { if(size() == 0) throw std::out_of_range("Index out of range"); return data_[size() - 1];}
    const T& back() const { if(size() == 0) throw std::out_of_range("Index out of range"); return data_[size() - 1];}
    //越界访问检查
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
=======
    size_t size() const { return size_;}
    size_t capacity() const { return capacity_;}
    T& operator[](size_t i) {return data_[i];}
    const T& operator[](size_t i) const {return data_[i];}
>>>>>>> 62f5f307985791666e0ab3a54e62b3980301e1a1
};