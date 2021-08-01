//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_UTILITY_RECT_H_
#define BLOCK_V2_UTILITY_RECT_H_

#include "coord.h"
class Rect {
public:
  Rect();
  Rect(const Coord &position, unsigned int width, unsigned int height);

  bool CheckWBoundaries(const Coord& point);

Coord placement;
unsigned width;
unsigned height;

};

#endif // BLOCK_V2_UTILITY_RECT_H_
