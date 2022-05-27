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

#ifndef TIGHTB_VECTOR_H
#define TIGHTB_VECTOR_H

#include <tightb/assert.h>

#include <array>
#include <cmath>
#include <ostream>

template <typename T, std::size_t S>
class Vec {
 public:
  Vec() = default;
  Vec(const std::initializer_list<T> &list)
      : Vec(list, std::make_index_sequence<S>()) {
    ASSERT(list.size() == S);
  };

  template <typename... U>
  explicit Vec(U &&...u) : data_({std::forward<U>(u)...}) {}

  T &operator[](int i);

  T const &operator[](int i) const;

  Vec<T, S> operator+(Vec<T, S> const &v) const;

  Vec<T, S> operator-(Vec<T, S> const &v) const;

  template <typename U>
  Vec<T, S> operator*(U p) const;

  bool operator==(Vec<T, S> const &v) const;

  bool operator!=(Vec<T, S> const &v) const;

  double dot(Vec<T, S> const &v) const;

  [[nodiscard]] std::array<T, S> data() const { return this->data_; }

  [[nodiscard]] std::size_t size() const { return this->data_.size(); }

 private:
  template <std::size_t... i>
  Vec(const std::initializer_list<T> &list, std::index_sequence<i...>)
      : data_({*(list.begin() + i)...}) {}

  std::array<T, S> data_;
};

template <typename T, std::size_t S>
T &Vec<T, S>::operator[](int i) {
  return this->data_.at(i);
}

template <typename T, std::size_t S>
T const &Vec<T, S>::operator[](int i) const {
  return this->data_.at(i);
}

template <typename T, std::size_t S>
Vec<T, S> Vec<T, S>::operator+(Vec<T, S> const &v) const {
  Vec<T, S> new_v{};

  for (int i = 0; i < S; i++) {
    new_v[i] = this->data_[i] + v[i];
  }

  return new_v;
}

template <typename T, std::size_t S>
Vec<T, S> Vec<T, S>::operator-(Vec<T, S> const &v) const {
  Vec<T, S> new_v{};

  for (int i = 0; i < S; i++) {
    new_v[i] = this->data_[i] - v[i];
  }

  return new_v;
}

template <typename T, std::size_t S>
double Vec<T, S>::dot(Vec<T, S> const &v) const {
  double dot = 0.0;

  for (int i = 0; i < S; i++) {
    dot += this->data_[i] * v[i];
  }

  return dot;
}

template <typename T, std::size_t S>
template <typename U>
Vec<T, S> Vec<T, S>::operator*(U p) const {
  Vec<T, S> new_v{};

  for (int i = 0; i < S; i++) {
    new_v[i] = p * this->data_[i];
  }

  return new_v;
}

template <typename T, typename U, std::size_t S>
Vec<T, S> operator*(U p, Vec<T, S> const &v) {
  return v * p;
}

template <typename T, std::size_t S>
bool Vec<T, S>::operator==(const Vec<T, S> &v) const {
  for (int i = 0; i < S; i++) {
    if (this->data_[i] != v[i]) return false;
  }
  return true;
}

template <typename T, std::size_t S>
bool Vec<T, S>::operator!=(const Vec<T, S> &v) const {
  bool ok = *this == v;
  return !ok;
}

template <typename T, std::size_t S>
std::ostream &operator<<(std::ostream &os, Vec<T, S> const &v) {
  os << "[Vec(" << v.size() << "),";
  os << " {";
  for (int i = 0; i < v.size(); i++) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "}]";
  return os;
}

#endif  // TIGHTB_VECTOR_H
