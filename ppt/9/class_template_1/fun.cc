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

#ifndef FUN_CC
#define FUN_CC
#include "fun.hpp"  // [NOLINT]

// Constructor
template <typename T>
Fun<T>::Fun(const T& d) : data_(d) {}

// Accessor Function
template <typename T>
T Fun<T>::get() const { return data_; }

// Mutator Function
template <typename T>
void Fun<T>::set(const T& d) { data_ = d; }
#endif

