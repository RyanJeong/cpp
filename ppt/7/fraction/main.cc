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
#include <iomanip>

#include "fraction.hpp"  // [NOLINT]

int main() {
  Fraction fract1(2, 3);
  Fraction fract2(1, 2);
  std::cout << "fract1: " << fract1 << std::endl;
  std::cout << "fract2: " << fract2 << std::endl;
  std::cout << "Result of +fract1: " << +fract1 << std::endl;
  std::cout << "Result of -fract2: " << -fract2 << std::endl << std::endl;

  Fraction fract3(3, 4);
  Fraction fract4(4, 5);
  Fraction fract5(5, 6);
  Fraction fract6(6, 7);
  std::cout << "fract3: " << fract3 << std::endl;
  std::cout << "fract4: " << fract4 << std::endl;
  std::cout << "fract5: " << fract5 << std::endl;
  std::cout << "fract6: " << fract6 << std::endl << std::endl;
  ++fract3;
  --fract4;
  fract5++;
  fract6--;
  std::cout << "Result of ++fract3: " << fract3 << std::endl;
  std::cout << "Result of --fract4: " << fract4 << std::endl;
  std::cout << "Result of fract5++: " << fract5 << std::endl;
  std::cout << "Result of fract6--: " << fract6 << std::endl << std::endl;

  Fraction fract7(3, 5);
  Fraction fract8(4, 7);
  Fraction fract9(5, 8);
  Fraction fract10(7, 9);
  fract7 += 2;
  fract8 -= 3;
  fract9 *= 4;
  fract10 /= 5;
  std::cout << "Result of fract7 += 2: " << fract7 << std::endl;
  std::cout << "Result of fract8 -= 3: " << fract8 << std::endl;
  std::cout << "Result of fract9 *= 4: " << fract9 << std::endl;
  std::cout << "Result of fract10 /= 5: " << fract10 << std::endl << std::endl;

  Fraction fract11(1, 2);
  Fraction fract12(3, 4);
  std::cout << "fract11: " << fract11 << std::endl;
  std::cout << "fract12: " << fract12 << std::endl;
  std::cout << "fract11 + fract12 : " << fract11 + fract12 << std::endl;
  std::cout << "fract11 - fract12 : " << fract11 - fract12 << std::endl;
  std::cout << "fract11 * fract12 : " << fract11 * fract12 << std::endl;
  std::cout << "fract11 / fract12 : " << fract11 / fract12 << std::endl
            << std::endl;

  Fraction fract13(2, 3);
  Fraction fract14(1, 3);
  std::cout << "fract13: " << fract13 << std::endl;
  std::cout << "fract14: " << fract14 << std::endl;
  std::cout << "fract13 == fract14: " << std::boolalpha;
  std::cout <<(fract13 == fract14) << std::endl;
  std::cout << "fract13 != fract14: " << std::boolalpha;
  std::cout <<(fract13 != fract14) << std::endl;
  std::cout << "fract13 > fract14: " << std::boolalpha;
  std::cout <<(fract13 > fract14) << std::endl;
  std::cout << "fract13 < fract14: " << std::boolalpha;
  std::cout <<(fract13 < fract14) << std::endl << std::endl;

  // Using convertor constructor to create two new objects
  Fraction fract15(5);  // Changing an integer to a fraction
  Fraction fract16(23.45);  // Changing a double value to a fraction
  std::cout << "fract15: " << fract15 << std::endl;
  std::cout << "fract16: " << fract16 << std::endl << std::endl;

  // Changing a fraction to a double
  Fraction fract17(9, 13);
  std::cout << "double value of fract17(9, 13): ";
  // std::cout << std::setprecision(2) << fract17.operator double();
  std::cout << std::setprecision(2) << static_cast<double>(fract17)
            << std::endl << std::endl;

  Fraction fract18;
  std::cin >> fract18;
  std::cout << "fract18: " << fract18 << std::endl;
  return 0;
}
