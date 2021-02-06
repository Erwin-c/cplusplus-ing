/*
 * smart_ptr.h
 *
 *  Created on: Feb 4, 2021
 *      Author: Erwin
 */

#ifndef SMRAT_PTR_H_
#define SMART_PTR_H_

#include <algorithm>

template <typename T>
class smart_ptr {
 public:
  explicit smart_ptr(T* ptr = nullptr) : ptr_(ptr) {}
  // smart_ptr(smart_ptr& other) { ptr_ = other.release(); }
  // To do
  smart_ptr(smart_ptr&& other) { ptr_ = other.release(); }
  ~smart_ptr() { delete ptr_; }

  T* get() const { return ptr_; }

  T& operator*() const { return *ptr_; }
  T* operator->() const { return ptr_; }
  // To do
  operator bool() const { return ptr_; }

  // smart_ptr& operator=(smart_ptr& rhs) {
    // smart_ptr(rhs).swap(*this);
    // return *this;
  // }

  smart_ptr& operator=(smart_ptr rhs) {
    rhs.swap(*this);
    return *this;
  }

 private:
  T* ptr_;

  T* release() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }

  void swap(smart_ptr& rhs) {
    std::swap(ptr_, rhs.ptr_);
  }
};

#endif  // SMART_PTR_H_
