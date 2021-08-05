//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BASIC_H_
#define BLOCK_V2_BOTS_BASIC_H_

#include "bot.h"
class Basic : public Bot{
public:
  Basic();
  explicit Basic(const Coord &position);
  Basic *Clone() override;
  void OutputFoFile(std::ostream &out) const override;

  const BotType type_ = BotType::BASIC;

private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_BASIC_H_
