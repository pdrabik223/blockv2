//
// Created by studio25 on 29.07.2021.
//

#include "enemy.h"
Enemy::Enemy(const Coord &position) : position_(position) {}
Enemy::Enemy() = default;

Enemy *Enemy::Clone() { return this; }
void Enemy::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::ENEMY<<"\n";
}
 BotType Enemy::GetType() const { return type_; }
void Enemy::CalculateMovementDirection(const std::vector<Bot *> &plane) {}
void Enemy::ClearMovementDirection() {movement_direction_ = movement_direction::Direction::NONE;}
