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
  return a ;
}
