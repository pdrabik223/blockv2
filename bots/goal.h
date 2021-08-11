//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_GOAL_H_
#define BLOCK_V2_BOTS_GOAL_H_

#include "bot.h"
class Goal : public Bot {
public:
  Goal();
  Goal(const Goal &other);
  Goal *Clone() override;
  void OutputToFile(std::ostream &out) const override;

  BotType GetType() const override;
  const BotType type_ = BotType::GOAL;

  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width, unsigned int plane_height) override;
  void LockEdge(const std::vector<Bot *> &plane, const Coord &bot_position,
                unsigned int plane_width, unsigned int plane_height,
                Direction push_direction) override;
  void ClearMovementDirection() override;

  Transposition GetMovement() const override;

protected:
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_GOAL_H_
