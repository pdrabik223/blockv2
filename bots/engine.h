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
  Engine& operator=(const Engine& other);
  Engine *Clone() override;
  void OutputToFile(std::ostream &out) const override;


  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width, unsigned plane_height) override;

  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;

  void ClearMovementDirection() override;

  void Ability(const std::vector<Bot *> &plane, const Coord &bot_position,
               unsigned int plane_width, unsigned int plane_height)  override
               {/* do nothing */};

  Transposition GetMovement() const override;
  Direction GetDirection() const;
  BotType GetType() const override;
  void RotateCell();

protected:
  const BotType type_ = BotType::ENGINE;
  Transposition movement_;
  Direction direction_ = Direction::UP;
};

#endif // BLOCK_V2_BOTS_ENGINE_H_
