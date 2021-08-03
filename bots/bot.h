//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BOT_H_
#define BLOCK_V2_BOTS_BOT_H_
#include "../utility/coord.h"
#include <ostream>

/// contains all used cell types
 enum class BotType {
  EMPTY,
  BASIC, /// something like stone
  BEDROCK,
  TURN, /// changes the direction of  block
  GOAL,
  ENEMY,
  ENGINE,
  FACTORY,
  TP,
  NONE,
  SIZE
};
 /// direction witch bot might be facing
 enum class Direction{
   UP,
   DOWN,
   LEFT,
   RIGHT
 };

 enum class TurnDirection{
   CLOCKWISE,
   COUNTER_CLOCKWISE
 };
class Bot {
public:
  Bot() : position_() {} // std::array needs no-param constructor
  virtual Bot *Clone(){return this;};

  virtual void OutputFoFile(std::ostream &out) = 0;

  static BotType type_;

protected:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BOT_H_
