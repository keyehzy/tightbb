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

#ifndef TIGHTB_ASSERT_H
#define TIGHTB_ASSERT_H

#include <cassert>

#define ASSERT(cond, ...)                                         \
  do {                                                            \
    if (!(cond)) {                                                \
      report_failure(__FILE__, __LINE__, __func__, #__VA_ARGS__); \
      __builtin_trap();                                           \
    }                                                             \
  } while (false)

#define UNREACHABLE() ASSERT(false)
#define ERROR(...) ASSERT(false, __VA_ARGS__)

void report_failure(const char *filename, int line, const char *function_name,
                    const char *message);

#endif  // TIGHTB_ASSERT_H
