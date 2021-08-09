//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_EMPTY_H_
#define BLOCK_V2_BOTS_EMPTY_H_

#include "bot.h"
class Empty : public Bot {
public:
  Empty();
  Empty(const Empty &other);
  Empty *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  BotType GetType() const override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width, unsigned int plane_height) override;
  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;
  void ClearMovementDirection() override;

  const BotType type_ = BotType::EMPTY;
  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::NONE;
};

#endif // BLOCK_V2_BOTS_EMPTY_H_
