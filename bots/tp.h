//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_TP_H_
#define BLOCK_V2_BOTS_TP_H_
#include "bot.h"
class Tp : public Bot{
public:
  Tp(const Coord &position);
  Tp();
  static BotType type_;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_TP_H_
