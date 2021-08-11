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
  Turn *Clone() override;
  void OutputToFile(std::ostream &out) const override;

  TurnDirection GetDirection() const;
  BotType GetType() const override;

  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;
  void ClearMovementDirection() override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width, unsigned int plane_height) override;
  void LockEdge(const std::vector<Bot *> &plane, const Coord &bot_position,
                unsigned int plane_width, unsigned int plane_height,
                Direction push_direction) override;

  const BotType type_ = BotType::TURN;

  Transposition GetMovement() const override;

protected:
  Transposition movement_;
  TurnDirection direction_ = TurnDirection::CLOCKWISE;
};

#endif // BLOCK_V2_BOTS_TURN_H_
