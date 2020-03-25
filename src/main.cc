#include <iostream>

#include "matrix.h"

using namespace matricks;

int main() {
  Matrix<int, 3, 4> m = {
    {1, 1, 1, 5},
    {2, 3, 5, 8},
    {4, 0, 5, 2}
  };

  std::cout << "Original matrix:" << std::endl
    << m << std::endl;

  std::cout << "Rref:" << std::endl
    << m.Rref() << std::endl;
}
