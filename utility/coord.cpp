//
// Created by studio25 on 29.07.2021.
//

#include "coord.h"
Coord::Coord(unsigned int x, unsigned int y) : x(x), y(y) {}
Coord::Coord(): x(0), y(0) {}
bool Coord::operator==(const Coord &rhs) const {
  return x == rhs.x && y == rhs.y;
}
bool Coord::operator!=(const Coord &rhs) const { return !(rhs == *this); }