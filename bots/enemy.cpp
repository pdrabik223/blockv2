//
// Created by studio25 on 29.07.2021.
//

#include "enemy.h"
Enemy::Enemy(const Coord &position) : position_(position) {}
Enemy::Enemy() {}

Enemy *Enemy::Clone() { return this; }
void Enemy::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::ENEMY<<"\n";
}
const BotType Enemy::GetType() const { return type_; }
