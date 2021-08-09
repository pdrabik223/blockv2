//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_TP_H_
#define BLOCK_V2_BOTS_TP_H_

#include "bot.h"
class Tp : public Bot{
public:
  Tp();
  Tp(const Coord &position,unsigned id);
  Tp *Clone() override;
  void OutputToFile(std::ostream &out) const override;
   BotType GetType() const override;
  const BotType type_ = BotType::TP;
  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  const unsigned plane_width,
                                  const unsigned plane_height) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ = movement_direction::Direction::NONE;
private:
  Coord position_;
  unsigned id_;
};

#endif // BLOCK_V2_BOTS_TP_H_
