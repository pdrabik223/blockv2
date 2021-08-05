//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_GOAL_H_
#define BLOCK_V2_BOTS_GOAL_H_
#include "bot.h"
class Goal: public Bot {
public:
  Goal();
  Goal(const Coord &position);
  Goal *Clone() override;
  void OutputFoFile(std::ostream &out) const override;

const BotType type_ = BotType::GOAL;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_GOAL_H_
