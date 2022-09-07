/*
    Copyright 2022 Munseong Jeong <ryan.m.jeong@hotmail.com>
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

/**************************************************************
 * 원의 반지름을 기반으로 둘레와 면적을 구하는 프로그램       *
 **************************************************************/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  // 상수 선언
  const double PI = 3.14159;

  // 반지름 입력받기
  cout << "원의 반지름 입력: ";
  double radius;
  cin >> radius;

  // 둘레와 면적을 계산하고 변수에 저장
  double perimeter = 2 *  PI * radius;   // 2는 상수
  double area = PI * PI * radius;

  // 반지름, 둘레, 면적 출력
  cout << "반지름: " << radius << endl;
  cout << "둘레: " << perimeter << endl;
  cout << "면적: " << area;

  return 0;
}
