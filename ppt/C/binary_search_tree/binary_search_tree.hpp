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
  Node<T>* left;
  Node<T>* right;
};

template <typename T>
class BinarySearchTree {
  Node<T>* MakeNode(const T& value) {
    Node<T>* temp = new Node<T>;
    if (!temp) {
      std::cerr << "Error! Cannot make a node." << std::endl;
      assert(false);
    }
    temp->data = value;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
  }

  // helper functions
  Node<T>* insert(const T& value, Node<T>* ptr) {
    if (!ptr)
      ptr = MakeNode(value);
    else if (value < ptr->data)
      ptr->left = insert(value, ptr->left);
    else
      ptr->right = insert(value, ptr->right);
    return ptr;
  }

  void destroy(Node<T>* ptr) {
    if (!ptr) return;
    destroy(ptr->left);
    destroy(ptr->right);
    delete ptr;
  }

  bool search(const T& value, Node<T>* ptr) const {
    if (!ptr) return false;
    if (ptr->data == value) return true;
    return search(value, (value < ptr->data ? ptr->left : ptr->right));
  }

  void preorder(Node<T>* ptr) const {
    if (!ptr) return;
    std::cout << ptr->data << std::endl;
    preorder(ptr->left);
    preorder(ptr->right);
  }

  void inorder(Node<T>* ptr) const {
    if (!ptr) return;
    inorder(ptr->left);
    std::cout << ptr->data << std::endl;
    inorder(ptr->right);
  }

  void postorder(Node<T>* ptr) const {
    if (!ptr) return;
    postorder(ptr->left);
    postorder(ptr->right);
    std::cout << ptr->data << std::endl;
  }

  Node<T>* root_;
  int count_;

 public:
  BinarySearchTree() : root_(nullptr), count_(0) {}
  ~BinarySearchTree() { destroy(root_); }

  void insert(const T& value) {
    root_ = insert(value, root_);
    ++count_;
  }

  bool search(const T& value) const { return search(value, root_); }
  void preorder() const { preorder(root_); }
  void inorder() const { inorder(root_); }
  void postorder() const { postorder(root_); }
  int size() const { return count_; }
  bool empty() const { return !count_; }
};

