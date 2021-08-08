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
  const BotType GetType() const override;
  const BotType type_ = BotType::BEDROCK;

  movement_direction::Direction movement_direction_ = movement_direction::Direction::NONE;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BEDROCK_H_
