//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2__GAME_H_
#define BLOCK_V2__GAME_H_
#include "level_info.h"
#include <vector>

class Board
{
public:
  Board() = delete;

  Board(const LevelInfo &level_info);
  Board &operator=(const Board &other);

  Bot *GetCell(const Coord& position);
  Bot *GetCell(unsigned position);

  BotType GetBotType(const Coord &position) const;
  BotType GetBotType(unsigned position) const;

  unsigned int GetWidth() const;
  unsigned int GetHeight() const;

  void Lock(const Coord& position);
  void UnLock(const Coord& position);
  bool IsLocked(const Coord& position);
  bool IsLocked(int position);

  void GenPosition();
  bool CompareGameState(const Board &other);
  bool IsWon();
  size_t Size() const;

  void AddCell(int x, int y, BotType type);
  void RotateCell(int x, int y);

private:
  void SetDirection(const Coord &position, const Direction &direction);
//  /// if two bots want to be in the same place this function resolves this
//  /// conflict
//  /// \param bot_a bot a
//  /// \param bot_b  bot b
//  /// \return the new bot object that will survive
  static Bot *CrushBots(Bot *bot_a, Bot *bot_b);

  /// restore default moving direction in all the bots
  void ClearMovementDirection();

  /// blocks every bot on the plane, from moving in the direction he can't
  void LockEdges();

  /// gen new legal moving directions
  void EngagePush();

  /// update bot position depending on legal moves
  void GenNextPlaneState();


  void ClearRotation();

  /// x axis
  unsigned width_;
  /// y axis
  unsigned height_;

  std::vector<Bot *> plane_;
  std::vector<bool> locked_fields_;
  void ActivateSecondAction();
};

#endif // BLOCK_V2__GAME_H_
