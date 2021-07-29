//
// Created by studio25 on 29.07.2021.
//

#include "enemy.h"
Enemy::Enemy(const Coord &position) : position_(position) {}
Enemy::Enemy() {}
BotType Enemy::type_ = BotType::ENEMY;
