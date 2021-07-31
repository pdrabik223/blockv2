//
// Created by studio25 on 01.08.2021.
//

#include "rect.h"
Rect::Rect(const Coord &position, unsigned int width, unsigned int height)
    : position(position), width(width), height(height) {}
bool Rect::CheckWBoundaries(Coord point) {
  if (point.x < position.x || point.y < position.y)
    return false;
  if (point.x - position.x > width || point.y - position.y > height)
    return false;
  return true;
}
