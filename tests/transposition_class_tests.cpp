//
// Created by studio25 on 07.08.2021.
//
#include "transposition.h"
//#include "bots_include.h"

#include "gtest/gtest.h"

TEST(first,MovementDirection){

  Transposition trans(11, 1, new Engine, 10);
  EXPECT_TRUE(trans.GetMovementDirection() == Direction::UP);

  Transposition trans_1(1, 11, new Engine, 10);
  EXPECT_TRUE(trans_1.GetMovementDirection() == Direction::DOWN);

  Transposition trans_2(1, 2, new Engine, 10);
  EXPECT_TRUE(trans_2.GetMovementDirection() == Direction::LEFT);

  Transposition trans_3(2, 1, new Engine, 10);
  EXPECT_TRUE(trans_3.GetMovementDirection() == Direction::RIGHT);

}
