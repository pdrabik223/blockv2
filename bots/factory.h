//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_FACTORY_H_
#define BLOCK_V2_BOTS_FACTORY_H_

#include "bot.h"
class Factory : public Bot {
public:
  Factory();
  Factory(const Factory &other);
  Factory& operator=(const Factory& other);
  explicit Factory(Direction direction);
  Factory *Clone() override;
  void OutputToFile(std::ostream &out) const override;


  void CalculateMovementDirection(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width, unsigned int plane_height) override;

  void Ability(const std::vector<Bot *> &plane, const Coord &bot_position,
               unsigned int plane_width, unsigned int plane_height)  override {/*do nothing*/};

  void Spawn(std::vector<Bot *> &plane, const Coord &bot_position,
  unsigned int plane_width, unsigned int plane_height);

  void ClearMovementDirection() override;

  Transposition GetMovement() const override;
  Direction GetDirection() const;
  BotType GetType() const override;
  void RotateCell();
protected:
  const BotType type_ = BotType::FACTORY;
  Transposition movement_;
  Direction direction_;
};

#endif // BLOCK_V2_BOTS_FACTORY_H_
