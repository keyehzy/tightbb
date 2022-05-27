# tightb - calculate electronic properties of solids
# Copyright (C) 2022  Matheus de Sousa (keyehzy)

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.23)

add_executable(tightb main.cpp)

set_target_properties(tightb PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
target_link_libraries(tightb PRIVATE tightb-lib)
add_library(
        tightb-lib
        vector.cpp
        tightb/vector.h graph.cpp tightb/graph.h assert.cpp tightb/assert.h)
target_include_directories(tightb-lib PUBLIC .)
