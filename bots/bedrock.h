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

  void ClearMovementDirection() override;

  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width,
              unsigned plane_height) override{/* do nothing */};

  /// pushing this block doesn't change anything
  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override {/* do nothing */};

  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/* do nothing */};

  void OutputToFile(std::ostream &out) const override;

  void ClearRotation() override;
  Transposition GetMovement() const override;
  void SetMovement(const Transposition &movement);
  void RotateCell(int angle) override;
  BotType GetType() const override;

protected:
  const BotType type_ = BotType::BEDROCK;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_BEDROCK_H_
