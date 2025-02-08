
#include <iostream>
#include "include/utils.hpp"
using namespace std;
using namespace graphvizwrapper;

enum Color { RED, WHITE, BLACK };
enum class Name { Tom, Lily, LiHua };

int main() {
  if (enum_to_string<Color, RED>() == string("RED")) {
    std::cout << enum_to_string<Color, RED>() << std::endl;
  } else {
    ERROR_PRINT("enum_to_string has error.");
    return 1;
  }
  if (enum_to_string<Name, Name::LiHua>() == string("Name::LiHua")) {
    std::cout << enum_to_string<Name, Name::LiHua>() << std::endl;
  } else {
    ERROR_PRINT("enum_to_string has error.");
    return 1;
  }
  return 0;
}