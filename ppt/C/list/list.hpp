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

#pragma once

#include <iostream>
#include <cassert>

template <typename T>
struct Node {
  T data;
  Node<T>* next;
};

template <typename T>
class List {
  Node<T>* MakeNode(const T& value) {
    Node<T>* temp = new Node<T>;
    if (!temp) {
      std::cerr << "Error! Cannot make a node." << std::endl;
      assert(false);
    }
    temp->data = value;
    temp->next = 0;
    return temp;
  }

  Node<T>* begin_;
  int count_;

 public:
  List() : begin_(nullptr), count_(0) {}
  ~List() {
    for (Node<T>* del = begin_; del; del = begin_) {
      begin_ = begin_->next;
      delete del;
    }
  }

  void insert(int pos, const T& value) {
    if (pos < 0 || pos > count_) {
      std::cerr << "Error! The position is out of range." << std::endl;
      assert(false);
    }
    Node<T>* add = MakeNode(value);
    ++count_;
    if (!pos) {
      add->next = begin_;
      begin_ = add;
      return;
    }
    Node<T>* cur = begin_;
    for (int i = 1; i < pos; ++i) cur = cur->next;
    add->next = cur->next;
    cur->next = add;
  }

  void erase(int pos) {
    if (pos < 0 || pos > count_ - 1) {
      std::cerr << "Error! The position is out of range." << std::endl;
      assert(false);
    }
    --count_;
    if (!pos) {
      Node<T>* del = begin_;
      begin_ = del->next;
      delete del;
      return;
    }
    Node<T>* cur = begin_;
    for (int i = 0; i < pos - 1; ++i) cur = cur->next;
    Node<T>* del = cur->next;
    cur->next = del->next;
    delete del;
  }

  T& get(int pos) const {
    if (pos < 0 || pos > count_ - 1) {
      std::cerr << "Error! The position is out of range." << std::endl;
      assert(false);
    }
    if (!pos) {
      return begin_->data;
    } else {
      Node<T>* cur = begin_;
      for (int i = 0; i < pos; ++i) cur = cur->next;
      return cur->data;
    }
  }

  void print() const {
    if (!count_) {
      std::cout << "\tList is empty." << std::endl;
      return;
    }
    for (Node<T>* cur = begin_; cur; cur = cur->next)
      std::cout << "\t" << cur->data << std::endl;
  }

  int size() const { return count_; }
};

