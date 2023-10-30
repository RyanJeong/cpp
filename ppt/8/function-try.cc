/*
    Copyright 2023 Munseong Jeong <munseong.jeong@daejin.ac.kr>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <string>

class MyClass {
 public:
  MyClass() try : value_(0) {
    // Handling exceptions in the function-try block if they occur during construction.
    if (value_ == 0) throw std::string("Value is zero.");
  } catch (const std::string& e) {
    std::cerr << "MyClass constructor caught an exception: " << e << std::endl;
    throw; // Re-throwing the exception to propagate it to the caller.
  }

 private:
  int value_;
};

int main() {
  try {
    MyClass obj;
  } catch (const std::string& e) {
    std::cerr << "Main caught an exception: " << e << std::endl;
  }
  return 0;
}

