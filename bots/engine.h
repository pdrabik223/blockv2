//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENGINE_H_
#define BLOCK_V2_BOTS_ENGINE_H_

#include "bot.h"
class Engine : public Bot {

public:
  Engine();
  explicit Engine(Direction direction);
  Engine(const Engine &other);

  Engine *Clone() override;
  void OutputToFile(std::ostream &out) const override;
  Direction GetDirection() const;
  BotType GetType() const override;
  const BotType type_ = BotType::ENGINE;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width, unsigned plane_height) override;

  void CalculateMovementDirection(
      const std::vector<Bot *> &plane, const Coord &bot_position,
      unsigned int plane_width, unsigned int plane_height,
      movement_direction::Direction push_direction) override;

  void ClearMovementDirection() override;

  movement_direction::Direction movement_direction_ =
      movement_direction::Direction::NONE;

private:
  Direction direction_ = Direction::UP;
};

#endif // BLOCK_V2_BOTS_ENGINE_H_
