//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2__LEVEL_INFO_H_
#define BLOCK_V2__LEVEL_INFO_H_
#include "bots_include.h"
#include <string>
#include <vector>
class LevelInfo {
public:
  LevelInfo(const std::string &file_path);
  LevelInfo(unsigned int width, unsigned int height);


  void LoadLevel(const std::string &file_path);
  void SaveLevel();
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
  void AddBot(const Coord &position,BotType type);
  /// creates specified bot object in given position
  /// \param position position on plane the bot should be created at
  /// \param type type of the created object<br>
  /// \param direction witch the block will be facing
  /// <h3>passed type object can only be:</h3>
  /// <ol>
  /// <li> BotType::ENGINE
  /// <li> BotType::FACTORY
  void AddBot(const Coord &position,BotType type,Direction direction);
  void AddBot(const Coord &position,BotType type,TurnDirection turn_direction);
  void AddBot(const Coord &position,BotType type,int id);

  std::vector<Bot*>& GetPLane(){

    return plane_;};
  unsigned int GetWidth() const;
  unsigned int GetHeight() const;
  const std::string &GetName() const;

private:
  /// creates bot object and returns ptr to it
  /// \important the returned hanging pointer must be deleted manually!
  /// \param in ifstream handle, the cursor position within will be modified!
  /// \param position position of the bot on the plane (may be unnecessary but for now it stays)
  /// \return the pointer to new bot object
  Bot *PushBot(std::ifstream &in, const Coord &position);
  std::string name_;



protected:
  unsigned width_;
  unsigned height_;
  std::vector<Bot*> plane_;

};

#endif // BLOCK_V2__LEVEL_INFO_H_
