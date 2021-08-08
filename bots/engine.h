//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENGINE_H_
#define BLOCK_V2_BOTS_ENGINE_H_
#include "../game.h"
#include "bot.h"
class Engine: public Bot {

public:
  Engine();
  Engine(const Coord &position, Direction direction);
  Engine *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  Direction GetDirection() const;
   BotType GetType() const override;
  const BotType type_ = BotType::ENGINE;
  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  const unsigned plane_width,
                                  const unsigned plane_height) override;
  void ClearMovementDirection() override;
  movement_direction::Direction movement_direction_ = movement_direction::Direction::NONE;
private:
  Direction direction_;
  Coord position_;
};

#endif // BLOCK_V2_BOTS_ENGINE_H_
