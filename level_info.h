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
  std::string name_;

protected:
  unsigned width_;
  unsigned height_;

  std::vector<Bot*> plane_;

};

#endif // BLOCK_V2__LEVEL_INFO_H_
