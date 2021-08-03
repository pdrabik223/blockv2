//
// Created by studio25 on 01.08.2021.
//

#include "rect.h"

Rect::Rect(const Coord &position, unsigned int width, unsigned int height)
    : placement(position), width(width), height(height) {}

bool Rect::CheckWBoundaries(const Coord &point) const {


  if (point.x < placement.x || point.y < placement.y)
    return false;

  if (point.x - placement.x > width || point.y - placement.y > height)
    return false;

  return true;
}

Rect::Rect() : placement(), width(0), height(0) {}
