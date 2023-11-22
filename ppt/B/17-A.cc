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

void move_one_disk(char start, char end) {
  std::cout << "Move top disk from " << start << " to " << end << std::endl;
}

void towers(int num, char source, char dest, char aux) {
  if (num == 1) {
    move_one_disk(source, dest);
  } else {
    towers(num - 1, source, aux, dest);
    move_one_disk(source, dest);
    towers(num - 1, aux, dest, source);
  }
}

int main() {
  int n;
  do {
    std::cout << "Enter number of disks(1 to 7): ";
    std::cin >> n;
  } while((n < 1) ||(n > 7));
  towers(n, 'A', 'C', 'B');
  return 0;
}

