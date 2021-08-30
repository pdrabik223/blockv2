//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_EMPTY_H_
#define BLOCK_V2_BOTS_EMPTY_H_

#include "bot.h"
class Empty : public Bot {
public:
  Empty();
  Empty(const Empty &other);
  Empty& operator=(const Empty &other);
  Empty *Clone() override;
  void OutputToFile(std::ostream &out) const override;


  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned int plane_width, unsigned int plane_height) override {/* do nothing */};

  /// can't be pushed but can be killed, and everything will kill it
  void Push(const std::vector<Bot *> &plane,
                                  const Coord &bot_position,
                                  unsigned int plane_width,
                                  unsigned int plane_height,
                                  Direction push_direction) override;

  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
               unsigned int plane_width, unsigned int plane_height)  override
               {/* do nothing */};

  void ClearMovementDirection() override;

  void ClearRotation() override;
  Transposition GetMovement() const override;
  void SetRotation(int angle) override{/*do nothing*/};
   void SetMovement(const Transposition &movement);
   void RotateCell(TurnDirection angle) override;
   BotType GetType() const override;


protected:
  const BotType type_ = BotType::EMPTY;
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_EMPTY_H_
