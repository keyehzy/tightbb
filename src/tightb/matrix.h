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

template <typename T, std::size_t H, std::size_t W>
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

  [[nodiscard]] T const& at(std::size_t i, std::size_t j) const;

  T& at(std::size_t i, std::size_t j);

  Matrix<T, H, W> operator+(Matrix<T, H, W> const& m) const;

  Matrix<T, H, W> operator-(Matrix<T, H, W> const& m) const;

  bool operator==(Matrix<T, H, W> const& m) const;

  bool operator!=(Matrix<T, H, W> const& m) const;

  std::array<std::array<T, W>, H> const& data() const { return this->data_; }

  template <typename U>
  Matrix<T, H, W> operator*(U p) const;

  [[nodiscard]] std::size_t rows() const { return H; }

  [[nodiscard]] std::size_t cols() const { return W; }

 private:
  template <std::size_t... i>
  std::array<T, W> make_array_impl(std::initializer_list<T> list,
                                   std::index_sequence<i...>) {
    ASSERT(list.size() == W);
    return std::array<T, W>({*(list.begin() + i)...});
  }

  std::array<std::array<T, W>, H> data_;
};

template <typename T, std::size_t H, std::size_t W>
T const& Matrix<T, H, W>::at(std::size_t i, std::size_t j) const {
  return this->data_.at(i).at(j);
}

template <typename T, std::size_t H, std::size_t W>
T& Matrix<T, H, W>::at(std::size_t i, std::size_t j) {
  return this->data_.at(i).at(j);
}

template <typename T, std::size_t H, std::size_t W>
Matrix<T, H, W> Matrix<T, H, W>::operator+(const Matrix<T, H, W>& m) const {
  Matrix<T, H, W> new_m{};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      new_m.at(i, j) = this->at(i, j) + m.at(i, j);
    }
  }
  return new_m;
}

template <typename T, std::size_t H, std::size_t W>
Matrix<T, H, W> Matrix<T, H, W>::operator-(const Matrix<T, H, W>& m) const {
  Matrix<T, H, W> new_m{};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      new_m.at(i, j) = this->at(i, j) - m.at(i, j);
    }
  }
  return new_m;
}
template <typename T, std::size_t H, std::size_t W>
bool Matrix<T, H, W>::operator==(const Matrix<T, H, W>& m) const {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (this->at(i, j) != m.at(i, j)) return false;
    }
  }
  return true;
}
template <typename T, std::size_t H, std::size_t W>
bool Matrix<T, H, W>::operator!=(const Matrix<T, H, W>& m) const {
  bool ok = *this == m;
  return !ok;
}
template <typename T, std::size_t H, std::size_t W>
template <typename U>
Matrix<T, H, W> Matrix<T, H, W>::operator*(U p) const {
  Matrix<T, H, W> new_m{};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      new_m.at(i, j) = p * this->at(i, j);
    }
  }
  return new_m;
}

template <typename T, std::size_t H, std::size_t W, typename U>
Matrix<T, H, W> operator*(U p, Matrix<T, H, W> m) {
  return m * p;
}

#endif  // TIGHTB_MATRIX_H
