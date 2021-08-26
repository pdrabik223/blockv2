//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_BEDROCK_H_
#define BLOCK_V2_BOTS_BEDROCK_H_

#include "bot.h"
class Bedrock : public Bot {
public:
  Bedrock();

  Bedrock(const Bedrock &other);
  Bedrock &operator=(const Bedrock &other);
  Bedrock *Clone() override;

  void OutputToFile(std::ostream &out) const override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width, unsigned plane_height) override;
  void Push(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;

  void SecondAction(const std::vector<Bot *> &plane, const Coord &bot_position,
               unsigned int plane_width,
               unsigned int plane_height) override{/* do nothing */};

  void ClearMovementDirection() override;

  Transposition GetMovement() const override;
  BotType GetType() const override;

protected:
  const BotType type_ = BotType::BEDROCK;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_BEDROCK_H_
