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
  explicit Factory(Direction direction);
  Factory *Clone() override;
  void OutputToFile(std::ostream &out) const override;

  Direction GetDirection() const;
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
  const BotType type_ = BotType::FACTORY;
  Transposition movement_;

private:
  Direction direction_;
};

#endif // BLOCK_V2_BOTS_FACTORY_H_
