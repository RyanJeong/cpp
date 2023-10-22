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

#include "fraction.hpp"  // [NOLINT]

#include <iostream>
#include <cassert>
#include <cmath>

Fraction::Fraction(int num, int den) : numer_(num), denom_(den) {
  Normalize();
}

Fraction::Fraction(double value) : denom_(1) {
  while ((value - static_cast<int>(value)) > 0.0) {
    value *= 10.0;
    denom_ *= 10;
  }
  numer_ = static_cast<int>(value);
  Normalize();
}

Fraction::Fraction() : numer_(0), denom_(1) {}

// Conversion operator
Fraction::operator double() const {
  double num = static_cast<double>(numer_);
  return (num / denom_);
}

// Unary plus operator
const Fraction Fraction::operator+() const {
  Fraction temp(+numer_, denom_);
  return temp;
}

// Unary minus operator
const Fraction Fraction::operator-() const {
  Fraction temp(-numer_, denom_);
  return temp;
}

// Pre-increment operator
Fraction& Fraction::operator++() {
  numer_ = numer_ + denom_;
  Normalize();
  return *this;
}

// Pre-decrement operator
Fraction& Fraction::operator--() {
  numer_ = numer_ - denom_;
  Normalize();
  return *this;
}

// Post-increment operator
const Fraction Fraction::operator++(int) {
  Fraction temp(numer_, denom_);
  ++(*this);
  return temp;
}

// Post-decrement operator
const Fraction Fraction::operator--(int) {
  Fraction temp(numer_, denom_);
  --(*this);
  return temp;
}

// Assignment operator
Fraction& Fraction::operator=(const Fraction& right) {
  if (*this != right) {
    numer_ = right.numer_;
    denom_ = right.denom_;
  }
  return *this;
}

// Compound Assignment operator(+=)
Fraction& Fraction::operator+=(const Fraction& right) {
  numer_ = numer_ * right.denom_ + denom_ * right.numer_;
  denom_ = denom_ * right.denom_;
  Normalize();
  return *this;
}

// Compound Assignment operator(-=)
Fraction& Fraction::operator-=(const Fraction& right) {
  numer_ = numer_ * right.denom_ - denom_ * right.numer_;
  denom_ = denom_ * right.denom_;
  Normalize();
  return *this;
}

// Compound Assignment operator(*=)
Fraction& Fraction::operator*=(const Fraction& right) {
  numer_ = numer_ * right.numer_;
  denom_ = denom_ * right.denom_;
  Normalize();
  return *this;
}

// Compound Assignment operator(/=)
Fraction& Fraction::operator/=(const Fraction& right) {
  numer_ = numer_ * right.denom_;
  denom_ = denom_ * right.numer_;
  Normalize();
  return *this;
}

// Addition operator(friend)
const Fraction operator+(const Fraction& left, const Fraction& right) {
  int new_numer = left.numer_ * right.denom_ + right.numer_ * left.denom_;
  int new_denom = left.denom_ * right.denom_;
  Fraction result(new_numer, new_denom);
  return result;
}

// Subtraction operator(friend)
const Fraction operator-(const Fraction& left, const Fraction& right) {
  int new_numer = left.numer_ * right.denom_ - right.numer_ * left.denom_;
  int new_denom = left.denom_ * right.denom_;
  Fraction result(new_numer, new_denom);
  return result;
}

// Multiplication operator(friend)
const Fraction operator*(const Fraction& left, const Fraction& right) {
  int new_numer = left.numer_ * right.numer_;
  int new_denom = left.denom_ * right.denom_;
  Fraction result(new_numer, new_denom);
  return result;
}

// Division operator(friend)
const Fraction operator/(const Fraction& left, const Fraction& right) {
  int new_numer = left.numer_ * right.denom_;
  int new_denom = left.denom_ * right.numer_;
  Fraction result(new_numer, new_denom);
  return result;
}

// Equality operator(friend)
bool operator==(const Fraction& left, const Fraction& right) {
  return (left.numer_ * right.denom_ == right.numer_ * left.denom_);
}

// Inequality operator(friend)
bool operator!=(const Fraction& left, const Fraction& right) {
  return (left.numer_ * right.denom_ != right.numer_ * left.denom_);
}

// Less-than operator(friend)
bool operator<(const Fraction& left, const Fraction& right) {
  return (left.numer_ * right.denom_< right.numer_ * left.denom_);
}

// Less-than or equal operator(friend)
bool operator<=(const Fraction& left, const Fraction& right) {
  return (left.numer_ * right.denom_<= right.numer_ * left.denom_);
}

// Greater-than operator(friend)
bool operator>(const Fraction& left, const Fraction& right) {
  return (left.numer_ * right.denom_ > right.numer_ * left.denom_);
}

// Greater-than or equal operator(friend)
bool operator>=(const Fraction& left, const Fraction& right) {
  return (left.numer_ * right.denom_ >= right.numer_ * left.denom_);
}

// Extraction operator(friend)
std::istream& operator>>(std::istream& left, Fraction& right) {
  std::cout << "Enter the value of numerator: ";
  left >> right.numer_;
  std::cout << "Enter the value of denominator: ";
  left >> right.denom_;
  right.Normalize();

  return left;
}

// Insertion operator(friend)
std::ostream& operator<<(std::ostream& left, const Fraction& right) {
  left << right.numer_ << "/" << right.denom_;
  return left;
}

// Helper function(greatest common divisor)
int Fraction::Gcd(int n, int m) {
  int gcd = 1;
  for (int k = 1; k <= n && k <= m; ++k) {
    if (n % k == 0 && m % k == 0)
      gcd = k;
  }
  return gcd;
}

// Helper function(Normalizing a fraction)
void Fraction::Normalize() {
  if (denom_ == 0) {
    std::cerr << "Invalid denomination in fraction. Need to quit."<< std::endl;
    assert(false);
  }
  if (denom_< 0) {
    denom_ = -denom_;
    numer_ = -numer_;
  }
  int divisor = Gcd(std::abs(numer_), std::abs(denom_));
  numer_ = numer_ / divisor;
  denom_ = denom_ / divisor;
}

