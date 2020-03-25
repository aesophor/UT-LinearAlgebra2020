#include <iostream>

#include "matrix.h"

using namespace matricks;

int main() {
  Matrix<3, 4> m1 = {
    {1, 1, 1, 5},
    {2, 3, 5, 8},
    {4, 0, 5, 2}
  };

  std::cout << "Original matrix:" << std::endl
    << m1 << std::endl;

  std::cout << "Rref:" << std::endl
    << m1.Rref() << std::endl;


  Matrix<3, 4> m2 = {
    {-3, -6, -30, -9},
    {2,   1,  11,  1},
    {1,  -4,  -8, -3}
  };

  std::cout << "Original matrix:" << std::endl
    << m2 << std::endl;

  std::cout << "Rref:" << std::endl
    << m2.Rref() << std::endl;

}
