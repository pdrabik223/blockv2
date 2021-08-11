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
    const Direction push_direction) {
    movement_.LockEdge(Opposite(push_direction));
}
void Empty::ClearMovementDirection() {
  movement_.Clear();
}

void Empty::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                   const unsigned plane_width,
                   const unsigned plane_height) { /* do nothing */
}
Empty::Empty(const Empty &other) : Bot(other) {
  movement_ = other.movement_;
}
void Empty::LockEdge(const std::vector<Bot *> &plane, const Coord &bot_position,
                     const unsigned int plane_width,
                     const unsigned int plane_height,
                     Direction push_direction) {
  // calculate pushed cell position
  Coord new_position = NextPosition(push_direction, bot_position);

  // this cell is pushed in some direction,
  // that means it can't be pushed in the opposite
  movement_.LockEdge(push_direction);

  // if this cell is pushing the border of the map lock that direction
  if (new_position.x >= plane_width || new_position.x < 0 ||
  new_position.y >= plane_height || new_position.y < 0) {
    movement_.LockEdge(Opposite(push_direction));
    return;
  }
  // order the cell in front to do the same
  plane[new_position.ToInt(plane_width)]->LockEdge(
      plane, new_position, plane_width, plane_height, push_direction);
}
