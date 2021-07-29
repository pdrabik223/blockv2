//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BOT_H_
#define BLOCK_V2_BOTS_BOT_H_
#include "../utility/coord.h"

/// contains all used cell types
 enum class BotType {
  EMPTY,
  BASIC,
  BEDROCK,
  TURN,
  GOAL,
  ENEMY,
  ENGINE,
  FACTORY,
  TP,
  NONE,
  SIZE
};

class Bot {
public:
  Bot() : position_() {} // std::array needs no-param constructor
  virtual Bot *Clone(){return this;};
  static BotType type_;

protected:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BOT_H_
