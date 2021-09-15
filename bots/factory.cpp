//
// Created by studio25 on 29.07.2021.
//

#include "factory.h"
Factory::Factory() = default;

Factory &Factory::operator=(const Factory &other) {
  if (&other == this)
    return *this;
  movement_ = other.movement_;
  direction_ = other.direction_;
  return *this;
}

Factory *Factory::Clone() { return new Factory(*this); }

void Factory::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::FACTORY << " " << (unsigned)direction_ << "\n";
}

Direction Factory::GetDirection() const { return direction_; }

BotType Factory::GetType() const { return type_; }

void Factory::Push(const std::vector<Bot *> &plane, const Coord &bot_position,
                   unsigned plane_width, unsigned plane_height,
                   Direction push_direction) {

  if (direction_ == push_direction or push_direction == Opposite(direction_)) {

    return;
  }

  Coord new_position = NextPosition(push_direction, bot_position);

  plane[new_position.ToInt(plane_width)]->Push(plane, new_position, plane_width,
                                               plane_height, push_direction);

  // if the next cell is "pushable" in the push_direction
  // this cell is pushable also in the push_direction
  if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
          push_direction))
    movement_.Push(push_direction);
  else
    movement_.LockDirection(push_direction);
}

void Factory::ClearMovementDirection() {
  movement_.Clear();
  movement_.LockDirection(direction_);
  movement_.LockDirection(Opposite(direction_));
}

Factory::Factory(const Factory &other) : Bot(other) {
  movement_ = other.movement_;
  direction_ = other.direction_;
}

Factory::Factory(Direction direction) : direction_(direction) {}

void Factory::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                     const unsigned int plane_width,
                     const unsigned int plane_height) {
  Coord new_position = NextPosition(direction_, bot_position);

  plane[new_position.ToInt(plane_width)]->Push(plane, new_position, plane_width,
                                               plane_height, direction_);
}

Transposition Factory::GetMovement() const { return movement_; }

void Factory::RotateCell() {
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
void Factory::SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                           unsigned int plane_width,
                           unsigned int plane_height) {
  Coord target = NextPosition(direction_, bot_position);
  Coord original = NextPosition(Opposite(direction_), bot_position);

  if (plane[target.ToInt(plane_width)]->GetType() == BotType::EMPTY) {
    delete plane[target.ToInt(plane_width)];
    plane[target.ToInt(plane_width)] =
        plane[original.ToInt(plane_width)]->Clone();
  }
}

void Factory::RotateCell(TurnDirection angle) {
  switch (angle) {
  case TurnDirection::CLOCKWISE:
    RotateCell();
    break;
  case TurnDirection::COUNTER_CLOCKWISE:
    RotateCell();
    RotateCell();
    RotateCell();
    break;
  }

  movement_.Rotate(angle);
}
void Factory::ClearRotation() { movement_.ClearRotation(); }

void Factory::SetRotation(int angle) { movement_.rotation_angle_ = angle; }
void Factory::SetMovement(const Transposition &movement) {
  movement_ = movement;
}
void Factory::SetDirection(Direction direction) { direction_ = direction; }
