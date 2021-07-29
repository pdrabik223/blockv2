//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_TURN_H_
#define BLOCK_V2_BOTS_TURN_H_
#include "bot.h"
class Turn: public Bot {
public:
  Turn(const Coord &position, TurnDirection direction);
  Turn();
  static BotType type_;

private:
  TurnDirection direction_;
  Coord position_;
};

#endif // BLOCK_V2_BOTS_TURN_H_
