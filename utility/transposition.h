//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_UTILITY_TRANSPOSITION_H_
#define BLOCK_V2_UTILITY_TRANSPOSITION_H_

#include "../bots/bots_include.h"
#include <vector>
enum class TranspositionType {
  NONE,    // do nothing with the cell
  CREATE,  // factory
  MOVE_TO, // every movable cell
  TURN,    // turn cell
  DELETE,  // kill cell
  SIZE
};

/// cell: checks if it's move is legal
/// makes the move to transposition table
/// but table returns verdict if the move is possible

/// the modification of a piece is hard, because
struct Transposition {
  Transposition(int from, int to, const Bot *bot, unsigned matrix_width);

  Direction GetMovementDirection() const;

  const Coord from;
  const Coord to;
  std::unique_ptr<Bot> bot;
};

#endif // BLOCK_V2_UTILITY_TRANSPOSITION_H_
