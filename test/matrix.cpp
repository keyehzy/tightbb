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

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <tightb/matrix.h>

TEST(test_matrix, declaration) {
  Matrix<double, 2, 2> m{{1.0, 2.0}, {3.0, 4.0}};
}

TEST(test_matrix, accessor) {
  {
    Matrix<double, 2, 2> m{{1.0, 2.0}, {3.0, 4.0}};
    EXPECT_EQ(m.at(0, 0), 1.0);
    EXPECT_EQ(m.at(0, 1), 2.0);
    EXPECT_EQ(m.at(1, 0), 3.0);
    EXPECT_EQ(m.at(1, 1), 4.0);
    EXPECT_ANY_THROW(m.at(2, 2));
  }

  {
    Matrix<double, 2, 3> m{{1.0, 2.0, 3.0}, {3.0, 4.0, 5.0}};
    EXPECT_EQ(m.at(0, 0), 1.0);
    EXPECT_EQ(m.at(0, 1), 2.0);
    EXPECT_EQ(m.at(0, 2), 3.0);
    EXPECT_EQ(m.at(1, 0), 3.0);
    EXPECT_EQ(m.at(1, 1), 4.0);
    EXPECT_EQ(m.at(1, 2), 5.0);
    EXPECT_ANY_THROW(m.at(2, 3));
  }
}

TEST(test_matrix, add_matrices) {
  Matrix<double, 2, 2> m1{{1.0, 2.0}, {3.0, 4.0}};
  Matrix<double, 2, 2> m2{{4.0, 2.0}, {3.0, 1.0}};
  Matrix<double, 2, 2> res = m1 + m2;
  EXPECT_EQ(res.at(0, 0), 5.0);
  EXPECT_EQ(res.at(0, 1), 4.0);
  EXPECT_EQ(res.at(1, 0), 6.0);
  EXPECT_EQ(res.at(1, 1), 5.0);
}

TEST(test_matrix, subtract_matrices) {
  Matrix<double, 2, 2> m1{{1.0, 2.0}, {3.0, 4.0}};
  Matrix<double, 2, 2> m2{{4.0, 2.0}, {3.0, 1.0}};
  Matrix<double, 2, 2> res = m1 - m2;
  EXPECT_EQ(res.at(0, 0), -3.0);
  EXPECT_EQ(res.at(0, 1), 0.0);
  EXPECT_EQ(res.at(1, 0), 0.0);
  EXPECT_EQ(res.at(1, 1), 3.0);
}

TEST(test_matrix, comparison_between_matrices) {
  {
    Matrix<double, 2, 2> m1{{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double, 2, 2> m2{{1.0, 2.0}, {3.0, 4.0}};
    EXPECT_TRUE(m1 == m2);
  }

  {
    Matrix<double, 2, 2> m1{{1.0, 3.0}, {3.0, 4.0}};
    Matrix<double, 2, 2> m2{{1.0, 2.0}, {3.0, 4.0}};
    EXPECT_TRUE(m1 != m2);
  }
}

TEST(test_matrix, product_of_matrix_by_scalar) {
  Matrix<double, 2, 2> m{{1.0, 2.0}, {3.0, 4.0}};
  {
    Matrix<double, 2, 2> pm = 2.0 * m;
    EXPECT_EQ(pm.at(0, 0), 2.0);
    EXPECT_EQ(pm.at(0, 1), 4.0);
    EXPECT_EQ(pm.at(1, 0), 6.0);
    EXPECT_EQ(pm.at(1, 1), 8.0);
  }

  {
    Matrix<double, 2, 2> mp = m * 2.0;
    EXPECT_EQ(mp.at(0, 0), 2.0);
    EXPECT_EQ(mp.at(0, 1), 4.0);
    EXPECT_EQ(mp.at(1, 0), 6.0);
    EXPECT_EQ(mp.at(1, 1), 8.0);
  }
}

TEST(test_matrix, dimensions) {
  Matrix<double, 2, 3> m{{1.0, 2.0, 3.0}, {3.0, 4.0, 5.0}};
  EXPECT_EQ(m.rows(), 2);
  EXPECT_EQ(m.cols(), 3);
}
