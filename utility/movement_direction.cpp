//
// Created by studio25 on 08.08.2021.
//

#include "movement_direction.h"

movement_direction::Direction
movement_direction::operator+(const movement_direction::Direction &a,
                              const movement_direction::Direction &b) {
  return truth_table[(unsigned)a][(unsigned)b];
}

movement_direction::Direction &
movement_direction::operator+=(movement_direction::Direction &a,
                               const movement_direction::Direction &b) {
  a = truth_table[(unsigned)a][(unsigned)b];
  return a;
}
movement_direction::Direction
movement_direction::LockAxis(const movement_direction::Direction &locked_direction) {

  if (locked_direction == movement_direction::Direction::LEFT or
      locked_direction == movement_direction::Direction::RIGHT)
    return movement_direction::Direction::LOCK_HORIZONTAL;
  if (locked_direction == movement_direction::Direction::UP or
      locked_direction == movement_direction::Direction::DOWN)
    return movement_direction::Direction::LOCK_VERTICAL;

  assert(false);
  return movement_direction::Direction(locked_direction);
}
