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
      const unsigned int plane_width, const unsigned int plane_height,
      const movement_direction::Direction push_direction) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::NONE;
};

#endif // BLOCK_V2_BOTS_GOAL_H_
