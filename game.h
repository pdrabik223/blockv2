//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2__GAME_H_
#define BLOCK_V2__GAME_H_
#include "bots/bots_main.h"
#include <vector>
#include "utility/transposition.h"

class Board {
public:
  Board(unsigned int width, unsigned int height);
  Bot& GetCell(Coord position);
  Bot& GetCell(unsigned position);

private:
  void CollapseTranspositionTable();
  unsigned Board::Conv2D(Coord position);
  /// x axis
  unsigned width_;
  /// y axis
  unsigned height_;

  std::vector<Bot> plane_;
  std::vector<Transposition> transposition_table_;

};

#endif // BLOCK_V2__GAME_H_
