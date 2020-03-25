#include <iostream>

#include "matrix.h"

using namespace matricks;

int main() {
  Matrix<int, 3, 4> m = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 0, 0, 1}
  };

  std::cout << m << std::endl;
}
