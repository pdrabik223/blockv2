//
// Created by studio25 on 29.07.2021.
//

#include "engine.h"
Engine::Engine(const Coord &position, Direction direction)
    : position_(position), direction_(direction) {}
Engine::Engine() = default;

Engine *Engine::Clone() { return this; }
void Engine::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::ENGINE << " " << (unsigned)direction_ << "\n";
}

Direction Engine::GetDirection() const { return direction_; }

BotType Engine::GetType() const { return type_; }

void Engine::CalculateMovementDirection(
    const std::vector<Bot *> &plane, const Coord &bot_position,
    const unsigned plane_width, const unsigned plane_height,
                                        const Direction push_direction) {
  Coord new_position = GenPosition(push_direction, bot_position);

  if (new_position.x >= plane_width || new_position.x < 0 ||
  new_position.y >= plane_height || new_position.y < 0) {
    this->movement_direction_ =
        movement_direction::LockAxis((movement_direction::Direction)push_direction);
    return;
  }
  plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
      plane, new_position, plane_width, plane_height,push_direction);

  if (IsPossible(movement_direction::Direction((int)push_direction + 1),
                 plane[new_position.ToInt(plane_width)]->movement_direction_))
    this->movement_direction_ +=
        movement_direction::Direction((int)push_direction + 1);
  else
    this->movement_direction_ +=
        LockAxis(movement_direction::Direction((int)push_direction + 1));

}
void Engine::ClearMovementDirection() {
  this->movement_direction_ =
      movement_direction::Direction((int)direction_ + 1);
}
void Engine::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                    const unsigned plane_width, const unsigned plane_height) {
  Coord new_position = GenPosition(direction_, bot_position);

  if (new_position.x >= plane_width || new_position.x < 0 ||
  new_position.y >= plane_height || new_position.y < 0) {
    this->movement_direction_ =
        movement_direction::LockAxis((movement_direction::Direction)direction_);
    return;
  }

  plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
      plane, new_position, plane_width, plane_height,direction_);

  if (IsPossible(movement_direction::Direction((int)direction_ + 1),
                 plane[new_position.ToInt(plane_width)]->movement_direction_))
    this->movement_direction_ +=
        movement_direction::Direction((int)direction_ + 1);
  else
    this->movement_direction_ +=
        LockAxis(movement_direction::Direction((int)direction_ + 1));}
