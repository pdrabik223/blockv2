//
// Created by studio25 on 29.07.2021.
//

#include "goal.h"

Goal::Goal() = default;

Goal *Goal::Clone() { return new Goal(*this); }
void Goal::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::GOAL << "\n";
}
BotType Goal::GetType() const { return type_; }
void Goal::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                      const Coord &bot_position,
                                      const unsigned plane_width,
                                      const unsigned plane_height,
                                      const Direction push_direction) {}
void Goal::ClearMovementDirection() {
  movement_direction_ = movement_direction::Direction::NONE;
}
Goal::Goal(const Goal &other) : Bot(other) {
  movement_direction_ = other.movement_direction_;
}
