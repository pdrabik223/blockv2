//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_BOTS_ENGINE_H_
#define BLOCK_V2_BOTS_ENGINE_H_

#include "bot.h"
class Engine : public Bot {

public:
  Engine();
  explicit Engine(Direction direction);
  Engine(const Engine &other);
  Engine &operator=(const Engine &other);
  /// clone function returns pointer to a new object of the Engine type,
  /// @note new pointer must be deleted afterwards
  Engine *Clone() override;
  ~Engine() override = default;

  /// outputs to file cell info, it's type and special additional information if
  /// cell contains one
  void OutputToFile(std::ostream &out) const override;

  /// push cell if  front of engine cell, next advance in the pushed direction
  void Action(const std::vector<Bot *> &plane, const Coord &bot_position,
              unsigned plane_width, unsigned plane_height) override;

  /// react to a main mechanic of the game
  /// also the pushed block should worry about block that is pushing it
  /// engine has it's own velocity and direction, so pushing engine block will
  /// behave different depending on the pushing side
  void Push(const std::vector<Bot *> &plane, const Coord &bot_position,
            unsigned int plane_width, unsigned int plane_height,
            Direction push_direction) override;

  /// this cell does not have any unique second function
  void SecondAction(std::vector<Bot *> &plane, const Coord &bot_position,
                    unsigned int plane_width,
                    unsigned int plane_height) override{/* do nothing */};

  Transposition GetMovement() const override;
  Direction GetDirection() const;
  BotType GetType() const override;

  void SetRotation(int angle) override;
  void SetMovement(const Transposition &movement);
  /// removes previous rotation
  void ClearRotation() override;
  /// removes previous movement
  void ClearMovementDirection() override;

  /// rotates cell in place
  void RotateCell(TurnDirection angle) override;
  /// rotates cell in place by 90 degrees
  void RotateCell();

protected:
  /// type of cell, to simplify cell identification
  const BotType type_ = BotType::ENGINE;
  /// current movement direction and cell rotation
  Transposition movement_;
  /// defines orientation of the Engine cell
  Direction direction_ = Direction::UP;
};

#endif // BLOCK_V2_BOTS_ENGINE_H_
