## Gauss Jordan Elimination
* For implementation details, see `Matrix::Rref()` in [`src/matrix.h`](https://github.com/aesophor/UT-LinearAlgebra2020/blob/master/matricks/matrix.h).

* Arithmetic operations are carried out using fractions (see [`src/fraction.h`](https://github.com/aesophor/UT-LinearAlgebra2020/blob/master/matricks/fraction.h)).

## Todo
* Ideally, we should enforce size check on matrices at compile-time (currently it's only performed at runtime).

## Requirements
* g++ (or any C++11 compilant compiler)

## Installation
```
$ sudo make install
```
This will copy the `matricks` directory into `/usr/local/include/`.

## Usage
Include headers:
```
#include <matricks/matrix.h>
```

Declare a matrix:
```
Matrix<3, 3> m1 = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};
```

Reduce matrix `m1` to rref:
```
m1.Rref();
```

## Examples
```
Original matrix:
1 2 3
4 5 6
7 8 9

Rref:
1 0 -1
0 1 2
0 0 0
```

```
Original matrix:
-3 -6 -30 -9
2 1 11 1
1 -4 -8 -3

Rref:
1 0 4 0
0 1 3 0
0 0 0 1
```
