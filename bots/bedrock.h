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
  void OutputFoFile(std::ostream &out) const override;

  static BotType type_;

private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BEDROCK_H_
