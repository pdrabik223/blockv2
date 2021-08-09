//
// Created by studio25 on 29.07.2021.
//

#include "turn.h"
Turn::Turn() = default;

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
                                      const Direction push_direction) {}
void Turn::ClearMovementDirection() {
  movement_direction_ = movement_direction::Direction::LOCK_GLOBAL;
}
Turn::Turn(const Turn &other)  : Bot(other) {
  movement_direction_ = other.movement_direction_;
  direction_ = other.direction_;
}
Turn::Turn(TurnDirection direction) : direction_(direction) {}
