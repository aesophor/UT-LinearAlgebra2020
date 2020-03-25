#ifndef MATRICKS_H_
#define MATRICKS_H_

#include <iostream>
#include <initializer_list>
#include <vector>

namespace matricks {

template <typename T, size_t row_size, size_t col_size>
class Matrix {
 public:
  Matrix(std::initializer_list<std::initializer_list<T>> init_list) {
    data_.reserve(row_size);
    for (const auto& row : init_list) {
      data_.push_back({});
      data_.back().reserve(col_size);
      for (const auto& col : row) {
        data_.back().push_back(col);
      }
    }
  }

  virtual ~Matrix() = default;

  friend std::ostream& operator<< (std::ostream& os, const Matrix& m) {
    for (const auto& row : m.data_) {
      for (const auto& col : row) {
        std::cout << col << " ";
      }
      std::cout << std::endl;
    }
    return os;
  }

 private:
  std::vector<std::vector<T>> data_;
};

}  // namespace matricks

#endif  // MATRICKS_H_
