#include <iostream>
#include <string>
#include <algorithm>

int main() {
  while (true) {
    std::string str;
    std::getline(std::cin, str);
    if (str == "***") {
      break;
    }
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl;
  }

  return 0;
}
