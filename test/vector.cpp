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

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <tightb/vector.h>

using ::testing::ElementsAre;

TEST(test_vector, declaration) {
  Vec<2> v = {1.0, 2.0};
}

TEST(test_vector, add_two_vectors) {
  Vec<2> v1{1.0, 2.0};
  Vec<2> v2{2.0, 3.0};
  Vec<2> sum = v1 + v2;
  EXPECT_THAT(sum.data(), ElementsAre(3.0, 5.0));
}

TEST(test_vector, subtract_two_vectors) {
  Vec<2> v1{1.0, 2.0};
  Vec<2> v2{2.0, 3.0};
  Vec<2> sub = v1 - v2;
  EXPECT_THAT(sub.data(), ElementsAre(-1.0, -1.0));
}

// TODO(keyehzy): this operation can be implemented using BLAS
TEST(test_vector, dot_product_of_two_vectors) {
  Vec<2> v1{1.0, 2.0};
  Vec<2> v2{2.0, 3.0};
  double dot = v1.dot(v2);
  EXPECT_THAT(dot, 8.0);
}
