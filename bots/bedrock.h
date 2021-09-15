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
  /// clone function returns pointer to a new object of the Bedrock type,
  /// @note new pointer must be deleted afterwards
  Bedrock *Clone() override;

  /// this cell does not have any unique function
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width,
              unsigned plane_height) override{/* do nothing */};

  /// pushing this block doesn't change anything
  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override{/* do nothing */};

  /// this cell does not have any unique second function
  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/* do nothing */};

  /// outputs to file cell info, it's type and special additional information if
  /// cell contains one
  void OutputToFile(std::ostream &out) const override;

  BotType GetType() const override;
  Transposition GetMovement() const override;

  void SetRotation(int angle) override { movement_.rotation_angle_ = angle; };
  void SetMovement(const Transposition &movement);

  /// removes previous movement
  void ClearMovementDirection() override;
  /// removes previous rotation
  void ClearRotation() override;
  /// rotates cell in place
  void RotateCell(TurnDirection angle) override;

protected:
  /// type of cell, to simplify cell identification
  const BotType type_ = BotType::BEDROCK;
  /// current movement direction and cell rotation
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_BEDROCK_H_
