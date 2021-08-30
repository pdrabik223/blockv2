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

  void ClearMovementDirection() override;

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
  void RotateCell(TurnDirection angle) override;
  void SetRotation(int angle) override{/*do nothing*/};


  void ClearRotation() override;
  Transposition GetMovement() const override;
  BotType GetType() const override;



protected:
  const BotType type_ = BotType::BASIC;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_BASIC_H_
