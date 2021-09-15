//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_FACTORY_H_
#define BLOCK_V2_BOTS_FACTORY_H_

#include "bot.h"
class Factory : public Bot {
public:
  Factory();
  Factory(const Factory &other);
  Factory &operator=(const Factory &other);
  explicit Factory(Direction direction);
  /// clone function returns pointer to a new object of the Factory type,
  /// @note new pointer must be deleted afterwards
  Factory *Clone() override;
  ~Factory() override = default;
  /// outputs to file cell info, it's type and special additional information if
  /// cell contains one
  void OutputToFile(std::ostream &out) const override;

  /// react to a main mechanic of the game
  /// also the pushed block should worry about block that is pushing it
  /// Factory cell can be pushed only from the sides
  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override;
  /// push cell in front of factory cell, to make room for new one
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width, unsigned int plane_height) override;

  /// create copy of a block standing behind Factory cell
  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override;
  /// getters
  Transposition GetMovement() const override;
  Direction GetDirection() const;
  BotType GetType() const override;

  /// setters
  void SetMovement(const Transposition &movement);
  void SetDirection(Direction direction);
  void SetRotation(int angle) override;

  /// removes previous movement
  void ClearMovementDirection() override;
  /// removes previous rotation
  void ClearRotation() override;
  /// rotates cell in place
  void RotateCell(TurnDirection angle) override;
  /// rotates cell in place by 90 degrees
  void RotateCell();

protected:
  /// type of cell, to simplify cell identification
  const BotType type_ = BotType::FACTORY;
  /// current movement direction and cell rotation
  Transposition movement_;
  /// defines orientation of the Factory cell
  Direction direction_;
};

#endif // BLOCK_V2_BOTS_FACTORY_H_
