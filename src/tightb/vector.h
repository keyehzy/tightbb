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
#include <ostream>

template<int S>
class Vec {
public:
    Vec(const std::initializer_list<double> &list) : data_(list) {};

    explicit Vec(int i) : data_(i) {};

    double &operator[](int i);

    double operator[](int i) const;

    Vec<S> operator+(Vec<S> const &v) const;

    Vec<S> operator-(Vec<S> const &v) const;

    bool operator==(Vec<S> const &v) const;

    bool operator!=(Vec<S> const &v) const;

    [[nodiscard]] double dot(Vec<S> const &v) const;

    [[nodiscard]] double norm() const;

    Vec<S> operator*(double p) const;

    Vec<S> proj(Vec<S> const &v) const;

    [[nodiscard]] std::vector<double> data() const { return this->data_; }

    [[nodiscard]] int size() const { return this->data_.size(); }

private:
    std::vector<double> data_;
};

template<int S>
double &Vec<S>::operator[](int i) {
  assert(i >= 0 && i < S);
  return this->data_[i];
}

template<int S>
double Vec<S>::operator[](int i) const {
  assert(i >= 0 && i < S);
  return this->data_[i];
}

template<int S>
Vec<S> Vec<S>::operator+(Vec<S> const &v) const {
  Vec<S> new_v(S);

  for (int i = 0; i < S; i++) {
    new_v[i] = this->data_[i] + v[i];
  }

  return new_v;
}

template<int S>
Vec<S> Vec<S>::operator-(Vec<S> const &v) const {
  Vec<S> new_v(S);

  for (int i = 0; i < S; i++) {
    new_v[i] = this->data_[i] - v[i];
  }

  return new_v;
}

template<int S>
double Vec<S>::dot(Vec<S> const &v) const {
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

template<int S>
Vec<S> Vec<S>::operator*(double p) const {
  Vec<S> new_v(S);

  for (int i = 0; i < S; i++) {
    new_v[i] = p * this->data_[i];
  }

  return new_v;
}

template<int S>
Vec<S> operator*(double p, Vec<S> const &v) {
  return v * p;
}

template<int S>
Vec<S> Vec<S>::proj(Vec<S> const &v) const {
  double scalar_projection = this->dot(v) / v.dot(v);
  return scalar_projection * v;
}

template<int S>
bool Vec<S>::operator==(const Vec<S> &v) const {
  for (int i = 0; i < S; i++) {
    if (this->data_[i] != v[i])
      return false;
    return true;
  }
}

template<int S>
bool Vec<S>::operator!=(const Vec<S> &v) const {
  bool ok = *this == v;
  return !ok;
}

template<int S>
std::ostream &operator<<(std::ostream &os, Vec<S> const &v) {
  os << "[Vec(" << v.size() << "),";
  os << " {";
  for (int i = 0; i < v.size(); i++) {
    os << v[i];
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "}]";
  return os;
}

#endif //TIGHTB_VECTOR_H
