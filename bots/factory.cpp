//
// Created by studio25 on 29.07.2021.
//

#include "factory.h"
Factory::Factory(const Coord &position, Direction direction)
    : position_(position), direction_(direction) {}
Factory::Factory() = default;

Factory *Factory::Clone() { return this;}
void Factory::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::FACTORY<<" "<<(unsigned)direction_<<"\n";
}

Direction Factory::GetDirection() const { return direction_; }
 BotType Factory::GetType() const { return type_; }
void Factory::CalculateMovementDirection(const std::vector<Bot *> &plane) {}
void Factory::ClearMovementDirection() {movement_direction_ = movement_direction::Direction::NONE;}
