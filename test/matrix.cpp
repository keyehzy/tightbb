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

TEST(test_matrix, declaration) { Matrix<2, 2> m{{1.0, 2.0}, {3.0, 4.0}}; }

TEST(test_matrix, acessor) {
  Matrix<2, 2> m{{1.0, 2.0}, {3.0, 4.0}};
  EXPECT_EQ(m.get(0, 0), 1.0);
  EXPECT_EQ(m.get(0, 1), 2.0);
  EXPECT_EQ(m.get(1, 0), 3.0);
  EXPECT_EQ(m.get(1, 1), 4.0);
}