//
// Created by studio25 on 29.07.2021.
//

#include "factory.h"
Factory::Factory() = default;

Factory *Factory::Clone() { return new Factory(*this); }
void Factory::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::FACTORY << " " << (unsigned)direction_ << "\n";
}

Direction Factory::GetDirection() const { return direction_; }
BotType Factory::GetType() const { return type_; }
void Factory::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                         const Coord &bot_position,
                                         const unsigned plane_width,
                                         const unsigned plane_height,
                                         const Direction push_direction) {}
void Factory::ClearMovementDirection() { movement_.Clear(); }
Factory::Factory(const Factory &other) : Bot(other) {
  movement_ = other.movement_;
  direction_ = other.direction_;
}
Factory::Factory(Direction direction) : direction_(direction) {}
void Factory::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                     const unsigned int plane_width,
                     const unsigned int plane_height) {
  Coord new_position = NextPosition(direction_, bot_position);

  plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
      plane, new_position, plane_width, plane_height, direction_);
}

Transposition Factory::GetMovement() const { return movement_; }

void Factory::Spawn(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width, unsigned int plane_height) {

  Coord target = NextPosition(direction_, bot_position);
  Coord original = NextPosition(Opposite(direction_), bot_position);

  if (plane[target.ToInt(plane_width)]->GetType() == BotType::EMPTY) {
    delete plane[target.ToInt(plane_width)];
    plane[target.ToInt(plane_width)] =
        plane[original.ToInt(plane_width)]->Clone();
  }
}
void Factory::RotateCell() {
  switch (direction_) {
  case Direction::UP:
    direction_ = Direction::RIGHT;
    return;
  case Direction::DOWN:
    direction_ = Direction::LEFT;
    return;
  case Direction::LEFT:
    direction_ = Direction::UP;
    return;
  case Direction::RIGHT:
    direction_ = Direction::DOWN;
    return;
  }
}
