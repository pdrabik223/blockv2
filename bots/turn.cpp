//
// Created by studio25 on 29.07.2021.
//

#include "turn.h"
Turn::Turn(const Coord &position, TurnDirection direction)
    : position_(position), direction_(direction) {}
Turn::Turn() = default;

Turn *Turn::Clone() { return this; }

void Turn::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::TURN << " " << (unsigned)direction_ << "\n";
}

TurnDirection Turn::GetDirection() const { return direction_; }
 BotType Turn::GetType() const { return type_; }
 void Turn::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                       const Coord &bot_position,
                                       const unsigned plane_width,
                                       const unsigned plane_height) {}
void Turn::ClearMovementDirection() {
  movement_direction_ = movement_direction::Direction::LOCK_GLOBAL;
}
