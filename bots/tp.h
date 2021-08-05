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
  void OutputFoFile(std::ostream &out) const override;

  const BotType type_ = BotType::TP;
private:
  Coord position_;
  unsigned id_;
};

#endif // BLOCK_V2_BOTS_TP_H_
