//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_UTILITY_COORD_H_
#define BLOCK_V2_UTILITY_COORD_H_

#include <cassert>
#include <ciso646>
#include <ostream>
struct Coord {
  Coord(unsigned int x, unsigned int y);
  Coord();
  Coord(const Coord& other);
  Coord& operator=(const Coord& other);

  bool operator==(const Coord &rhs) const;
  bool operator!=(const Coord &rhs) const;
  friend std::ostream &operator<<(std::ostream &os, const Coord &coord);

  unsigned ToInt(unsigned width)const {
    assert(x<width);
    return y * width + x;
  }

  unsigned x;
  unsigned y;
};

#endif // BLOCK_V2_UTILITY_COORD_H_
