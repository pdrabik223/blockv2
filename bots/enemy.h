//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENEMY_H_
#define BLOCK_V2_BOTS_ENEMY_H_
#include "bot.h"
class Enemy : public Bot {
public:
  Enemy();
  Enemy(const Coord &position);
  Enemy *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  const BotType GetType() const override;
  const BotType type_ = BotType::ENEMY;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_ENEMY_H_
