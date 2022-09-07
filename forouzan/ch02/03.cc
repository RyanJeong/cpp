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

/************************************************************* 
 * 키보드로부터 2개의 숫자 값을 입력받은 뒤에               *
 * 두 값을 더한 후 출력하는 프로그램                          * 
 *************************************************************/

#include <iostream>

using std::cin;
using std::cout;

int main() {
  // 입력받기
  cout << "첫 번째 숫자 입력: ";
  int num1;
  cin >> num1;
  cout << "두 번째 숫자 입력: ";
  int num2;
  cin >> num2;

  // 계산과 결과 저장
  int sum = num1 + num2;
  cout << "두 숫자의 합: " << sum;

  return 0;
}
