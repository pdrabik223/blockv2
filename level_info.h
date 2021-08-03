//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2__LEVEL_INFO_H_
#define BLOCK_V2__LEVEL_INFO_H_
#include "bots_main.h"
#include <string>
#include <vector>
class LevelInfo {

public:
  LevelInfo(const std::string &file_path);
  LevelInfo(unsigned int width, unsigned int height);

  void LoadLevel(const std::string &file_path);
  void SaveLevel();

  virtual ~LevelInfo();

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
