//
// Created by studio25 on 29.07.2021.
//

#include "bot.h"
Coord NextPosition(Direction direction, const Coord &current_position) {
  switch (direction) {
  case Direction::UP:
    return {current_position.x, current_position.y - 1};
  case Direction::DOWN:
    return {current_position.x, current_position.y + 1};
  case Direction::LEFT:
    return {current_position.x - 1, current_position.y};
  case Direction::RIGHT:
    return {current_position.x + 1, current_position.y};
  }
}
Coord NextPosition(movement_direction::Direction direction,
                   const Coord &current_position) {
  switch (direction) {
  case movement_direction::Direction::NONE:
    return current_position;
  case movement_direction::Direction::UP:
    return {current_position.x, current_position.y - 1};
  case movement_direction::Direction::DOWN:
    return {current_position.x, current_position.y + 1};
  case movement_direction::Direction::LEFT:
    return {current_position.x - 1, current_position.y};
  case movement_direction::Direction::RIGHT:
    return {current_position.x + 1, current_position.y};
  case movement_direction::Direction::LOCK_HORIZONTAL:
  case movement_direction::Direction::LOCK_VERTICAL:
  case movement_direction::Direction::LOCK_GLOBAL:
    return current_position;
  case movement_direction::Direction::SIZE:
    assert(false);
    return Coord();
  }
}

