#include <vector>
#include <iostream>
#include "./libraries/split.h"

int main() {
  std::string test = "this is a string";

  std::vector<std::string> vec = libsplit::split(test, ' ');

  for (std::string thing : vec) {
    std::cout << thing << std::endl;
  }

  return 0;
}

