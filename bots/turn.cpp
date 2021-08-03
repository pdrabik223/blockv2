//
// Created by studio25 on 29.07.2021.
//

#include "turn.h"
Turn::Turn(const Coord &position, TurnDirection direction)
    : position_(position), direction_(direction) {}
Turn::Turn() {}
BotType Turn::type_ = BotType::TURN;
Turn *Turn::Clone() { return this; }

void Turn::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::TURN<<" "<<(unsigned)direction_<<"\n";
}

