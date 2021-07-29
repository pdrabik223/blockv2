//
// Created by studio25 on 29.07.2021.
//

#include "engine.h"
Engine::Engine(const Coord &position, Direction direction)
    : position_(position), direction_(direction) {}
Engine::Engine() {}
BotType Engine::type_ = BotType::ENGINE;
