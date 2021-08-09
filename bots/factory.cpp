//
// Created by studio25 on 29.07.2021.
//

#include "factory.h"
Factory::Factory(const Coord &position, Direction direction)
    : position_(position), direction_(direction) {}
Factory::Factory() = default;

Factory *Factory::Clone() { return new Factory(*this);}
void Factory::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::FACTORY<<" "<<(unsigned)direction_<<"\n";
}

Direction Factory::GetDirection() const { return direction_; }
 BotType Factory::GetType() const { return type_; }
 void Factory::CalculateMovementDirection(const std::vector<Bot *> &plane, const Coord &bot_position,
     const unsigned plane_width, const unsigned plane_height,
                                          const Direction push_direction) {}
void Factory::ClearMovementDirection() {movement_direction_ = movement_direction::Direction::NONE;}
Factory::Factory(const Factory &other)  : Bot(other) {
  movement_direction_ = other.movement_direction_;
  direction_ = other.direction_;
}
