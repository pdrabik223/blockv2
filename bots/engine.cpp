//
// Created by studio25 on 29.07.2021.
//

#include "engine.h"
Engine::Engine() = default;

Engine::Engine(const Engine &other) : Bot(other) {
  movement_ = other.movement_;
  direction_ = other.direction_;
}

Engine &Engine::operator=(const Engine& other) {
  if(&other == this) return *this;
  movement_ = other.movement_;
  direction_ = other.direction_;
  return *this;
}

Engine *Engine::Clone() { return new Engine(*this); }

void Engine::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::ENGINE << " " << (unsigned)direction_ << "\n";
}

Direction Engine::GetDirection() const { return direction_; }

BotType Engine::GetType() const { return type_; }

void Engine::Push(const std::vector<Bot *> &plane,
                                        const Coord &bot_position,
                                        unsigned plane_width,
                                        unsigned plane_height,
                                        Direction push_direction) {

  Coord new_position = NextPosition(push_direction, bot_position);

  plane[new_position.ToInt(plane_width)]->Push(plane, new_position, plane_width,
                                               plane_height, push_direction);

  // if the next cell is "pushable" in the push_direction
  // this cell is pushable also in the push_direction
  if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
          push_direction))
    movement_.AddDirection(push_direction);
  else
    movement_.LockDirection(push_direction);
}

void Engine::ClearMovementDirection() {
  movement_.Clear();
  movement_.AddDirection(direction_);
  movement_.LockDirection(Opposite(direction_));
}

void Engine::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                    const unsigned plane_width, const unsigned plane_height) {
  Coord new_position = NextPosition(direction_, bot_position);

  plane[new_position.ToInt(plane_width)]->Push(plane, new_position, plane_width,
                                               plane_height, direction_);

  // if the next cell is "pushable" in the push_direction
  // this cell is pushable also in the push_direction
  if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(direction_))
    movement_.AddDirection(direction_);
  else
    movement_.LockDirection(direction_);


}

Engine::Engine(Direction direction) : direction_(direction) {}

Transposition Engine::GetMovement() const { return movement_; }
void Engine::RotateCell() {
  switch (direction_) {
  case Direction::UP:
    direction_ = Direction::RIGHT;
    return;
  case Direction::DOWN:
    direction_ = Direction::LEFT;
    return;
  case Direction::LEFT:
    direction_ = Direction::UP;
    return;
  case Direction::RIGHT:
    direction_ = Direction::DOWN;
    return;
  }
}

