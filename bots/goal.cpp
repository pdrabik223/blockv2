//
// Created by studio25 on 29.07.2021.
//

#include "goal.h"
Goal::Goal(const Coord &position) : position_(position) {}
Goal::Goal() {}

Goal *Goal::Clone() { return this; }
void Goal::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::GOAL<<"\n";
}
const BotType Goal::GetType() const { return type_; }
