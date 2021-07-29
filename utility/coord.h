//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_UTILITY_COORD_H_
#define BLOCK_V2_UTILITY_COORD_H_

class Coord{
public:
  Coord(unsigned int x, unsigned int y);
  Coord();
  bool operator==(const Coord &rhs) const;
  bool operator!=(const Coord &rhs) const;

  unsigned x;
  unsigned y;

};

#endif // BLOCK_V2_UTILITY_COORD_H_
