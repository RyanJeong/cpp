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
#include <queue>

int main() {
  std::queue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);

  if (!queue.empty()) {
    std::cout << "Queue size: " << queue.size() << std::endl;
    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Back element: " << queue.back() << std::endl;
    queue.pop();
    std::cout << "Dequeued(popped) one element." << std::endl;
    std::cout << "Front element after dequeue: " << queue.front() << std::endl;
  }
  return 0;
}
