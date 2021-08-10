//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BEDROCK_H_
#define BLOCK_V2_BOTS_BEDROCK_H_

#include "bot.h"
class Bedrock : public Bot {
public:
  Bedrock();

  Bedrock(const Bedrock &other);
  Bedrock *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  BotType GetType() const override;
  const BotType type_ = BotType::BEDROCK;
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width, unsigned plane_height) override;
  void CalculateMovementDirection(
      const std::vector<Bot *> &plane, const Coord &bot_position,
      unsigned int plane_width, unsigned int plane_height,
      movement_direction::Direction push_direction) override;

  void LockEdge(const std::vector<Bot *> &plane, const Coord &bot_position,
                const unsigned int plane_width,
                const unsigned int plane_height) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::LOCK_GLOBAL;
};

#endif // BLOCK_V2_BOTS_BEDROCK_H_
