//
// Created by studio25 on 29.07.2021.
//

#include "turn.h"
Turn::Turn(const Coord &position, TurnDirection direction)
    : position_(position), direction_(direction) {}
Turn::Turn() {}
BotType Turn::type_ = BotType::TURN;
