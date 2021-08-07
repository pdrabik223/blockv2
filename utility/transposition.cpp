//
// Created by studio25 on 29.07.2021.
//

#include "transposition.h"

Direction Transposition::GetMovementDirection(unsigned matrix_width) const {
  assert(from != to);

  if (from.y == to.y) {
    if (from.x < to.x)
      return Direction::RIGHT;
    else
      return Direction::LEFT;
  } else if (from.x == to.x) {
    if (from.y < to.y)
      return Direction::DOWN;
    else
      return Direction::UP;
  }
  assert(false);
}
Transposition::Transposition(unsigned int from, unsigned int to, const Bot *bot,
                             unsigned matrix_width)
                             : from(from % matrix_width, from / matrix_width),
                             to(to % matrix_width, to / matrix_width), bot(new Bot(*bot)) {
  assert(this->from.x == this->to.x xor this->from.y == this->to.y);
}
