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

  void ClearMovementDirection() override;

  Transposition GetMovement() const override;
  BotType GetType() const override;

protected:
  const BotType type_ = BotType::GOAL;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_GOAL_H_
