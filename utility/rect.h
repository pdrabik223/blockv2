//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_UTILITY_RECT_H_
#define BLOCK_V2_UTILITY_RECT_H_

#include "coord.h"
struct Rect {
  Rect();
  Rect(const Coord &position, unsigned int width, unsigned int height);
  Rect(const Rect &other);
  Rect&  operator=(const Rect &other);

  bool CheckWBoundaries(const Coord& point) const;

Coord placement;
unsigned width;
unsigned height;

};

#endif // BLOCK_V2_UTILITY_RECT_H_
