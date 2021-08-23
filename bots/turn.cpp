//
// Created by studio25 on 29.07.2021.
//

#include "turn.h"
Turn::Turn() = default;

Turn::Turn(const Turn &other) : Bot(other) {
  movement_ = other.movement_;
  direction_ = other.direction_;
}

Turn &Turn::operator=(const Turn &other) {
  if (&other == this)
    return *this;
  movement_ = other.movement_;
  direction_ = other.direction_;
  return *this;
}

Turn *Turn::Clone() { return new Turn(*this); }

void Turn::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::TURN << " " << (unsigned)direction_ << "\n";
}

TurnDirection Turn::GetDirection() const { return direction_; }

BotType Turn::GetType() const { return type_; }

void Turn::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                      const Coord &bot_position,
                                      const unsigned plane_width,
                                      const unsigned plane_height,
                                      const Direction push_direction) {
  Coord pushing_block_position(NextPosition(push_direction, bot_position));

  Coord new_position =
      NextPosition(Rotate(push_direction, direction_), bot_position);

  plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
      plane, new_position, plane_width, plane_height, push_direction);
}
void Turn::ClearMovementDirection() { movement_.Clear(); }

Turn::Turn(TurnDirection direction) : direction_(direction) {}

void Turn::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                  unsigned int plane_width, unsigned int plane_height) {}

Transposition Turn::GetMovement() const { return movement_; }

void Turn::RotateCell() {
  switch (direction_) {
  case TurnDirection::CLOCKWISE:
    direction_ = TurnDirection::COUNTER_CLOCKWISE;
    return;
  case TurnDirection::COUNTER_CLOCKWISE:
    direction_ = TurnDirection::CLOCKWISE;
    return;
  }
}
