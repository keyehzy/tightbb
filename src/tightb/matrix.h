// tightb - calculate electronic properties of solids
// Copyright (C) 2022  Matheus de Sousa (keyehzy)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef TIGHTB_MATRIX_H
#define TIGHTB_MATRIX_H

#include <tightb/assert.h>

#include <array>

template <typename T, std::size_t W, std::size_t H>
class Matrix {
 public:
  Matrix() = default;

  Matrix(std::initializer_list<std::initializer_list<T>> list) {
    ASSERT(list.size() == H);

    for (int i = 0; i < H; i++) {
      std::initializer_list<T> L = *(list.begin() + i);
      data_[i] = make_array_impl(L, std::make_index_sequence<W>());
    }
  };

  [[nodiscard]] T const& get(std::size_t i, std::size_t j) const;

  T& get(std::size_t i, std::size_t j);

  Matrix<T, W, H> operator+(Matrix<T, W, H> const& m) const;

  Matrix<T, W, H> operator-(Matrix<T, W, H> const& m) const;

 private:
  template <std::size_t... i>
  std::array<T, W> make_array_impl(std::initializer_list<T> list,
                                   std::index_sequence<i...>) {
    ASSERT(list.size() == W);
    return std::array<T, W>({*(list.begin() + i)...});
  }

  std::array<std::array<T, W>, H> data_;
};

template <typename T, std::size_t W, std::size_t H>
T const& Matrix<T, W, H>::get(std::size_t i, std::size_t j) const {
  return this->data_.at(i).at(j);
}

template <typename T, std::size_t W, std::size_t H>
T& Matrix<T, W, H>::get(std::size_t i, std::size_t j) {
  return this->data_.at(i).at(j);
}
template <typename T, std::size_t W, std::size_t H>
Matrix<T, W, H> Matrix<T, W, H>::operator+(const Matrix<T, W, H>& m) const {
  Matrix<T, W, H> new_m{};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      new_m.get(i, j) = this->get(i, j) + m.get(i, j);
    }
  }
  return new_m;
}
template <typename T, std::size_t W, std::size_t H>
Matrix<T, W, H> Matrix<T, W, H>::operator-(const Matrix<T, W, H>& m) const {
  Matrix<T, W, H> new_m{};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      new_m.get(i, j) = this->get(i, j) - m.get(i, j);
    }
  }
  return new_m;
}

#endif  // TIGHTB_MATRIX_H
