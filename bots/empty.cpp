//
// Created by studio25 on 29.07.2021.
//

#include "empty.h"
Empty::Empty() = default;
Empty::Empty(const Empty &other) : Bot(other) { movement_ = other.movement_; }

Empty &Empty::operator=(const Empty &other) {
  if (&other == this)
    return *this;
  movement_ = other.movement_;
  return *this;
}

Empty *Empty::Clone() { return new Empty(*this); }

void Empty::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::EMPTY << "\n";
}
BotType Empty::GetType() const { return type_; }

void Empty::Push(const std::vector<Bot *> &plane,
                                       const Coord &bot_position,
                                       unsigned plane_width,
                                       unsigned plane_height,
                 Direction push_direction) {

  movement_.LockDirection(Opposite(push_direction));

}

void Empty::ClearMovementDirection() { movement_.Clear(); }

Transposition Empty::GetMovement() const { return movement_; }
void Empty::SetMovement(const Transposition &movement) { movement_ = movement; }
void Empty::RotateCell(TurnDirection angle)  { movement_.Rotate(angle); }
void Empty::ClearRotation() {  movement_.ClearRotation(); }
