// Created by studio25 on 29.07.2021.
//
//

#ifndef BLOCK_V2_UTILITY_TRANSPOSITION_H_
#define BLOCK_V2_UTILITY_TRANSPOSITION_H_

#include "coord.h"
#include <vector>

/// direction witch bot might be facing
enum class Direction { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

Direction Opposite(Direction target);
Coord NextPosition(Direction direction, const Coord &current_position);

enum class TranspositionType {
  NONE,    // do nothing with the cell
  CREATE,  // factory
  MOVE_TO, // every movable cell
  TURN,    // turn cell
  DELETE,  // kill cell
  SIZE
};

enum class TriBool { NONE = -1, FALSE = 0, TRUE = 1 };

struct Transposition {
  Transposition();
  Transposition(const Transposition &other);
  Transposition &operator=(const Transposition &other);
  Coord Collapse(Coord current_position);
  void LockEdge(const Direction &direction);
  void AddDirection(const Direction &direction);
  void Clear();
  void LockAxis();
  bool CheckDirection(const Direction &direction);

  TriBool encounter_counter[4];
};

#endif // BLOCK_V2_UTILITY_TRANSPOSITION_H_
