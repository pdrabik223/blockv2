//
// Created by studio25 on 29.07.2021.
//

#include "transposition.h"
#include <iostream>

Transposition::Transposition() {
  for (TriBool &i : encounter_counter)
    i = TriBool::NONE;
}
Transposition::Transposition(const Transposition &other) {
  for (int i = 0; i < 4; i++)
    this->encounter_counter[i] = other.encounter_counter[i];
}
Transposition &Transposition::operator=(const Transposition &other) {
  if(this == &other) return *this;
  for (int i = 0; i < 4; i++)
    this->encounter_counter[i] = other.encounter_counter[i];
  return *this;
}
Coord Transposition::Collapse(Coord current_position) {
  return current_position;
}
void Transposition::LockEdge(const Direction &direction) {
  encounter_counter[(int)direction] = TriBool::FALSE;
}

bool Transposition::CheckDirection(const Direction &direction) {
  return encounter_counter[(int)direction] not_eq TriBool::FALSE;
}
void Transposition::Clear() {
  for (auto &i : encounter_counter)
    i = TriBool::NONE;
}
void Transposition::AddDirection(const Direction &direction) {
  encounter_counter[(int)direction] = TriBool::TRUE;
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
