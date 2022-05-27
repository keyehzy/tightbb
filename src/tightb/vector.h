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

#include <array>

template<int S>
class Vec {
public:
    Vec(const std::initializer_list<double> &list) : data_(list) {};

    explicit Vec(int i) : data_(i) {};

    double &operator[](int i);

    Vec<S> operator+(Vec<S> v) const;

    Vec<S> operator-(Vec<S> v) const;

    [[nodiscard]] double dot(Vec<S> v) const;

    [[nodiscard]] double norm() const;

    [[nodiscard]] std::vector<double> data() const { return this->data_; }

private:
    std::vector<double> data_;
};

template<int S>
double &Vec<S>::operator[](int i) {
  assert(i >= 0 && i < S);
  return this->data_[i];
}

template<int S>
Vec<S> Vec<S>::operator+(Vec<S> v) const {
  Vec<S> new_v(S);

  for (int i = 0; i < S; i++) {
    new_v[i] = this->data_[i] + v[i];
  }

  return new_v;
}

template<int S>
Vec<S> Vec<S>::operator-(Vec<S> v) const {
  Vec<S> new_v(S);

  for (int i = 0; i < S; i++) {
    new_v[i] = this->data_[i] - v[i];
  }

  return new_v;
}

template<int S>
double Vec<S>::dot(Vec<S> v) const {
  double dot = 0.0;

  for (int i = 0; i < S; i++) {
    dot += this->data_[i] * v[i];
  }

  return dot;
}

template<int S>
double Vec<S>::norm() const {
  double dot = this->dot(*this);
  return sqrt(dot);
}

#endif //TIGHTB_VECTOR_H
