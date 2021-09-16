//
// Created by studio25 on 29.07.2021.
//

#include "transposition.h"

/// right hand rule
const Direction r_h_r[2][2] = {
    //       			LEFT   RIGHT
    /* UP */ {Direction::LEFT, Direction::UP},
    /*DOWN */ {Direction::DOWN, Direction::RIGHT},
};

/// rotation rule
const Direction r_r[4][2]{
    //         clockwise      counterclockwise
    /* UP */ {Direction::RIGHT, Direction::LEFT},
    /*DOWN */ {Direction::LEFT, Direction::RIGHT},
    /*LEFT */ {Direction::UP, Direction::DOWN},
    /*RIGHT */ {Direction::DOWN, Direction::UP},

};
Direction Opposite(Direction target) {
  switch (target) {
  case Direction::UP:
    return Direction::DOWN;
  case Direction::DOWN:
    return Direction::UP;
  case Direction::LEFT:
    return Direction::RIGHT;
  case Direction::RIGHT:
    return Direction::LEFT;
  }

  assert(false);
  return target;
}

Direction RotateDirection(Direction target, TurnDirection angle) {
  return r_r[(int)target][(int)angle];
}

Direction RotateDirection(Direction target, int angle) {
  switch (angle) {
  case 0:
    return target;
  case 90:
  case -270:
    return r_r[(int)target][(int)TurnDirection::CLOCKWISE];
  case -90:
  case 270:
    return r_r[(int)target][(int)TurnDirection::COUNTER_CLOCKWISE];
  case 180:
  case -180:
    if (target == Direction::UP)
      return Direction::DOWN;

    if (target == Direction::DOWN)
      return Direction::UP;

    if (target == Direction::LEFT)
      return Direction::RIGHT;

    if (target == Direction::RIGHT)
      return Direction::LEFT;

  default:
    assert(false);
    return Direction::UP;
  }
}

Coord NextPosition(Direction direction, const Coord &current_position) {
  switch (direction) {
  case Direction::UP:
    return {current_position.x, current_position.y - 1};
  case Direction::DOWN:
    return {current_position.x, current_position.y + 1};
  case Direction::LEFT:
    return {current_position.x - 1, current_position.y};
  case Direction::RIGHT:
    return {current_position.x + 1, current_position.y};
  }
  assert(false);
  return current_position;
}

bool CheckBoundaries(unsigned plane_width, unsigned plane_height,
                     const Coord &new_position) {

  return (plane_width > new_position.x and plane_height > new_position.y);
}

Coord PreviousPosition(Direction direction, const Coord &current_position) {
  return NextPosition(Opposite(direction), current_position);
}

Direction RHR(Direction a, Direction b) {

  // UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
  if (a > Direction::DOWN)
    std::swap(a, b);

  assert(a <= Direction::DOWN);
  assert(b > Direction::DOWN);
  return r_h_r[(int)a][(int)b - 2];
}

Transposition::Transposition() {
  for (TriState &i : encounter_counter_)
    i = TriState::UNDEFINED;
}
Transposition::Transposition(const Transposition &other) {
  for (int i = 0; i < 4; i++)
    this->encounter_counter_[i] = other.encounter_counter_[i];
  rotation_angle_ = other.rotation_angle_;
}
Transposition &Transposition::operator=(const Transposition &other) {
  if (this == &other)
    return *this;
  for (int i = 0; i < 4; i++)
    this->encounter_counter_[i] = other.encounter_counter_[i];
  rotation_angle_ = other.rotation_angle_;
  return *this;
}
Coord Transposition::Collapse(const Coord &current_position) {

  Direction vertical;
  bool empty_vertical = true;

  Direction horizontal;
  bool empty_horizontal = true;

  if (encounter_counter_[(int)Direction::UP] == TriState::T_TRUE) {
    vertical = Direction::UP;
    empty_vertical = false;
  }
  if (encounter_counter_[(int)Direction::DOWN] == TriState::T_TRUE) {
    vertical = Direction::DOWN;
    empty_vertical = false;
  }
  if (encounter_counter_[(int)Direction::LEFT] == TriState::T_TRUE) {
    horizontal = Direction::LEFT;
    empty_horizontal = false;
  }
  if (encounter_counter_[(int)Direction::RIGHT] == TriState::T_TRUE) {
    horizontal = Direction::RIGHT;
    empty_horizontal = false;
  }

  if (not empty_vertical)
    vertical = RotateDirection(vertical, rotation_angle_);

  if (not empty_horizontal)
    horizontal = RotateDirection(horizontal, rotation_angle_);

  if (not empty_vertical and not empty_horizontal)
    return NextPosition(RHR(vertical, horizontal), current_position);

  if (empty_vertical and not empty_horizontal)
    return NextPosition(horizontal, current_position);

  if (not empty_vertical and empty_horizontal)
    return NextPosition(vertical, current_position);

  return current_position;
}
void Transposition::LockDirection(const Direction &direction) {
  encounter_counter_[(int)direction] = TriState::T_FALSE;
}

bool Transposition::CheckDirection(const Direction &direction) {
  return encounter_counter_[(int)direction] not_eq TriState::T_FALSE;
}
void Transposition::Clear() {
  for (auto &i : encounter_counter_)
    i = TriState::UNDEFINED;
}
void Transposition::AddDirection(const Direction &direction) {
  if (encounter_counter_[(int)direction] != TriState::UNDEFINED)
    return;
  encounter_counter_[(int)direction] = TriState::T_TRUE;
}
void Transposition::Push(const Direction &direction) {
  AddDirection(direction);
  LockDirection(Opposite(direction));
}

void Transposition::Rotate() {
  TriState temp_encounter[4];
  for (int i = 0; i < 4; i++)
    temp_encounter[i] = encounter_counter_[i];

  encounter_counter_[(int)Direction::UP] = temp_encounter[(int)Direction::LEFT];
  encounter_counter_[(int)Direction::RIGHT] =
      temp_encounter[(int)Direction::UP];
  encounter_counter_[(int)Direction::DOWN] =
      temp_encounter[(int)Direction::RIGHT];
  encounter_counter_[(int)Direction::LEFT] =
      temp_encounter[(int)Direction::DOWN];
}

void Transposition::Rotate(TurnDirection direction) {

  switch (direction) {

  case TurnDirection::CLOCKWISE:
    rotation_angle_ += 90;
    break;
  case TurnDirection::COUNTER_CLOCKWISE:
    rotation_angle_ -= 90;
    break;
  }
}
void Transposition::ClearRotation() { rotation_angle_ = 0; }
// todo make a better one
TurnDirection Transposition::CollapseRotation() {
  switch (rotation_angle_) {
  case 90:
    return TurnDirection::CLOCKWISE;
  case -90:
    return TurnDirection::COUNTER_CLOCKWISE;
  default:
    assert(false);
    return TurnDirection::CLOCKWISE;
  }
}
