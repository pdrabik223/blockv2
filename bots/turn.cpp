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
void Turn::ClearMovementDirection() { movement_.Clear(); }
Turn::Turn(const Turn &other) : Bot(other) {
  movement_ = other.movement_;
  direction_ = other.direction_;
}
Turn::Turn(TurnDirection direction) : direction_(direction) {}
void Turn::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                  unsigned int plane_width, unsigned int plane_height) {}
void Turn::LockEdge(const std::vector<Bot *> &plane, const Coord &bot_position,
                    const unsigned int plane_width,
                    const unsigned int plane_height, Direction push_direction) {
}
