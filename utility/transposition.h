//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_UTILITY_TRANSPOSITION_H_
#define BLOCK_V2_UTILITY_TRANSPOSITION_H_

#include "../bots/bots_main.h"
#include <vector>
enum class TranspositionType {
  NONE, // do nothing with the cell
  CREATE, // factory
  MOVE_TO, // every movable cell
  TURN, // turn cell
  DELETE, // kill cell
  SIZE
};

/// cell: checks if it's move is legal
/// makes the move to transposition table
/// but table returns verdict if the move is possible

/// the modification of a piece is hard, because
class Transposition {
public:
  Transposition();
  void PushTransposition(TranspositionType target);
  void PushTransposition(TranspositionType target, Bot info);
  Bot& Collapse(Bot& target);


private:
  std::vector<std::pair<TranspositionType, Bot>> transposition_;
};

#endif // BLOCK_V2_UTILITY_TRANSPOSITION_H_
