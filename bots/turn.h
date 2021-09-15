//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_TURN_H_
#define BLOCK_V2_BOTS_TURN_H_

#include "bot.h"
class Turn : public Bot {
public:
  Turn();
  Turn(const Turn &other);
  explicit Turn(TurnDirection direction);
  Turn &operator=(const Turn &other);
  Turn *Clone() override;
  ~Turn() override = default;

  void OutputToFile(std::ostream &out) const override;

  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override;


  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width,
              unsigned int plane_height) override{/*do nothing*/};

  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/*do nothing*/};

  TurnDirection GetDirection() const;
  BotType GetType() const override;
  Transposition GetMovement() const override;

  void SetRotation(int angle);
  void SetMovement(const Transposition &movement);
  void SetDirection(TurnDirection direction);

  void ClearMovementDirection() override;
  void ClearRotation() override;
  void RotateCell();
  void RotateCell(TurnDirection angle) override;

protected:
  const BotType type_ = BotType::TURN;
  Transposition movement_;
  TurnDirection direction_ = TurnDirection::CLOCKWISE;
};

#endif // BLOCK_V2_BOTS_TURN_H_
