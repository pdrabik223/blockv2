//
// Created by studio25 on 29.07.2021.
//
/// template class for "bot classes"
/// Bot class is purely virtual

#ifndef BLOCK_V2_BOTS_BOT_H_
#define BLOCK_V2_BOTS_BOT_H_
#include "transposition.h"
#include <ostream>

/// contains all used cell types
enum class BotType {
  BASIC, /// something like stone in minecraft
  BEDROCK,

  TURN, /// changes the direction of  block

  GOAL,
  ENEMY,

  ENGINE,
  FACTORY,

  EMPTY,
  NONE,
  SIZE
};

class Bot {
public:
  Bot() = default;

  Bot(const Bot &other) { movement_ = other.movement_; };
  Bot &operator=(const Bot &other) { movement_ = other.movement_; };

  /// clone function returns pointer to a new object of the Bot type,
  /// @note new pointer must be deleted afterwards
  virtual Bot *Clone() {
    assert(false);
    return new Bot(*this);
  };

  virtual ~Bot() = default;

  virtual BotType GetType() const { return type_; }
  virtual Transposition GetMovement() const { return movement_; }

  virtual void SetRotation(int angle) { assert(false); };

  /// outputs to file cell info, it's type and special additional information if
  /// cell contains one
  virtual void OutputToFile(std::ostream &out) const { assert(false); };

  /// activates special function of a block (if there is one)
  /// this action is activated only once per generation
  virtual void Action(const std::vector<Bot *> &plane,
                      const Coord &bot_position, const unsigned plane_width,
                      const unsigned plane_height) {
    assert(false);
  };

  /// react to a main mechanic of the game
  /// also the pushed block should worry about block that is pushing it
  /// a.k.a. if for example goal is pushed he needs to check what block is
  /// pushing him, and than react by letting be pushed or not
  virtual void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width, unsigned int plane_height,
                    Direction push_direction) {
    assert(false);
  };

  /// activates second function of a block, that happens after push faze
  /// this action is activated only once per generation
  virtual void SecondAction(std::vector<Bot *> &plane,
                            const Coord &bot_position, unsigned int plane_width,
                            unsigned int plane_height) {
    assert(false);
  };

  /// removes previous movement
  virtual void ClearMovementDirection() { assert(false); };

  /// removes previous rotation
  virtual void ClearRotation() { assert(false); };

  /// rotates cell in place
  virtual void RotateCell(TurnDirection angle) { assert(false); };

protected:
  /// type of cell, to simplify cell identification
  const BotType type_ = BotType::NONE;

  /// current movement direction and cell rotation
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_BOT_H_
