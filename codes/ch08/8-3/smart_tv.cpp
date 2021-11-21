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

#include <iostream>
#include <string>

class TV {
  int size;
 public:
  TV() : size(20) { }
  explicit TV(int size) : size(size) { }
  int getSize() { return size; }
};

class WideTV : public TV {
  bool videoIn;
 public:
  WideTV(int size, bool videoIn) : TV(size), videoIn(videoIn) { }
  bool getVideoIn() { return videoIn; }
};

class SmartTV : public WideTV {
  std::string ipAddr;
 public:
  SmartTV(std::string ipAddr, int size) : WideTV(size, true), ipAddr(ipAddr) { }
  std::string getIpAddr() { return ipAddr; }
};

int main() {
  SmartTV htv("192.0.0.1", 32);
  std::cout << "size=" << htv.getSize() << std::endl;
  std::cout << "videoIn=" << std::boolalpha << htv.getVideoIn() << std::endl;
  std::cout << "IP=" << htv.getIpAddr() << std::endl;

  return 0;
}
