// Copyright (c) 2018-2020 Marco Wang <m.aesophor@gmail.com>
#include <iostream>
#include <cassert>

#include <matricks/fraction.h>

using namespace matricks;

int main() {
  assert(Fraction(5, 6) + Fraction(7, 3) == Fraction(19, 6));
  assert(Fraction(5, 6) - Fraction(7, 3) == Fraction(-27, 18));
  assert(Fraction(5, 6) * Fraction(7, 3) == Fraction(35, 18));
  assert(Fraction(5, 6) / Fraction(7, 3) == Fraction(5, 14));

  assert(Fraction(2, 3) + Fraction(1, 3) == 1);
  assert(Fraction(5, 6) - Fraction(5, 6) == Fraction(0));
  assert(Fraction(5, 6) - Fraction(5, 6) == Fraction(0, 2));
  assert(Fraction(5, 6) - Fraction(5, 6) == 0);
  assert(Fraction(5, 6) * 0 == 0);

  assert(Fraction(0, 3) == Fraction(0, 5));
  assert(Fraction(6, 3) == 2);
  assert(Fraction(7, 3) != 2);
  assert(Fraction(1, 3) != Fraction(2, 3));

  std::cout << "fraction: all tests passed" << std::endl;
}
