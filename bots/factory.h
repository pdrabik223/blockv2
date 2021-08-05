//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_FACTORY_H_
#define BLOCK_V2_BOTS_FACTORY_H_
#include "bot.h"
class Factory : public Bot {
public:
  Factory();
  Factory(const Coord &position, Direction direction);
  Factory *Clone() override;
  void OutputToFile(std::ostream &out) const override;

  Direction GetDirection() const;
  const BotType GetType() const override;
  const BotType type_ = BotType::FACTORY;

private:
  Direction direction_;
  Coord position_;
};

#endif // BLOCK_V2_BOTS_FACTORY_H_
