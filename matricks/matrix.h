#ifndef MATRICKS_H_
#define MATRICKS_H_

#include <iostream>
#include <initializer_list>
#include <vector>
#include "fraction.h"

namespace matricks {

template <size_t row_size, size_t col_size>
class Matrix {
 public:
  Matrix(std::initializer_list<std::initializer_list<Fraction>> init_list) {
    // TODO: size check should be performed at compile-time, not at runtime,
    // but std::initializer_list::size() is a horrible piece of shit because
    // for some reason it's not constexpr. See:
    // https://stackoverflow.com/questions/5438671/static-assert-on-initializer-listsize
    if (init_list.size() > row_size) {
      throw std::length_error("Illegal matrix row_size");
    }

    data_.reserve(row_size);
    for (const auto& row : init_list) {
      if (row.size() > col_size) {
        throw std::length_error("Illegal matrix col_size");
      }
      data_.push_back({});
      data_.back().reserve(col_size);
      for (const auto& col : row) {
        data_.back().push_back(col);
      }
    }
  }

  virtual ~Matrix() = default;


  struct Cursor {
    Cursor() : row(), col() {}
    size_t row;
    size_t col;
  };

  Matrix<row_size, col_size>& Rref() {
    // Place a cursor in the top entry of the first non-zero column
    // of this matrix.
    // TODO: what if the elements in the first row are all zeroes?
    Matrix::Cursor cursor;
    for (const auto& col : data_[0]) {
      if (col == 0) {
        cursor.col++;
      }
    }

    while (cursor.row < row_size && cursor.col < col_size) {
      // Step1. If the cursor entry is zero, swap the cursor row with
      //        some row below to make the cursor entry non-zero.
      if (data_[cursor.row][cursor.col] == 0) {
        for (size_t i = 1; i < row_size; i++) {
          if (data_[i][cursor.col] != 0) {
            std::swap(data_[cursor.row], data_[i]);
          }
        }
      }

      // Step2: Divide the cursor row by the cursor entry
      data_[cursor.row] = RowDiv(cursor.row, data_[cursor.row][cursor.col]);

      // Step3: Eliminate all other entries in the cursor column, by
      //        subtracting suitable multiples of the cursor row from
      //        the other rows.
      for (size_t i = 0; i < row_size; i++) {
        Fraction cursor_entry = data_[cursor.row][cursor.col];
        Fraction current_entry = data_[i][cursor.col];

        if (current_entry == 0 || i == cursor.row) {
          continue;
        }
        data_[i] = RowSub(i, RowMul(cursor.row, current_entry / cursor_entry));
      }

      // Step4: Move the cursor one row down and one column to the right.
      //        If the new cursor entry and all entries below are zero,
      //        move the cursor to the next columns (Remaining in the
      //        same row). Repeat the last step if necessary.
      cursor.row++;
      cursor.col++;

      bool is_checking_zero = true;
      while (is_checking_zero && cursor.row < row_size && cursor.col < col_size) {
        for (size_t i = cursor.row; i < row_size; i++) {
          if (data_[i][cursor.col] != 0) {
            is_checking_zero = false;
            break;
          }
        }
        if (is_checking_zero) {
          cursor.col++;
        }
      }

      // Return to step1.
    }

    return *this;
  }

  friend std::ostream& operator <<(std::ostream& os, const Matrix& m) {
    for (const auto& row : m.data_) {
      for (const auto& col : row) {
        std::cout << col << " ";
      }
      std::cout << std::endl;
    }
    return os;
  }

 private:
  std::vector<Fraction> RowSub(size_t row, const std::vector<Fraction>& other_row_vector) {
    std::vector<Fraction> row_vector(data_[row]);
    for (size_t i = 0; i < other_row_vector.size(); i++) {
      row_vector[i] -= other_row_vector[i];
    }
    return row_vector;
  }

  std::vector<Fraction> RowMul(size_t row, Fraction val) {
    std::vector<Fraction> row_vector(data_[row]);
    for (auto& col : row_vector) {
      col *= val;
    }
    return row_vector;
  }

  std::vector<Fraction> RowDiv(size_t row, Fraction val) {
    std::vector<Fraction> row_vector(data_[row]);
    for (auto& col : row_vector) {
      col /= val;
    }
    return row_vector;
  }

  std::vector<std::vector<Fraction>> data_;
};

}  // namespace matricks

#endif  // MATRICKS_H_
