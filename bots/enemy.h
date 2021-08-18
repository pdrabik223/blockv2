//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENEMY_H_
#define BLOCK_V2_BOTS_ENEMY_H_

#include "bot.h"
class Enemy : public Bot {
public:
  Enemy();

  Enemy(const Enemy &other);
  Enemy *Clone() override;
  void OutputToFile(std::ostream &out) const override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width, unsigned plane_height) override;

  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;

  void Ability(const std::vector<Bot *> &plane, const Coord &bot_position,
               unsigned int plane_width, unsigned int plane_height)  override
               {/* do nothing */};

  void ClearMovementDirection() override;

  Transposition GetMovement() const override;

  BotType GetType() const override;

protected:
  const BotType type_ = BotType::ENEMY;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_ENEMY_H_
