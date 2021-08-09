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
   BotType GetType() const override;
  const BotType type_ = BotType::ENEMY;
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              const unsigned plane_width, const unsigned plane_height) override;
  void CalculateMovementDirection(const std::vector<Bot *> &plane, const Coord &bot_position,
      const unsigned plane_width, const unsigned plane_height,
                                  const Direction push_direction) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ = movement_direction::Direction::NONE;
private:
  Coord position_;
};

#endif // BLOCK_V2_BOTS_ENEMY_H_
