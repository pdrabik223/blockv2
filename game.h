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

  Board(LevelInfo& level_info);
  Bot* GetCell(Coord position);
  Bot* GetCell(unsigned position);
  unsigned int GetWidth() const;
  unsigned int GetHeight() const;

  void GenPosition();

private:

  /// x axis
  unsigned width_;
  /// y axis
  unsigned height_;

  std::vector<Bot*> plane_;
  std::vector<Transposition> transposition_table_;

};

#endif // BLOCK_V2__GAME_H_
