// Copyright (c) 2018-2020 Marco Wang <m.aesophor@gmail.com>
#include <iostream>
#include <cassert>

#include <matricks/matrix.h>

using namespace matricks;


int main() {
  Matrix<3, 3> m1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  const Matrix<3, 3> m1_rref = {
    {1, 0, -1},
    {0, 1,  2},
    {0, 0,  0}
  };

  assert(m1.Rref() == m1_rref);


  Matrix<3, 4> m2 = {
    {-3, -6, -30, -9},
    {2,   1,  11,  1},
    {1,  -4,  -8, -3}
  };

  const Matrix<3, 4> m2_rref = {
    {1, 0, 4, 0},
    {0, 1, 3, 0},
    {0, 0, 0, 1}
  };

  assert(m2.Rref() == m2_rref);

  std::cout << "gauss jordan elimination: all tests passed" << std::endl;
}
