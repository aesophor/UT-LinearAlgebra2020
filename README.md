## Gauss Jordan Elimination
Declare a matrix like this:
```
Matrix<3, 3> m1 = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};
```

Reduce matrix `m1` to rref like this:
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
