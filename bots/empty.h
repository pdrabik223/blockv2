//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_EMPTY_H_
#define BLOCK_V2_BOTS_EMPTY_H_
#include "bot.h"
class Empty: public Bot{
public:
  Empty();
  Empty(const Coord &position);
  Empty *Clone() override;
  void OutputFoFile(std::ostream &out) const override;

  static BotType type_;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_EMPTY_H_
