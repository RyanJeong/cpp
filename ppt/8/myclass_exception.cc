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

#include <exception>
#include <string>

class MyClassException : public std::exception {
 public:
  MyClassException(const std::string& what, const std::string& where) noexcept;
  ~MyClassException() noexcept override = default;

  const char* what() const noexcept override;
  const char* where() const noexcept;

 private:
  const std::string what_;
  const std::string where_;
};

MyClassException::MyClassException(const std::string& what,
                                   const std::string& where) noexcept
    : what_(what), where_(where) {}

const char* MyClassException::what() const noexcept { return what_.c_str(); }

const char* MyClassException::where() const noexcept { return where_.c_str(); }

