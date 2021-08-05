//
// Created by studio25 on 29.07.2021.
//

#include "engine.h"
Engine::Engine(const Coord &position, Direction direction)
    : position_(position), direction_(direction) {}
Engine::Engine() {}

Engine *Engine::Clone() { return this; }
void Engine::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::BASIC<<" "<<(unsigned)direction_<<"\n";
}


Direction Engine::GetDirection() const { return direction_; }
const BotType Engine::GetType() const { return type_; }
