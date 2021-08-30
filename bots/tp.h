//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_TP_H_
#define BLOCK_V2_BOTS_TP_H_

#include "bot.h"
class Tp : public Bot {
public:
  Tp();
  explicit Tp(unsigned int id);
  Tp(const Tp &other);
  Tp& operator=(const Tp& other);
  Tp *Clone() override;
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
                    unsigned int plane_height) override {/* do nothing*/};
  void SetRotation(int angle) override{/*do nothing*/};
  void ClearRotation() override;
  void ClearMovementDirection() override;

  void RotateCell(TurnDirection angle) override;
  Transposition GetMovement() const override;
  BotType GetType() const override;
protected:
  const BotType type_ = BotType::TP;
  Transposition movement_;
  unsigned id_;
};

#endif // BLOCK_V2_BOTS_TP_H_
