//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_TURN_H_
#define BLOCK_V2_BOTS_TURN_H_

#include "bot.h"
class Turn : public Bot {
public:
  Turn();
  Turn(const Turn &other);
  explicit Turn(TurnDirection direction);
  Turn &operator=(const Turn &other);
  /// clone function returns pointer to a new object of the Turn type,
  /// @note new pointer must be deleted afterwards
  Turn *Clone() override;
  ~Turn() override = default;

  /// outputs to file cell info, it's type and special additional information if
  /// cell contains one
  void OutputToFile(std::ostream &out) const override;

  /// this cell can not be pushed
  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override;

  /// this cell does not have any unique function
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width,
              unsigned int plane_height) override{/*do nothing*/};

  /// this cell does not have any unique second function
  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/*do nothing*/};

  TurnDirection GetDirection() const;
  BotType GetType() const override;
  Transposition GetMovement() const override;

  void SetRotation(int angle) override;
  void SetMovement(const Transposition &movement);
  void SetDirection(TurnDirection direction);
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
  const BotType type_ = BotType::TURN;
  /// current movement direction and cell rotation
  Transposition movement_;
  /// rotation applied to cell entering Rotate cell
  TurnDirection direction_ = TurnDirection::CLOCKWISE;
};

#endif // BLOCK_V2_BOTS_TURN_H_
