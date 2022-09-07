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
 * 3회 거래 후의 계좌 잔액을 구하는 프로그램                  *
 **************************************************************/
#include <iostream>

using std::cin;
using std::cout;

int main() {
  // 변수 선언
  int balance = 0;

  // 첫 번째 거래 후에 잔액 조정
  cout << "첫 번째 거래 금액 입력: ";
  int transaction;
  cin >> transaction;
  balance = balance + transaction;

  // 두 번째 거래 후에 잔액 조정
  cout << "두 번째 거래 금액 입력: ";
  cin >> transaction;
  balance = balance + transaction;

  // 세 번째 거래 후에 잔액 조정
  cout << "세 번째 거래 금액 입력: ";
  cin >> transaction;
  balance = balance + transaction;

  // 최종 잔액 출력
  cout << "계좌의 최종 잔액은 " << balance << "달러입니다.";

  return 0;
}
