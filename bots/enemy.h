//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENEMY_H_
#define BLOCK_V2_BOTS_ENEMY_H_
#include "bot.h"
class Enemy : public Bot {
public:
  Enemy(const Coord &position);
  Enemy();

private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_ENEMY_H_
