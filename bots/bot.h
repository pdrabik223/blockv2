//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BOT_H_
#define BLOCK_V2_BOTS_BOT_H_
#include <ostream>

#include "transposition.h"

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

class Bot {
public:
  Bot() = default;

  virtual Bot *Clone() {
    assert(false);
    return new Bot(*this);
  };
  Bot(const Bot &other) { movement_ = other.movement_; };

  virtual void OutputToFile(std::ostream &out) const { assert(false); };

  virtual BotType GetType() const { return type_; }

  /// activates special function of a block (if there is one)
  virtual void Action(const std::vector<Bot *> &plane,
                      const Coord &bot_position, const unsigned plane_width,
                      const unsigned plane_height) {
    assert(false);
  };

  virtual void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width, unsigned int plane_height,
                    Direction push_direction) {
    assert(false);
  };

  virtual void Ability(const std::vector<Bot *> &plane,
                       const Coord &bot_position, unsigned int plane_width,
                       unsigned int plane_height) {
    assert(false);
  };

  virtual void ClearMovementDirection() { assert(false); };

  virtual Transposition GetMovement() const { return movement_; }

  virtual void LockEdge(Direction edge) { assert(false); };
  virtual void AddDirection(Direction direction) { assert(false); };

protected:
  const BotType type_ = BotType::NONE;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_BOT_H_
