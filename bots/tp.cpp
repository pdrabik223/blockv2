//
// Created by studio25 on 29.07.2021.
//

#include "tp.h"
#include "../game.h"
Tp::Tp(const Coord &position, unsigned id) : position_(position), id_(id) {}
Tp::Tp() = default;

Tp *Tp::Clone() { return new Tp(*this); }
void Tp::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::TP << " " << id_ << "\n";
}
BotType Tp::GetType() const { return type_; }
void Tp::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                    const Coord &bot_position,
                                    const unsigned plane_width,
                                    const unsigned plane_height,
                                    const Direction push_direction) {}
void Tp::ClearMovementDirection() {
  movement_direction_ = movement_direction::Direction::LOCK_GLOBAL;
}
Tp::Tp(const Tp &other) { movement_direction_ = other.movement_direction_; }
