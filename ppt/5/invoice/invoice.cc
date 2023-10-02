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

#include "invoice.hpp"  // [NOLINT]

Invoice::Invoice(int invoice_num)
    : invoice_number_(invoice_num), invoice_total_(0.0) {}

void Invoice::add(int quantity, const Product& product) {
  invoice_total_ += quantity * product.get_price();
}

void Invoice::print() const {
  std::cout << "Invoice Number: " << invoice_number_ << std::endl;
  std::cout << "Invoice Total: " << invoice_total_ << std::endl;
}

