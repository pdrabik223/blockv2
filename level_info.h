//
// Created by studio25 on 03.08.2021.
//
/// contains additional level information
#ifndef BLOCK_V2__LEVEL_INFO_H_
#define BLOCK_V2__LEVEL_INFO_H_
#include "bots_include.h"
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <windows.h>

class LevelInfo {
public:
  LevelInfo(unsigned int width, unsigned int height);
  /// to directly load level from file
  explicit LevelInfo(const std::string &file_path);

  LevelInfo(const LevelInfo &other);
  LevelInfo &operator=(const LevelInfo &other);

  /// copy constructor
  void LoadLevel(const std::string &file_path);

  /// save current level to file
  void SaveLevel();

  /// destructor
  virtual ~LevelInfo();

  /// creates specified bot object in given position
  /// \param position position on plane the bot should be created at
  /// \param type type of the created object<br>
  /// <h3>passed type object can only be:</h3>
  /// <ol>
  /// <li>BotType::EMPTY
  /// <li>BotType::BASIC
  /// <li>BotType::BEDROCK
  /// <li>BotType::GOAL
  /// <li>BotType::ENEMY
  void AddBot(const Coord &position, BotType type);

  /// creates specified bot object in given position
  /// \param position position on plane the bot should be created at
  /// \param type type of the created object<br>
  /// \param direction witch the block will be facing
  /// <h3>passed type object can only be:</h3>
  /// <ol>
  /// <li> BotType::ENGINE
  /// <li> BotType::FACTORY
  void AddBot(const Coord &position, BotType type, Direction direction);

  /// adds new Turn bot to the game
  /// \param position position on plane the bot should be created at
  /// \param type type of the created object<br>
  /// \param direction witch the block will be facing
  void AddBot(const Coord &position, BotType type,
              TurnDirection turn_direction);
  /// Locks field at position
  /// \param position coordinates of locking block
  void Lock(Coord position);

  /// Unlocks field at position
  /// \param position coordinates of unlocking block
  void UnLock(Coord position);

  /// checks if bloc can be placed at position
  /// \param position Coodinates at witch the check will be performed
  /// \return true if block can't be placed, false if can be
  bool IsLocked(Coord position);
  /// checks if bloc can be placed at position
  /// \param position at witch the check will be performed
  /// \return true if block can't be placed, false if can be
  bool IsLocked(int position);

  const std::vector<Bot *> &GetPLane() const { return plane_; };
  unsigned int GetWidth() const;
  unsigned int GetHeight() const;
  const std::string &GetName() const;
  const std::vector<bool> &GetLockedFields() const;

  void SetName(const std::string &name);

  /// updates state of the game
  /// \param state new state of the game
  void SetWon(bool state);

  /// set's game state to won
  void LevelCompleted();

  /// acquires pointer to specified cell
  /// \param position of desired cell
  /// \return pointer to specified cell
  Bot *GetCell(int position);

  /// creates new cell entity at specified coordinates
  /// \param x position in x axis
  /// \param y position in y axis
  /// \param type of the new cell
  void AddCell(int x, int y, BotType type);

  ///  rotates cell at specified coordinates
  /// \param x position in x axis
  /// \param y position in y axis
  void RotateCell(int x, int y);

  ///  update the size of  the playing field
  ///  allocating new memory in process, but keeping already existing
  ///  information
  /// \param new_width
  /// \param new_height
  void Resize(int new_width, int new_height);

  /// check whether the game is won
  /// \return true if game is won, false if not
  bool IsWon();

private:
  /// creates bot object and returns ptr to it
  /// \important the returned hanging pointer must be deleted manually!
  /// \param in ifstream handle, the cursor position within will be modified!
  /// \param position position of the bot on the plane (may be unnecessary but
  /// for now it stays) \return the pointer to new bot object
  Bot *PushBot(std::ifstream &in, const Coord &position);

protected:
  /// x axis
  unsigned width_;
  /// y axis
  unsigned height_;
  /// "board" placement of all the cells
  std::vector<Bot *> plane_;
  /// representation witch fields are free to touch
  std::vector<bool> locked_fields_;
  /// level name
  std::string name_;
  bool is_won_ = false;
};

#endif // BLOCK_V2__LEVEL_INFO_H_
