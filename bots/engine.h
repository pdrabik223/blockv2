//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENGINE_H_
#define BLOCK_V2_BOTS_ENGINE_H_
#include "bot.h"
class Engine: public Bot {

public:
  Engine(const Coord &position, Direction direction);
  Engine();
  static BotType type_;
private:
  Direction direction_;
  Coord position_;
};

#endif // BLOCK_V2_BOTS_ENGINE_H_
