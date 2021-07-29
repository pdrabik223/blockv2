//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_GOAL_H_
#define BLOCK_V2_BOTS_GOAL_H_
#include "bot.h"
class Goal: public Bot {
public:
  Goal(const Coord &position);
  Goal();
  static BotType type_;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_GOAL_H_
