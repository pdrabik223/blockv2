//
// Created by studio25 on 29.07.2021.
//

#include "turn.h"
#include "engine.h"
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

void Turn::Push(const std::vector<Bot *> &plane, const Coord &bot_position,
                unsigned plane_width, unsigned plane_height,
                Direction push_direction) {
  Direction new_direction = RotateDirection(push_direction, direction_);

  Coord pusher_position = NextPosition(Opposite(push_direction), bot_position);

  Coord new_position = NextPosition(new_direction, pusher_position);

  plane[new_position.ToInt(plane_width)]->Push(plane, new_position, plane_width,
                                               plane_height, new_direction);

  if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
          new_direction))
    movement_.encounter_counter_[(int)push_direction] = TriState::UNDEFINED;
  else
    movement_.LockDirection(push_direction);

  if (direction_ == TurnDirection::CLOCKWISE)
    plane[pusher_position.ToInt(plane_width)]->SetRotation(90);

  if (direction_ == TurnDirection::COUNTER_CLOCKWISE)
    plane[pusher_position.ToInt(plane_width)]->SetRotation(-90);
}
void Turn::ClearMovementDirection() {
  //  movement_.Clear();
  movement_.LockDirection(Direction::LEFT);
  movement_.LockDirection(Direction::RIGHT);
  movement_.LockDirection(Direction::UP);
  movement_.LockDirection(Direction::DOWN);
}

Turn::Turn(TurnDirection direction) : direction_(direction) {}

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
void Turn::RotateCell(TurnDirection angle) { movement_.Rotate(angle); }

void Turn::ClearRotation() { movement_.ClearRotation(); }

void Turn::SetRotation(int angle) { movement_.rotation_angle_ = angle; }
void Turn::SetMovement(const Transposition &movement) { movement_ = movement; }
void Turn::SetDirection(TurnDirection direction) { direction_ = direction; }
