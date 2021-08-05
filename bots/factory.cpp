//
// Created by studio25 on 29.07.2021.
//

#include "factory.h"
Factory::Factory(const Coord &position, Direction direction)
    : position_(position), direction_(direction) {}
Factory::Factory() {}

Factory *Factory::Clone() { return this;}
void Factory::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::FACTORY<<"\n";
}

Direction Factory::GetDirection() const { return direction_; }
