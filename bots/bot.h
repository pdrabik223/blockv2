//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BOT_H_
#define BLOCK_V2_BOTS_BOT_H_
#include "../utility/coord.h"
#include "../utility/movement_direction.h"
#include <ostream>

/// contains all used cell types
enum class BotType {
  BASIC, /// something like stone
  BEDROCK,
  TURN, /// changes the direction of  block
  GOAL,
  ENEMY,
  ENGINE,
  FACTORY,
  TP,
  EMPTY,
  NONE,
  SIZE
};
/// direction witch bot might be facing
enum class Direction { UP, DOWN, LEFT, RIGHT };

enum class TurnDirection { CLOCKWISE, COUNTER_CLOCKWISE };
class Bot {
public:
  Bot() = default;

  virtual Bot *Clone() { return this; };

  virtual void OutputToFile(std::ostream &out) const {};
  virtual BotType GetType() const { return type_; }
  virtual void CalculateMovementDirection(const std::vector<Bot *> &plane){ };
  virtual void ClearMovementDirection(){ };
  const BotType type_ = BotType::NONE;

  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::NONE;

protected:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BOT_H_
