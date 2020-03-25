#ifndef MATRICKS_H_
#define MATRICKS_H_

#include <iostream>
#include <initializer_list>
#include <vector>

namespace matricks {

struct MatrixPtr {
 public:
  MatrixPtr() : row(), col() {}
  size_t row;
  size_t col;
};

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

  Matrix<T, row_size, col_size>& Rref() {
    // Place a cursor in the top entry of the first non-zero column
    // of this matrix.
    // TODO: what if the elements in the first row are all zeroes?
    MatrixPtr ptr;
    for (const auto& col : data_[0]) {
      if (col == 0) {
        ptr.col++;
      }
    }


    while (ptr.row < row_size && ptr.col < col_size) {
      // Step1. If the cursor entry is zero, swap the cursor row with
      //        some row below to make the cursor entry non-zero.
      if (data_[ptr.row][ptr.col] == 0) {
        for (size_t i = 1; i < row_size; i++) {
          if (data_[i][ptr.col] != 0) {
            std::swap(data_[ptr.row], data_[i]);
          }
        }
      }

      // Step2: Divide the cursor row by the cursor entry
      data_[ptr.row] = RowDiv(ptr.row, data_[ptr.row][ptr.col]);

      // Step3: Eliminate all other entries in the cursor column, by
      //        subtracting suitable multiples of the cursor row from
      //        the other rows.
      for (size_t i = 0; i < row_size; i++) {
        int ptr_entry = data_[ptr.row][ptr.col];
        int current_entry = data_[i][ptr.col];

        if (current_entry == 0 || i == ptr.row) {
          continue;
        }
        data_[i] = RowSub(i, RowMul(ptr.row, current_entry / ptr_entry));
      }

      // Step4: Move the cursor one row down and one column to the right.
      //        If the new cursor entry and all entries below are zero,
      //        move the cursor to the next columns (Remaining in the
      //        same row). Repeat the last step if necessary.
      ptr.row++;
      ptr.col++;

      bool is_checking_zero = true;
      while (is_checking_zero && ptr.row < row_size && ptr.col < col_size) {
        for (size_t i = ptr.row; i < row_size; i++) {
          if (data_[i][ptr.col] != 0) {
            is_checking_zero = false;
            break;
          }
        }
        if (is_checking_zero) {
          ptr.col++;
        }
      }

      // Return to step1.
    }

    return *this;
  }

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
  std::vector<T> RowSub(size_t row, const std::vector<T>& other_row_vector) {
    std::vector<T> row_vector(data_[row]);
    for (size_t i = 0; i < other_row_vector.size(); i++) {
      row_vector[i] -= other_row_vector[i];
    }
    return row_vector;
  }

  std::vector<T> RowMul(size_t row, T val) {
    std::vector<T> row_vector(data_[row]);
    for (auto& col : row_vector) {
      col *= val;
    }
    return row_vector;
  }

  std::vector<T> RowDiv(size_t row, T val) {
    std::vector<T> row_vector(data_[row]);
    for (auto& col : row_vector) {
      col /= val;
    }
    return row_vector;
  }

  std::vector<std::vector<T>> data_;
};

}  // namespace matricks

#endif  // MATRICKS_H_
