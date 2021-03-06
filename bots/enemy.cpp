//
// Created by studio25 on 29.07.2021.
//

#include "enemy.h"

Enemy::Enemy() = default;

Enemy::Enemy(const Enemy &other) : Bot(other) { movement_ = other.movement_; }

Enemy &Enemy::operator=(const Enemy &other) {
  if (&other == this)
    return *this;
  movement_ = other.movement_;
  return *this;
}
Enemy *Enemy::Clone() { return new Enemy(*this); }
void Enemy::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::ENEMY << "\n";
}
BotType Enemy::GetType() const { return type_; }

void Enemy::Push(const std::vector<Bot *> &plane, const Coord &bot_position,
                 unsigned plane_width, unsigned plane_height,
                 Direction push_direction) {

  Coord new_position = NextPosition(push_direction, bot_position);
  Coord pusher_position = NextPosition(Opposite(push_direction), bot_position);

  if (CheckBoundaries(plane_width, plane_height, new_position))
    switch (plane[pusher_position.ToInt(plane_width)]->GetType()) {

    case BotType::BASIC:
    case BotType::FACTORY:
    case BotType::ENEMY:
      // act normal
      plane[new_position.ToInt(plane_width)]->Push(
          plane, new_position, plane_width, plane_height, push_direction);

      if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
              push_direction)) {
        movement_.Push(push_direction);
      }

      break;
    case BotType::BEDROCK:
    case BotType::TURN:
    case BotType::EMPTY:
      // those block can't push
      assert("un-pushable block");
    case BotType::GOAL:
    case BotType::ENGINE:
      // kill those
      movement_.LockDirection(Opposite(push_direction));
      break;
    case BotType::NONE:
    case BotType::SIZE:
      assert("incorrect memory assigment");
    }
  else
    movement_.LockDirection(push_direction);
}

Transposition Enemy::GetMovement() const { return movement_; }

void Enemy::ClearMovementDirection() { movement_.Clear(); }

void Enemy::SetMovement(const Transposition &movement) { movement_ = movement; }

void Enemy::RotateCell(TurnDirection angle) { movement_.Rotate(angle); }

void Enemy::ClearRotation() { movement_.ClearRotation(); }
