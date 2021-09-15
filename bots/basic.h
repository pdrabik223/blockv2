// This is a beginning of a file
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BASIC_H_
#define BLOCK_V2_BOTS_BASIC_H_

#include "bot.h"
class Basic : public Bot {
public:
  Basic();

  Basic(const Basic &other);
  Basic &operator=(const Basic &other);
  Basic *Clone() override;
  ~Basic() override = default;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width,
              unsigned plane_height) override{/*do nothing*/};

  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override;

  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/* do nothing */};

  void OutputToFile(std::ostream &out) const override;

  Transposition GetMovement() const override;
  BotType GetType() const override;

  void SetRotation(int angle) override { movement_.rotation_angle_ = angle; };
  void SetMovement(const Transposition &movement);

  void ClearMovementDirection() override;
  void ClearRotation() override;
  void RotateCell(TurnDirection angle) override;

protected:
  const BotType type_ = BotType::BASIC;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_BASIC_H_
