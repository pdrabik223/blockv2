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
void Empty::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                       const Coord &bot_position,
                                       const unsigned plane_width,
                                       const unsigned plane_height,
                                       const Direction push_direction) {
  movement_.LockDirection(Opposite(push_direction));
}
void Empty::ClearMovementDirection() { movement_.Clear(); }

void Empty::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                   const unsigned plane_width,
                   const unsigned plane_height) { /* do nothing */
}

Transposition Empty::GetMovement() const { return movement_; }