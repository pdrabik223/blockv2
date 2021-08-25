//
// Created by studio25 on 29.07.2021.
//

#include "goal.h"

Goal::Goal() = default;

Goal::Goal(const Goal &other) : Bot(other) {
  movement_ = other.movement_;
}

Goal &Goal::operator=(const Goal& other) {
  if(&other == this) return *this;
  movement_ = other.movement_;
  return *this;
}
Goal *Goal::Clone() { return new Goal(*this); }

void Goal::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::GOAL << "\n";
}
BotType Goal::GetType() const { return type_; }

void Goal::CalculateMovementDirection(
    const std::vector<Bot *> &plane, const Coord &bot_position,
    const unsigned plane_width, const unsigned plane_height,
    const Direction push_direction) {
  Coord new_position = NextPosition(push_direction, bot_position);
  Coord pusher_position = NextPosition(Opposite(push_direction), bot_position);

  // if true the block behaves like basic block
  if(plane[pusher_position.ToInt(plane_width)]->GetType() == BotType::BASIC) {

    plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
        plane, new_position, plane_width, plane_height, push_direction);
    // if the next cell is "pushable" in the push_direction
    // this cell is pushable also in the push_direction
    if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
        push_direction)) {
      movement_.AddDirection(push_direction);
      movement_.LockDirection(Opposite(push_direction));
    } else
      //      movement_.LockEdge(push_direction); // the basic can't crush the enemy
      movement_.LockDirection(Opposite(push_direction)); // the basic can

  }else
    movement_.LockDirection(Opposite(push_direction));
}

void Goal::ClearMovementDirection() {
  movement_.Clear();
}

void Goal::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                  unsigned int plane_width, unsigned int plane_height) {/* do nothing */}

Transposition Goal::GetMovement() const { return movement_; }

