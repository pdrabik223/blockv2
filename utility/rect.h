//
// Created by studio25 on 01.08.2021.
//
/// describes rectangle that can not be rotated
#ifndef BLOCK_V2_UTILITY_RECT_H_
#define BLOCK_V2_UTILITY_RECT_H_

#include "coord.h"
struct Rect {
  Rect();
  Rect(const Coord &position, unsigned int width, unsigned int height);
  Rect(const Rect &other);
  Rect &operator=(const Rect &other);

  void SetPlacement(const Coord &placement);

  /// checks whether point lies inside boundaries of rectangle
  /// \param point tested point
  /// \return true if point lies inside this rectangle, false if not
  bool CheckWBoundaries(const Coord &point) const;

  /// top right corner of Rectangle described in 2d space
  Coord placement;
  unsigned width;
  unsigned height;
};

#endif // BLOCK_V2_UTILITY_RECT_H_
