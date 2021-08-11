//
// Created by studio25 on 29.07.2021.
//

#include "engine.h"
Engine::Engine() = default;

Engine *Engine::Clone() { return new Engine(*this); }
void Engine::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::ENGINE << " " << (unsigned)direction_ << "\n";
}

Direction Engine::GetDirection() const { return direction_; }

BotType Engine::GetType() const { return type_; }

void Engine::LockEdge(const std::vector<Bot *> &plane,
                      const Coord &bot_position, const unsigned int plane_width,
                      const unsigned int plane_height,
                      Direction push_direction) {
  // calculate pushed cell position
  Coord new_position = NextPosition(push_direction, bot_position);

  // this cell is pushed in some direction,
  // that means it can't be pushed in the opposite
  movement_.LockEdge(push_direction);

  // if this cell is pushing the border of the map lock that direction
  if (new_position.x >= plane_width || new_position.x < 0 ||
      new_position.y >= plane_height || new_position.y < 0) {
    movement_.LockEdge(Opposite(push_direction));
    return;
  }
  // order the cell in front to do the same
  plane[new_position.ToInt(plane_width)]->LockEdge(
      plane, new_position, plane_width, plane_height, push_direction);
}

void Engine::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                        const Coord &bot_position,
                                        unsigned plane_width,
                                        unsigned plane_height,
                                        Direction push_direction) {

  Coord new_position = NextPosition(push_direction, bot_position);

  plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
      plane, new_position, plane_width, plane_height, push_direction);

  // if the next cell is "pushable" in the push_direction
  // this cell is pushable also in the push_direction
  if (plane[new_position.ToInt(plane_width)]->movement_.CheckDirection(
          push_direction))
    movement_.AddDirection(push_direction);
  else
    movement_.LockEdge(push_direction);
}

void Engine::ClearMovementDirection() {
  movement_.Clear();
  movement_.AddDirection(direction_);
  movement_.LockEdge(Opposite(direction_));
}

void Engine::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                    const unsigned plane_width, const unsigned plane_height) {
  Coord new_position = NextPosition(direction_, bot_position);

  plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
      plane, new_position, plane_width, plane_height, direction_);

  // if the next cell is "pushable" in the push_direction
  // this cell is pushable also in the push_direction
  if (plane[new_position.ToInt(plane_width)]->movement_.CheckDirection(
          direction_))
    movement_.AddDirection(direction_);
  else
    movement_.LockEdge(direction_);
}
Engine::Engine(const Engine &other) : Bot(other) {
  movement_ = other.movement_;
  direction_ = other.direction_;
}
Engine::Engine(Direction direction) : direction_(direction) {}
