//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_TP_H_
#define BLOCK_V2_BOTS_TP_H_

#include "bot.h"
class Tp : public Bot {
public:
  Tp();
  Tp(const Tp &other);
  Tp(unsigned int id);
  Tp *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  BotType GetType() const override;
  const BotType type_ = BotType::TP;
  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
      const unsigned int plane_width, const unsigned int plane_height,
      const movement_direction::Direction push_direction) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::NONE;

private:
  unsigned id_;
};

#endif // BLOCK_V2_BOTS_TP_H_
