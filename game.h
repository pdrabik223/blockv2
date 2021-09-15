//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2__GAME_H_
#define BLOCK_V2__GAME_H_
#include "level_info.h"
#include <vector>

class GameEngine {
public:
  GameEngine() = delete;

  explicit GameEngine(const LevelInfo &level_info);
  GameEngine(const GameEngine &other);
  GameEngine &operator=(const GameEngine &other);

  ~GameEngine();

  /// acquires pointer to specified cell
  /// \param position coordinates of desired cell
  /// \return pointer to specified cell
  Bot *GetCell(const Coord &position);

  /// acquires pointer to specified cell
  /// \param position of desired cell
  /// \return pointer to specified cell
  Bot *GetCell(unsigned position);

  /// tests the Block for it's type
  /// \param position coordinates of tested block
  /// \return type of block at position
  BotType GetBotType(const Coord &position) const;

  /// tests the Block for it's type
  /// \param position of tested block
  /// \return type of block at position
  BotType GetBotType(unsigned position) const;

  /// acquire width of level
  /// \return width of level
  unsigned int GetWidth() const;

  /// acquire height of level
  /// \return height of level
  unsigned int GetHeight() const;

  /// Locks field at position
  /// \param position coordinates of locking block
  void Lock(const Coord &position);

  /// Unlocks field at position
  /// \param position coordinates of unlocking block
  void UnLock(const Coord &position);

  /// checks if bloc can be placed at position
  /// \param position at witch the check will be performed
  /// \return true if block can't be placed, false if can be
  bool IsLocked(int position);

  /// generate new frame/ game state
  void GenPosition();
  /// check whether the game is won
  /// \return true if game is won, false if not
  bool IsWon();
  ///
  /// \return total number of bots
  size_t Size() const;
  /// creates new cell entity at specified coordinates
  /// \param x position in x axis
  /// \param y position in y axis
  /// \param type of the new cell
  void AddCell(int x, int y, BotType type);

  ///  rotates cell at specified coordinates
  /// \param x position in x axis
  /// \param y position in y axis
  void RotateCell(int x, int y);

private:
  /// if two bots want to be in the same place this function resolves this
  /// conflict
  /// \param bot_a bot a
  /// \param bot_b  bot b
  /// \return the new bot object that will survive
  static Bot *CrushBots(Bot *bot_a, Bot *bot_b);

  /// restore default moving direction in all the bots
  void ClearMovementDirection();

  /// gen new legal moving directions
  void EngagePush();

  /// update bot position depending on legal moves
  void GenNextPlaneState();

  void EmplaceBot(std::vector<Bot *> &plane, const Coord &placement,
                  BotType type, int rotation);
  /// clears rotation off all cells on plane
  void ClearRotation();
  /// activates second action off all cells on plane
  void ActivateSecondAction();

  /// calculate final rotation of the cell
  /// \param position targeted cell
  /// \return final rotation
  int CollapseRotation(const Coord &position);

  /// x axis
  unsigned width_;
  /// y axis
  unsigned height_;
  /// "board" placement of all the cells
  std::vector<Bot *> plane_;
  /// representation witch fields are free to touch
  std::vector<bool> locked_fields_;
};

#endif // BLOCK_V2__GAME_H_
