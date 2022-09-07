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
 * 동전과 지폐들의 금액 합계를 구하는 프로그램               *
 *************************************************************/
#include <iostream>

using std::cin;
using std::cout;

int main() {
  // 상수 정의
  const unsigned int pennyValue = 1;
  const unsigned int nickelValue = 5;
  const unsigned int dimeValue = 10;
  const unsigned int quarterValue = 25;
  const unsigned int dollarValue = 100;

  // 코인 입력받기
  cout << "페니의 수: ";
  unsigned int pennies;
  cin >> pennies;
  cout << "니켈의 수: ";
  unsigned int nickels;
  cin >> nickels;
  cout << "다임의 수: ";
  unsigned int dimes;
  cin >> dimes;
  cout << "쿼터의 수: ";
  unsigned int quarters;
  cin >> quarters;
  cout << "달러의 수: ";
  unsigned int dollars;
  cin >> dollars;

  // 전체 금액 계산
  uint64_t totalValue;
  totalValue = pennies * pennyValue + nickels * nickelValue +
      dimes * dimeValue + quarters * quarterValue + dollars * dollarValue;

  // 결과 출력
  cout << "전체 값은 " << totalValue << "페니입니다.";

  return 0;
}
