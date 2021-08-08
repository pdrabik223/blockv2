//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BEDROCK_H_
#define BLOCK_V2_BOTS_BEDROCK_H_
#include "bot.h"
class Bedrock: public Bot {
public:
  Bedrock();
  Bedrock(const Coord &position);

  Bedrock *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  BotType GetType() const override;
  const BotType type_ = BotType::BEDROCK;
  void CalculateMovementDirection(const std::vector<Bot *> &plane) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ = movement_direction::Direction::LOCK_GLOBAL;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BEDROCK_H_
