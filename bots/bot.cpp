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
void Bot::CalculateMovementDirection(const std::vector<Bot *> &plane, const Coord &bot_position,
    const unsigned int plane_width, const unsigned int plane_height,
    const Direction push_direction) { }
