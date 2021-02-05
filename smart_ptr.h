/*
 * smart_ptr.h
 *
 *  Created on: Feb 4, 2021
 *      Author: Erwin
 */

#ifndef SMRAT_PTR_H_
#define SMART_PTR_H_

template <typename T>
class smart_ptr {
 public:
  // To do
  explicit smart_ptr(T* ptr = nullptr) : ptr(_ptr) {}
  ~smart_ptr() { delete ptr_; }

  T* get const { return ptr_; }

  T& operator*() const { return *ptr; }
  T* operator(->) const { return ptr_; }
  // To do
  operator bool() const { return ptr_; }

 private:
  T* ptr_;
};

#endif  // SMART_PTR_H_
