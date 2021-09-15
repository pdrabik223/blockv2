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
  ~Factory() override = default;
  void OutputToFile(std::ostream &out) const override;

  void Push(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width, unsigned int plane_height) override;

  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override;
  /// getters
  Transposition GetMovement() const override;
  Direction GetDirection() const;
  BotType GetType() const override;

  /// setters
  void SetMovement(const Transposition &movement);
  void SetDirection(Direction direction);
  void ClearMovementDirection() override;

  void ClearRotation() override;
  void RotateCell(TurnDirection angle) override;
  void RotateCell();
  void SetRotation(int angle) override;

protected:
  const BotType type_ = BotType::FACTORY;
  Transposition movement_;
  Direction direction_;
};

#endif // BLOCK_V2_BOTS_FACTORY_H_
