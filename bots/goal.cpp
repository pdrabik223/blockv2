//
// Created by studio25 on 29.07.2021.
//

#include "goal.h"

Goal::Goal() = default;

Goal::Goal(const Goal &other) : Bot(other) { movement_ = other.movement_; }

Goal &Goal::operator=(const Goal &other) {
  if (&other == this)
    return *this;
  movement_ = other.movement_;
  return *this;
}
Goal *Goal::Clone() { return new Goal(*this); }

void Goal::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::GOAL << "\n";
}
BotType Goal::GetType() const { return type_; }

void Goal::Push(const std::vector<Bot *> &plane, const Coord &bot_position,
                unsigned plane_width, unsigned plane_height,
                Direction push_direction) {
  Coord new_position = NextPosition(push_direction, bot_position);
  Coord pusher_position = NextPosition(Opposite(push_direction), bot_position);

  switch (plane[pusher_position.ToInt(plane_width)]->GetType()) {

  case BotType::BASIC:
  case BotType::GOAL:
  case BotType::FACTORY:
    // act normal
    plane[new_position.ToInt(plane_width)]->Push(
        plane, new_position, plane_width, plane_height, push_direction);

    if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
            push_direction)) {
      movement_.Push(push_direction);
    }
    break;
  case BotType::BEDROCK:
  case BotType::TURN:
  case BotType::TP:
  case BotType::EMPTY:
    // those block can't push
    assert("un-pushable block");
  case BotType::ENEMY:
  case BotType::ENGINE:
    // get killed by those
    movement_.LockDirection(Opposite(push_direction));
    break;
  case BotType::NONE:
  case BotType::SIZE:
    assert("incorrect memory assigment");
  }
}

void Goal::ClearMovementDirection() { movement_.Clear(); }
Transposition Goal::GetMovement() const { return movement_; }
void Goal::RotateCell(int angle) { movement_.Rotate(angle);  }
void Goal::ClearRotation() {  movement_.ClearRotation(); }
