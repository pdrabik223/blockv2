//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_UTILITY_COORD_H_
#define BLOCK_V2_UTILITY_COORD_H_

struct Coord {
  Coord(unsigned int x, unsigned int y);
  Coord();
  bool operator==(const Coord &rhs) const;
  bool operator!=(const Coord &rhs) const;
  unsigned ToInt(unsigned width)const { return y * width + x; }

  unsigned x;
  unsigned y;
};

#endif // BLOCK_V2_UTILITY_COORD_H_
