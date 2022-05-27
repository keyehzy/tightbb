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

#include <tightb/assert.h>

#include <cstdio>

void report_failure(const char *filename, int line, const char *fn_name,
                    const char *msg) {
  std::fprintf(stderr, "%s:%d: assertion failed in %s: %s\n", filename, line,
               fn_name, msg);
}
