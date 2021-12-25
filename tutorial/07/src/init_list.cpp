/*
    Copyright 2021 Munseong Jeong <msjeong@daejin.ac.kr>

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

class Test {
 public:
  Test() = default;
  Test(char, int, double);
  ~Test(void) = default;
 private:
  char c_;
  int i_;
  double d_;
};

/*
Test::Test(char c, int i, double d) {
  c_ = c;
  i_ = i;
  d_ = d;
}
*/
Test::Test(char c, int i, double d) : c_{c}, i_{i}, d_{d} {}

int main() {
  Test test('a', 2, 3.14);

  return 0;
}
