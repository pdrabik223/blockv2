//
// Created by studio25 on 08.08.2021.
//

#include "movement_direction.h"
using namespace movement_direction;
///
/// \param a first argument
/// \param b second argument
/// \return sum of it's arguments, following the <a href="../README.md">truth table</a>




Direction operator+(const Direction &a, const Direction &b) {

  if(a == b) return a;

  if (a == Direction::NONE) {
    return b;
  }

}
