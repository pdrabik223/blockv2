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
Coord::Coord(const Coord &other) {
  x = other.x;
  y = other.y;
}
Coord &Coord::operator=(const Coord &other) {
  if(this == &other) return *this;
  x = other.x;
  y = other.y;
  return *this;

}
std::ostream &operator<<(std::ostream &os, const Coord &coord) {
  os << "x: " << coord.x << " y: " << coord.y;
  return os;
}
