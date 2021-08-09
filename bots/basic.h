//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BASIC_H_
#define BLOCK_V2_BOTS_BASIC_H_

#include "bot.h"
class Basic : public Bot {
public:
  Basic();
  explicit Basic(const Coord &position);
  Basic(const Basic &other);
  Basic *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  BotType GetType() const override;
  const BotType type_ = BotType::BASIC;
  void ClearMovementDirection() override;
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
               unsigned plane_width,  unsigned plane_height) override;
  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned plane_width,
                                  unsigned plane_height,
                                  Direction push_direction) override;
  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::NONE;

};

#endif // BLOCK_V2_BOTS_BASIC_H_
