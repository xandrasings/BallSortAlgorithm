#include "Position.h"
#include <iostream>



Position::Position (int content) {
  var_content = content;
}

void Position::print () {
  std::cout << "Position! " << var_content << std::endl;
  std::cout << std::endl;
}