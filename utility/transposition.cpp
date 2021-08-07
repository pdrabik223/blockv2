//
// Created by studio25 on 29.07.2021.
//

#include "transposition.h"
#include <iostream>

Direction Transposition::GetMovementDirection() const {
  if (from.x == to.x) {
    if (from.y > to.y)
      return Direction::UP; /*   UP = 0    */
    else                       /*   DOWN = 1  */
      return Direction::DOWN;  /*   LEFT = 2  */
  } else {                     /*   RIGHT = 3 */
    if (from.x < to.x)
      return Direction::LEFT;
    else
      return Direction::RIGHT;
  }
  assert(false);
}
Transposition::Transposition(unsigned int from, unsigned int to, const Bot *bot,
                             unsigned matrix_width)
    : from(from % matrix_width, from / matrix_width),
      to(to % matrix_width, to / matrix_width), bot(new Bot(*bot)) {
  assert(this->from.x == this->to.x xor this->from.y == this->to.y);
  assert(from != to);
}
