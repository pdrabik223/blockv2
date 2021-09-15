//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_GOAL_H_
#define BLOCK_V2_BOTS_GOAL_H_

#include "bot.h"
class Goal : public Bot {
public:
  Goal();
  Goal(const Goal &other);
  Goal &operator=(const Goal &other);
  Goal *Clone() override;
  ~Goal() override = default;

  void OutputToFile(std::ostream &out) const override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width,
              unsigned int plane_height) override{/* do nothing*/};

  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override;

  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/* do nothing */};

  BotType GetType() const override;
  Transposition GetMovement() const override;

  void SetMovement(const Transposition &movement);
  void SetRotation(int angle) override { movement_.rotation_angle_ = angle; };

  void ClearRotation() override;
  void ClearMovementDirection() override;
  void RotateCell(TurnDirection angle) override;

protected:
  const BotType type_ = BotType::GOAL;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_GOAL_H_
