//
// Created by studio25 on 08.08.2021.
//
#include "movement_direction.h"
#include "gtest/gtest.h"

using namespace movement_direction;
TEST(movement_dir, add_operator) {

  EXPECT_TRUE( Direction::UP + Direction::UP == Direction::UP);

  EXPECT_TRUE( Direction::DOWN + Direction::DOWN == Direction::DOWN);

  EXPECT_TRUE( Direction::DOWN + Direction::UP == Direction::LOCK_VERTICAL);

  EXPECT_TRUE( Direction::UP + Direction::LEFT == Direction::LEFT);

  EXPECT_TRUE( Direction::LOCK_HORIZONTAL + Direction::LOCK_VERTICAL == Direction::LOCK_GLOBAL);

  EXPECT_TRUE( Direction::LEFT + Direction::RIGHT == Direction::LOCK_HORIZONTAL);

  EXPECT_TRUE( Direction::LEFT + Direction::RIGHT == Direction::LEFT + Direction::RIGHT);

}
