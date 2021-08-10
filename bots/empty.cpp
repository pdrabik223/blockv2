//
// Created by studio25 on 29.07.2021.
//

#include "empty.h"
Empty::Empty() = default;

Empty *Empty::Clone() { return new Empty(*this); }

void Empty::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::EMPTY << "\n";
}
BotType Empty::GetType() const { return type_; }
void Empty::CalculateMovementDirection(
    const std::vector<Bot *> &plane, const Coord &bot_position,
    const unsigned plane_width, const unsigned plane_height,
    const movement_direction::Direction push_direction) {

  if (!IsPossible(
          push_direction,
          plane[NextPosition(push_direction, bot_position).ToInt(plane_width)]
              ->movement_direction_))
    movement_direction_ = movement_direction::LockAxis(push_direction);
}
void Empty::ClearMovementDirection() {
  movement_direction_ = movement_direction::Direction::NONE;
}

void Empty::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                   const unsigned plane_width,
                   const unsigned plane_height) { /* do nothing */
}
Empty::Empty(const Empty &other) : Bot(other) {
  movement_direction_ = other.movement_direction_;
}
void Empty::LockEdge(const std::vector<Bot *> &plane, const Coord &bot_position,
                     const unsigned int plane_width,
                     const unsigned int plane_height) {

}
