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

class Fraction {
  int numer_;
  int denom_;

  int Gcd(int n, int m = 1);  // using default parameters
  void Normalize();

 public:
  // question 1. explicit Fraction(int numer, int denom = 1);
  Fraction(int numer, int denom = 1);  // [NOLINT] allow implicit conversion
  Fraction(double value);  // [NOLINT] allow implicit conversion
  Fraction();
  Fraction(const Fraction& fract) = default;
  ~Fraction() = default;

  // question 2. operator double() const;
  explicit operator double() const;
  const Fraction operator+() const;
  const Fraction operator-() const;
  Fraction& operator++();
  Fraction& operator--();
  const Fraction operator++(int);
  const Fraction operator--(int);
  Fraction& operator=(const Fraction& right);
  Fraction& operator+=(const Fraction& right);
  Fraction& operator-=(const Fraction& right);
  Fraction& operator*=(const Fraction& right);
  Fraction& operator/=(const Fraction& right);

  friend const Fraction operator+(const Fraction& left, const Fraction& right);
  friend const Fraction operator-(const Fraction& left, const Fraction& right);
  friend const Fraction operator*(const Fraction& left, const Fraction& right);
  friend const Fraction operator/(const Fraction& left, const Fraction& right);

  friend bool operator==(const Fraction& left, const Fraction& right);
  friend bool operator!=(const Fraction& left, const Fraction& right);
  friend bool operator<(const Fraction& left, const Fraction& right);
  friend bool operator<=(const Fraction& left, const Fraction& right);
  friend bool operator>(const Fraction& left, const Fraction& right);
  friend bool operator>=(const Fraction& left, const Fraction& right);

  friend std::istream& operator>>(std::istream& left, Fraction& right);
  friend std::ostream& operator<<(std::ostream& left, const Fraction& right);
};

