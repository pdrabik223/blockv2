//
// Created by studio25 on 29.07.2021.
//

#include "basic.h"
#include "../game.h"

Basic::Basic() = default;

Basic *Basic::Clone() { return new Basic(*this); }

void Basic::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::BASIC << "\n";
}
BotType Basic::GetType() const { return type_; }


void Basic::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                       const Coord &bot_position,
                                       unsigned plane_width,
                                       unsigned plane_height,
                                       Direction push_direction) {

  Coord new_position = NextPosition(push_direction, bot_position);

  plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
      plane, new_position, plane_width, plane_height, push_direction);

  // if the next cell is "pushable" in the push_direction
  // this cell is pushable also in the push_direction
  if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
          push_direction)) {
    movement_.AddDirection(push_direction);
    movement_.LockEdge(Opposite(push_direction));
  } else
    movement_.LockEdge(push_direction);
}
void Basic::ClearMovementDirection() { movement_.Clear(); }

void Basic::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                   const unsigned plane_width,
                   const unsigned plane_height) { /*do nothing*/
}
Basic::Basic(const Basic &other) : Bot(other) { movement_ = other.movement_; }
Transposition Basic::GetMovement() const { return movement_; }

