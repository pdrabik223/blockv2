//
// Created by studio25 on 29.07.2021.
//

#include "transposition.h"
#include <iostream>
#include <memory>

const Direction r_h_r[2][2] = {
    //       			LEFT   RIGHT
    /* UP */ {Direction::LEFT, Direction::UP},
    /*DOWN */ {Direction::DOWN, Direction::RIGHT},
};

Direction RHR(Direction a, Direction b) {

  // UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
  if (a >= Direction::DOWN)
    std::swap(a, b);

  assert(a <= Direction::DOWN);
  assert(b > Direction::DOWN);
  return r_h_r[(int)a][(int)b];
}

Transposition::Transposition() {
  for (TriState &i : encounter_counter)
    i = TriState::NONE;
}
Transposition::Transposition(const Transposition &other) {
  for (int i = 0; i < 4; i++)
    this->encounter_counter[i] = other.encounter_counter[i];
}
Transposition &Transposition::operator=(const Transposition &other) {
  if (this == &other)
    return *this;
  for (int i = 0; i < 4; i++)
    this->encounter_counter[i] = other.encounter_counter[i];
  return *this;
}
Coord Transposition::Collapse(const Coord &current_position) {

  std::unique_ptr<Direction> vertical = nullptr;
  std::unique_ptr<Direction> horizontal = nullptr;

  if (encounter_counter[(int)Direction::UP] == TriState::TRUE)
    vertical = std::make_unique<Direction>(Direction::UP);

  if (encounter_counter[(int)Direction::DOWN] == TriState::TRUE)
    vertical = std::make_unique<Direction>(Direction::DOWN);

  if (encounter_counter[(int)Direction::LEFT] == TriState::TRUE)
    horizontal = std::make_unique<Direction>(Direction::LEFT);

  if (encounter_counter[(int)Direction::RIGHT] == TriState::TRUE)
    horizontal = std::make_unique<Direction>(Direction::RIGHT);

  if (vertical != nullptr and horizontal != nullptr)
    return NextPosition(RHR(*vertical, *horizontal), current_position);
  if (vertical == nullptr and horizontal != nullptr)
    return NextPosition(*vertical, current_position);
  if (vertical != nullptr and horizontal == nullptr)
    return NextPosition(*horizontal, current_position);

  return current_position;
}
void Transposition::LockEdge(const Direction &direction) {
  encounter_counter[(int)direction] = TriState::FALSE;
}

bool Transposition::CheckDirection(const Direction &direction) {
  return encounter_counter[(int)direction] not_eq TriState::FALSE;
}
void Transposition::Clear() {
  for (auto &i : encounter_counter)
    i = TriState::NONE;
}
void Transposition::AddDirection(const Direction &direction) {
  if (encounter_counter[(int)direction] != TriState::NONE)
    return;
  encounter_counter[(int)direction] = TriState::TRUE;
}
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