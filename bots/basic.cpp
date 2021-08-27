//
// Created by studio25 on 29.07.2021.
//

#include "basic.h"


Basic::Basic() = default;

Basic::Basic(const Basic &other) : Bot(other) { movement_ = other.movement_; }

Basic &Basic::operator=(const  Basic& other) {
if(&other == this) return *this;

movement_ = other.movement_;

return *this;
}


Basic *Basic::Clone() { return new Basic(*this); }

void Basic::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::BASIC << "\n";
}
BotType Basic::GetType() const { return type_; }

/// default push
/// cant be killed so nothing can stop him
void Basic::Push(const std::vector<Bot *> &plane,
                                       const Coord &bot_position,
                                       unsigned plane_width,
                                       unsigned plane_height,
                                       Direction push_direction) {

  Coord new_position = NextPosition(push_direction, bot_position);

  plane[new_position.ToInt(plane_width)]->Push(plane, new_position, plane_width,
                                               plane_height, push_direction);

  if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
          push_direction)) {
    movement_.Push(push_direction);
  } else
    movement_.LockDirection(push_direction);

}
void Basic::ClearMovementDirection() { movement_.Clear(); }



Transposition Basic::GetMovement() const { return movement_; }

void Basic::SetMovement(const Transposition &movement) { movement_ = movement; }
void Basic::RotateCell(TurnDirection angle) { movement_.Rotate(angle); }
