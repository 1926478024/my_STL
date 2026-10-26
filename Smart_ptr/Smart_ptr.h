#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <iostream>

template <typename T> class Weak_ptr;
template <typename T>
class Shared_ptr{
  private:
    T* ptr_;
    long* strong_;
    long* weak_;
    void release(){
	if(strong_){
	  --(*strong_);
	  if(*strong_ == 0){
	    delete ptr_;
	    ptr_ = nullptr;
	    if(*weak_ == 0){
		delete strong_;
		delete weak_;
		strong_ = nullptr;
		weak_ = nullptr;
	    }
	  }
	}
    }
    friend class Weak_ptr<T>;
  public:
    Shared_ptr():ptr_(nullptr), strong_(nullptr), weak_(nullptr){}
    explicit Shared_ptr(T* ptr = nullptr):ptr_(ptr), strong_(nullptr), weak_(nullptr){
	if(ptr_){
	  strong_ = new long(1);
	  weak_ = new long(0);
	}
    }
    ~Shared_ptr(){
	release();
    }
    //拷贝构造和赋值运算符
    Shared_ptr(const Shared_ptr &other): ptr_(other.ptr_), strong_(other.strong_), weak_(other.weak_){
	if(strong_) ++(*strong_);
    }
    Shared_ptr& operator =(const Shared_ptr &other){
	if(this != &other){
	  release();
	  ptr_ = other.ptr_;
	  strong_ = other.strong_;
	  weak_ = other.weak_;
	  if(strong_) ++(*strong_);
        }
	return *this;
    }
    //移动构造
    Shared_ptr(Shared_ptr &&other) noexcept : ptr_(other.ptr_), strong_(other.strong_), weak_(other.weak_){
	other.ptr_ = nullptr;
	other.strong_ = nullptr;
	other.weak_ = nullptr;
    }
    Shared_ptr& operator = (Shared_ptr &&other) noexcept {
	if(this != &other){
	  ptr_ = other.ptr_;
	  strong_ = other.strong_;
	  weak_ = other.weak_;
	  other.ptr_ = nullptr;
	  other.strong_ = nullptr;
	  other.weak_ = nullptr;
	}
	return *this;
    }

    T& operator *() const{ return *ptr_; }
    T* operator ->() const{ return ptr_; }
    T* get() const{ return ptr_; }
    long use_count() const{ return strong_ ? *strong_ : 0; }
    void reset(T* ptr = nullptr){
	if(ptr_ == ptr) return ;
	release();
	ptr_ = ptr;
	strong_ = nullptr;
	weak_ = nullptr;
	if(ptr_) {
	  strong_ = new long(1);
	  weak_ = new long(0);
	}
    }
};

template <typename T>
class Unique_ptr{
  private:
    T* ptr_;
    void destroy(){
	delete ptr_;
	ptr_ = nullptr;
    }
  public:
    explicit Unique_ptr(T* ptr = nullptr):ptr_(ptr){}
    ~Unique_ptr(){
        destroy();
    }
    Unique_ptr(const Unique_ptr &other) = delete;
    Unique_ptr& operator =(const Unique_ptr &other) = delete;
    Unique_ptr(Unique_ptr &&other) noexcept : ptr_(other.ptr_){
        other.ptr_ = nullptr;
    }
    Unique_ptr& operator = (Unique_ptr &&other) noexcept {
        if(this != &other){
	  destroy();
          ptr_ = other.ptr_;
          other.ptr_ = nullptr;
        }
        return *this;
    }

    T& operator *() const{ return *ptr_; }
    T* operator ->() const{ return ptr_; }
    T* get() const{ return ptr_; }

    void reset(T* ptr = nullptr){
        if(ptr_ == ptr) return ;
        destroy();
        ptr_ = ptr;
    }
};

template <typename T>
class Weak_ptr{
  private:
    T* ptr_;
    long* strong_;
    long* weak_;
    void release(){
	if(weak_){
	  --(*weak_);
	  if(*weak_ == 0 && strong_ && *strong_ == 0){
	    delete strong_;
	    delete weak_;
	  }
	  ptr_ = nullptr;
	  strong_ = nullptr;
	  weak_ = nullptr;
	}
    }
  public:
    Weak_ptr(): ptr_(nullptr), strong_(nullptr), weak_(nullptr){}
    Weak_ptr(const Shared_ptr<T> &sp) : ptr_(sp.ptr_), strong_(sp.strong_), weak_(sp.weak_){
	if(weak_) ++(*weak_);
    }

    ~Weak_ptr(){
	release();
    }

    Weak_ptr(const Weak_ptr &other) : ptr_(other.ptr_), strong_(other.strong_), weak_(other.weak_){
	if(weak_) ++(*weak_);
    }
    Weak_ptr& operator =(const Weak_ptr &other){
	if(this != &other){
	  release();
	  ptr_ = other.ptr_;
	  strong_ = other.strong_;
	  weak_ = other.weak_;
	  if(weak_) ++(*weak_);
	}
	return *this;
    }
    Weak_ptr(Weak_ptr &&other) noexcept {
	ptr_ = other.ptr_;
	strong_ = other.strong_;
	weak_ = other.weak_;
	other.ptr_ = nullptr;
	other.strong_ = nullptr;
	other.weak_ = nullptr;
    }
    Weak_ptr& operator =(Weak_ptr &&other) noexcept {
	if(this != &other){
	  release();
	  ptr_ = other.ptr_;
	  strong_ = other.strong_;
	  weak_ = other.weak_;
	  other.ptr_ = nullptr;
	  other.strong_ = nullptr;
	  other.weak_ = nullptr;
	}
	return *this;
    }

    //提升为Shared_ptr
    Shared_ptr<T> lock() const{
	if(strong_ && *strong_ > 0){
	  Shared_ptr<T> sp;
	  sp.ptr_ = ptr_;
	  sp.strong_ = strong_;
	  sp.weak_ = weak_;
	  ++(*strong_);
	  return sp;
	}
	return Shared_ptr<T>();
    }

    bool expired() const{
	return !strong_ || *strong_ == 0;
    }
    long use_count() const{
	return strong_ ? *strong_ : 0;
    }

    void reset(){
	release();
    }
};
#endif
