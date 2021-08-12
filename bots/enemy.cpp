//
// Created by studio25 on 29.07.2021.
//

#include "enemy.h"

Enemy::Enemy() = default;

Enemy *Enemy::Clone() { return new Enemy(*this); }
void Enemy::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::ENEMY << "\n";
}
BotType Enemy::GetType() const { return type_; }
void Enemy::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                       const Coord &bot_position,
                                       const unsigned plane_width,
                                       const unsigned plane_height,
                                       const Direction push_direction) {

  Coord new_position = NextPosition(push_direction, bot_position);
  Coord pusher_position = NextPosition(Opposite(push_direction), bot_position);

  // if true the block behaves like basic block
  if(plane[pusher_position.ToInt(plane_width)]->GetType() == BotType::BASIC) {

    plane[new_position.ToInt(plane_width)]->CalculateMovementDirection(
        plane, new_position, plane_width, plane_height, push_direction);
    // if the next cell is "pushable" in the push_direction
    // this cell is pushable also in the push_direction
    if (plane[new_position.ToInt(plane_width)]->GetMovement().CheckDirection(
    	push_direction)) {
      movement_.AddDirection(push_direction);
      movement_.LockEdge(Opposite(push_direction));
    } else
//      movement_.LockEdge(push_direction); // the basic can't crush the enemy
      movement_.LockEdge(Opposite(push_direction)); // the basic can

  }else movement_.LockEdge(Opposite(push_direction));

}

void Enemy::ClearMovementDirection() { movement_.Clear(); }
void Enemy::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                   const unsigned plane_width,
                   const unsigned plane_height) { /*do nothing*/
}
Enemy::Enemy(const Enemy &other) : Bot(other) { movement_ = other.movement_; }
Transposition Enemy::GetMovement() const { return movement_; }
