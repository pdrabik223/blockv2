//
// Created by studio25 on 29.07.2021.
//

#include "factory.h"
Factory::Factory() = default;

Factory *Factory::Clone() { return new Factory(*this); }
void Factory::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::FACTORY << " " << (unsigned)direction_ << "\n";
}

Direction Factory::GetDirection() const { return direction_; }
BotType Factory::GetType() const { return type_; }
void Factory::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                         const Coord &bot_position,
                                         const unsigned plane_width,
                                         const unsigned plane_height,
                                         const Direction push_direction) {}
void Factory::ClearMovementDirection() { movement_.Clear(); }
Factory::Factory(const Factory &other) : Bot(other) {
  movement_ = other.movement_;
  direction_ = other.direction_;
}
Factory::Factory(Direction direction) : direction_(direction) {}
void Factory::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                     const unsigned int plane_width,
                     const unsigned int plane_height) {}
void Factory::LockEdge(const std::vector<Bot *> &plane,
                       const Coord &bot_position,
                       const unsigned int plane_width,
                       const unsigned int plane_height,
                       Direction push_direction) {}
Transposition Factory::GetMovement() const { return movement_; }
