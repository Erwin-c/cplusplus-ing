/*
 * demo_class.h
 *
 *  Created on: May 9, 2021
 *      Author: Erwin
 */

#ifndef DEMO_CLASS_H_
#define DEMO_CLASS_H_

#include <string>
#include <vector>

class Interface {};

// 'final': Inheritation is forbidden.
// It is suggested to use 'public' inheritation.
// It may be confused to use 'virtual' and 'protected'.
class DemoClass final : public Interface {
 public:
  // 'using': Type Alias.
  using string_type = std::string;
  using vector_type = std::vector<int>;

  // 6 functions:
  // These functions shall be implemented automatically by the complier.
  // Constructor: Default, Copy, Move. Assignment: Copy, Move.
  // Destructor:

  // 'default': Tell the compiler explicitly to use the default implementation.
  DemoClass() = default;

  DemoClass(const DemoClass&) = delete;

  // Copy assignment is forbidden.
  DemoClass& operator=(const DemoClass&) = delete;

  // 'explicit': To prevent accidental type conversion due to implicit
  //             construction and implicit transform.
  // Mainly for:
  // Constructors: Only one parameter.
  //               One parameter and other parameters with default value.
  // Transform operator functions:
  explicit DemoClass(const string_type& str);
  explicit operator bool();

  ~DemoClass() = default;

 private:
  // In-class member initializer: To avoid the pitfalls of not initializing.
  int a = 10;
  string_type s = "hello";
  vector_type v{1, 2, 3};
};

class DemoDelegating final {
 public:
  using string_type = std::string;

  // Delegating(Basic) Constructor.
  DemoDelegating(int x) : a(x) {}

  DemoDelegating() : DemoDelegating(0) {}

  DemoDelegating(const string_type& s) : DemoDelegating(stoi(s)) {}

  int get() { return a; }

 private:
  int a;
};

#endif  // DEMO_CLASS_H_
