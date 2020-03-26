// Copyright (c) 2018-2020 Marco Wang <m.aesophor@gmail.com>
#include <iostream>

#include <matricks/matrix.h>

using namespace matricks;


int main() {
  Matrix<3, 3> m1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
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
