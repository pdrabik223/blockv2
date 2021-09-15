//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENEMY_H_
#define BLOCK_V2_BOTS_ENEMY_H_

#include "bot.h"
class Enemy : public Bot {
public:
  Enemy();
  Enemy(const Enemy &other);
  Enemy &operator=(const Enemy &other);
  /// clone function returns pointer to a new object of the Enemy type,
  /// @note new pointer must be deleted afterwards
  Enemy *Clone() override;
  ~Enemy() override = default;

  /// outputs to file cell info, it's type and special additional information if
  /// cell contains one
  void OutputToFile(std::ostream &out) const override;

  /// this cell does not have any unique function
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width,
              unsigned plane_height) override{/* do nothing */};

  /// react to a main mechanic of the game
  /// also the pushed block should worry about block that is pushing it
  /// if Enemy cell is pushed it will try not to move in pushed direction,
  /// and react with pushing cell, the Basic cell can force Enemy cell to move
  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override;

  /// this cell does not have any unique second function
  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/* do nothing */};

  BotType GetType() const override;
  Transposition GetMovement() const override;

  void SetMovement(const Transposition &movement);
  void SetRotation(int angle) override { movement_.rotation_angle_ = angle; };
  /// removes previous movement
  void ClearMovementDirection() override;
  /// removes previous rotation
  void ClearRotation() override;
  /// rotates cell in place
  void RotateCell(TurnDirection angle) override;

protected:
  /// type of cell, to simplify cell identification
  const BotType type_ = BotType::ENEMY;
  /// current movement direction and cell rotation
  Transposition movement_;
};

#endif // BLOCK_V2_BOTS_ENEMY_H_
