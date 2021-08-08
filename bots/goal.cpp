//
// Created by studio25 on 29.07.2021.
//

#include "goal.h"
Goal::Goal(const Coord &position) : position_(position) {}
Goal::Goal() = default;

Goal *Goal::Clone() { return this; }
void Goal::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::GOAL<<"\n";
}
 BotType Goal::GetType() const { return type_; }
void Goal::CalculateMovementDirection(const std::vector<Bot *> &plane) {}
void Goal::ClearMovementDirection() {movement_direction_ = movement_direction::Direction::NONE;}
