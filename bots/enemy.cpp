//
// Created by studio25 on 29.07.2021.
//

#include "enemy.h"
Enemy::Enemy(const Coord &position) : position_(position) {}
Enemy::Enemy() = default;

Enemy *Enemy::Clone() { return new Enemy(*this); }
void Enemy::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::ENEMY<<"\n";
}
 BotType Enemy::GetType() const { return type_; }
 void Enemy::CalculateMovementDirection(const std::vector<Bot *> &plane, const Coord &bot_position,
     const unsigned plane_width, const unsigned plane_height,
                                        const Direction push_direction) {}
void Enemy::ClearMovementDirection() {movement_direction_ = movement_direction::Direction::NONE;}
void Enemy::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                   const unsigned plane_width,
                   const unsigned plane_height) { /*do nothing*/ }
Enemy::Enemy(const Enemy& other)  : Bot(other) {
  movement_direction_ = other.movement_direction_;
}
