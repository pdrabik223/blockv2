//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BASIC_H_
#define BLOCK_V2_BOTS_BASIC_H_

#include "bot.h"
class Basic :Bot{

public:
  Basic(const Coord &position);
  Basic();
  static BotType type_;

private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BASIC_H_
