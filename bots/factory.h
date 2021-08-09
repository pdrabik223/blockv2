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
  Factory(Direction direction);
  Factory *Clone() override;
  void OutputToFile(std::ostream &out) const override;

  Direction GetDirection() const;
  BotType GetType() const override;
  const BotType type_ = BotType::FACTORY;
  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
      const unsigned int plane_width, const unsigned int plane_height,
      const movement_direction::Direction push_direction) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::NONE;

private:
  Direction direction_;
};

#endif // BLOCK_V2_BOTS_FACTORY_H_
