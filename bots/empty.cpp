//
// Created by studio25 on 29.07.2021.
//

#include "empty.h"
Empty::Empty(const Coord &position) : position_(position) {}
Empty::Empty() = default;

Empty *Empty::Clone() { return this; }
void Empty::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::EMPTY<<"\n";
}
BotType Empty::GetType() const { return type_; }
void Empty::CalculateMovementDirection(
    const std::vector<Bot *> &plane, const Coord &bot_position,
    const unsigned plane_width, const unsigned plane_height,
                                       const Direction push_direction) {
  movement_direction_ +=  movement_direction::Direction((int)push_direction + 1);
}
void Empty::ClearMovementDirection() {movement_direction_ = movement_direction::Direction::NONE;}
void Empty::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                   const unsigned plane_width,
                   const unsigned plane_height) { /*do nothing*/ }
