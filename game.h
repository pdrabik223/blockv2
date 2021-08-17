//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2__GAME_H_
#define BLOCK_V2__GAME_H_
#include "bots/bots_include.h"
#include "level_info.h"
#include "utility/transposition.h"
#include <vector>

class Board {
public:
  Board() = delete;

  Board(const LevelInfo &level_info);
  Bot *GetCell(Coord position);
  Bot *GetCell(unsigned position);
  BotType GetBotType(const Coord &position) const;
  BotType GetBotType(unsigned position) const;
  unsigned int GetWidth() const;
  unsigned int GetHeight() const;

  void GenPosition();

  bool CompareGameState(const Board &other);

  bool IsWon();
  size_t Size() const;

void AddCell(int x, int y, BotType type);
private:

  /// if two bots want to be in the same place this function resolves this
  /// conflict
  /// \param bot_a bot a
  /// \param bot_b  bot b
  /// \return the new bot object that will survive
  static Bot *CrushBots(Bot *bot_a, Bot *bot_b);

  /// restore default moving direction in all the bots
  void ClearMovementDirection();

  /// blocks every bot on the plane, from moving in the direction he can't
  void LockEdges();

  /// gen new legal moving directions
  void CalculateMovementDirection();

  /// update bot position depending on legal moves
  void GenNextPlaneState();

  /// x axis
  unsigned width_;
  /// y axis
  unsigned height_;

  std::vector<Bot *> plane_;
};

#endif // BLOCK_V2__GAME_H_
