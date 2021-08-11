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
  explicit Tp(unsigned int id);
  Tp *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  BotType GetType() const override;
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


  const BotType type_ = BotType::TP;

  Transposition GetMovement() const override;

protected:
  Transposition movement_;
  unsigned id_;
};

#endif // BLOCK_V2_BOTS_TP_H_
