//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_UTILITY_TRANSPOSITION_H_
#define BLOCK_V2_UTILITY_TRANSPOSITION_H_

#include "coord.h"
#include <memory>
#include <vector>


/// bool that can be not defined
enum class TriState {
  T_FALSE = 2,
  UNDEFINED = 1,
  T_TRUE = 3,
};

/// rotation direction for turn cell
enum class TurnDirection { CLOCKWISE, COUNTER_CLOCKWISE };

/// direction witch bot might be facing
enum class Direction { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

/// right hand rule
/// \rule the  direction on the right goes first
/// \param a first direction to compare
/// \param b second direction to compare
/// \return  returns the correct direction according to the right hand rule
Direction RHR(Direction a, Direction b);

Direction Opposite(Direction target);

Direction Rotate(Direction target, TurnDirection angle);

Coord NextPosition(Direction direction, const Coord &current_position);

Coord PreviousPosition(Direction direction, const Coord &current_position);


class Transposition {
public:
  Transposition();

  Transposition(const Transposition &other);

  Transposition &operator=(const Transposition &other);

  Coord Collapse(const Coord &current_position);
  TurnDirection CollapseRotation();



  void LockDirection(const Direction &direction);
  void AddDirection(const Direction &direction);
  void Clear();
  bool CheckDirection(const Direction &direction);
  void Push(const Direction& direction);

  void Rotate(TurnDirection direction);
  void Rotate();
  void ClearRotation();
  TriState encounter_counter_[4];

  int rotation_angle_ = 0;

};

#endif // BLOCK_V2_UTILITY_TRANSPOSITION_H_
