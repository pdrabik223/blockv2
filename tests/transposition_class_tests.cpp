//
// Created by studio25 on 07.08.2021.
//
#include "../utility/transposition.h"

#include "gtest/gtest.h"

TEST(Transposition, LockEdge_and_AddDirection) {

  Transposition test_unit;
  test_unit.LockEdge(Direction::DOWN);

  EXPECT_TRUE(test_unit.encounter_counter[(int)Direction::DOWN] ==
              TriState::FALSE);

  test_unit.LockEdge(Direction::LEFT);
  EXPECT_TRUE(
      test_unit.encounter_counter[(int)Direction::DOWN] == TriState::FALSE &&
      test_unit.encounter_counter[(int)Direction::LEFT] == TriState::FALSE);

  test_unit.LockEdge(Direction::UP);
  test_unit.LockEdge(Direction::DOWN);
  test_unit.LockEdge(Direction::LEFT);
  test_unit.AddDirection(Direction::UP);
  test_unit.AddDirection(Direction::DOWN);
  test_unit.AddDirection(Direction::LEFT);
  test_unit.AddDirection(Direction::RIGHT);

  EXPECT_TRUE(
      test_unit.encounter_counter[(int)Direction::DOWN] == TriState::FALSE &&
      test_unit.encounter_counter[(int)Direction::UP] == TriState::FALSE &&
      test_unit.encounter_counter[(int)Direction::LEFT] == TriState::FALSE &&
      test_unit.encounter_counter[(int)Direction::RIGHT] == TriState::TRUE);
}
TEST(Transposition, Collapse) {
  Coord test_coord(1, 1);
  Transposition test_unit;
  test_unit.AddDirection(Direction::UP);
  test_unit.LockEdge(Direction::DOWN);

  EXPECT_TRUE(test_unit.Collapse(test_coord) == Coord(1, 0));

  test_unit.AddDirection(Direction::RIGHT);
  test_unit.LockEdge(Direction::LEFT);

  EXPECT_TRUE(test_unit.Collapse(test_coord) == Coord(1, 0));

  test_unit.AddDirection(Direction::DOWN);
  test_unit.LockEdge(Direction::UP);

  EXPECT_TRUE(test_unit.Collapse(test_coord) == Coord(2, 1));

  Transposition test_unit_2;
  test_unit_2.AddDirection(Direction::RIGHT);
  test_unit_2.LockEdge(Direction::LEFT);

  EXPECT_TRUE(test_unit_2.Collapse(test_coord) == Coord(2, 1));

}
