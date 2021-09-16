//
// Created by studio25 on 29.07.2021.
//

/// file contains all information describing bots movement
/// i.e. it; movement direction and rotation angle
/// Transposition class handles calculations and simplifies access to these
/// fields
/// Transposition class also resolves the final position of given bot entity at
/// the end of each generation
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

/// generates Direction opposing passed direction
/// i.e. for left is right, for up is down etc.
/// \param target current direction
/// \return direction opposing to current direction
Direction Opposite(Direction target);
///  transforms target direction by given angle
/// \param target direction before transformation
/// \param angle of the transformation
/// \return new direction
Direction RotateDirection(Direction target, TurnDirection angle);

/// generate position of the square existing one unit apart in specified
/// direction from the current position
/// \param direction of travel from current position to new position
/// \param current_position base position
/// \return new position
Coord NextPosition(Direction direction, const Coord &current_position);

/// check whether new position lies inside specified plane boundaries
/// \param plane_width width of plane
/// \param plane_height height of plane
/// \param new_position tested point
/// \return true if point lies inside of described plane, false if not
bool CheckBoundaries(unsigned plane_width, unsigned plane_height,
                     const Coord &new_position);

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
  void Push(const Direction &direction);

  void Rotate(TurnDirection direction);
  void Rotate();
  void ClearRotation();
  TriState encounter_counter_[4];

  int rotation_angle_ = 0;
};

#endif // BLOCK_V2_UTILITY_TRANSPOSITION_H_
