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

template <std::size_t W, std::size_t H>
class Matrix {
 public:
  Matrix(std::initializer_list<std::initializer_list<double>> list) {
    ASSERT(list.size() == H);

    for (int i = 0; i < H; i++) {
      std::initializer_list<double> L = *(list.begin() + i);
      data_[i] = make_array_impl(L, std::make_index_sequence<W>());
    }
  };

  [[nodiscard]] double const& get(std::size_t i, std::size_t j) const;
  double& get(std::size_t i, std::size_t j);

 private:
  template <std::size_t... i>
  std::array<double, W> make_array_impl(std::initializer_list<double> list,
                                        std::index_sequence<i...>) {
    ASSERT(list.size() == W);
    return std::array<double, W>({*(list.begin() + i)...});
  }

  std::array<std::array<double, W>, H> data_;
};

template <std::size_t W, std::size_t H>
double const& Matrix<W, H>::get(std::size_t i, std::size_t j) const {
  ASSERT(i >= 0 && i < H);
  ASSERT(j >= 0 && j < W);
  return this->data_[i][j];
}

template <std::size_t W, std::size_t H>
double& Matrix<W, H>::get(std::size_t i, std::size_t j) {
  ASSERT(i >= 0 && i < H);
  ASSERT(j >= 0 && j < W);
  return this->data_[i][j];
}

#endif  // TIGHTB_MATRIX_H
