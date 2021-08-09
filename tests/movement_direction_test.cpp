//
// Created by studio25 on 08.08.2021.
//
#include "gtest/gtest.h"

#include "../utility/movement_direction.h"

using namespace movement_direction;
TEST(movement_dir, add_operator) {

  EXPECT_TRUE(Direction::UP + Direction::UP == Direction::UP);

  EXPECT_TRUE(Direction::DOWN + Direction::DOWN == Direction::DOWN);

  EXPECT_TRUE(Direction::DOWN + Direction::UP == Direction::LOCK_VERTICAL);

  EXPECT_TRUE(Direction::UP + Direction::LEFT == Direction::LEFT);

  EXPECT_TRUE(Direction::LOCK_HORIZONTAL + Direction::LOCK_VERTICAL ==
              Direction::LOCK_GLOBAL);

  EXPECT_TRUE(Direction::LEFT + Direction::RIGHT == Direction::LOCK_HORIZONTAL);

  EXPECT_TRUE(Direction::LEFT + Direction::RIGHT ==
              Direction::LEFT + Direction::RIGHT);
}
TEST(movement_dir, add_equal_operator) {

  Direction a = Direction::UP;
  a += Direction::UP;
  EXPECT_TRUE(a == Direction::UP);

  Direction b = Direction::UP;
  b += Direction::DOWN;
  EXPECT_TRUE(b == Direction::LOCK_VERTICAL);

  Direction c = Direction::LOCK_VERTICAL;
  c += Direction::LOCK_VERTICAL;
  EXPECT_TRUE(c == Direction::LOCK_VERTICAL);

  Direction d = Direction::LEFT;
  d += Direction::RIGHT;
  EXPECT_TRUE(d == Direction::LOCK_HORIZONTAL);

  Direction e = Direction::LOCK_HORIZONTAL;
  e += Direction::LOCK_VERTICAL;
  EXPECT_TRUE(e == Direction::LOCK_GLOBAL);
}
TEST(movement_dir, LockAxis) {
  EXPECT_TRUE( LockAxis(Direction::RIGHT) == Direction::LOCK_HORIZONTAL);

  EXPECT_TRUE( LockAxis(Direction::UP) == Direction::LOCK_VERTICAL);
}

TEST(movement_dir, IsPossible) {

  EXPECT_TRUE(IsPossible(Direction::LEFT,Direction::UP));
  EXPECT_TRUE(IsPossible(Direction::UP,Direction::UP));
  EXPECT_TRUE(IsPossible(Direction::RIGHT,Direction::DOWN));
  EXPECT_TRUE(IsPossible(Direction::LEFT,Direction::LOCK_VERTICAL));
  EXPECT_TRUE(IsPossible(Direction::RIGHT,Direction::LOCK_VERTICAL));
  EXPECT_TRUE(IsPossible(Direction::UP,Direction::LOCK_HORIZONTAL));
  EXPECT_TRUE(IsPossible(Direction::DOWN,Direction::LOCK_HORIZONTAL));

  EXPECT_FALSE(IsPossible(Direction::LEFT,Direction::RIGHT));
  EXPECT_FALSE(IsPossible(Direction::UP,Direction::DOWN));

 EXPECT_FALSE(IsPossible(Direction::LEFT,Direction::LOCK_GLOBAL));
 EXPECT_FALSE(IsPossible(Direction::RIGHT,Direction::LOCK_GLOBAL));
 EXPECT_FALSE(IsPossible(Direction::UP,Direction::LOCK_GLOBAL));
 EXPECT_FALSE(IsPossible(Direction::DOWN,Direction::LOCK_GLOBAL));


 EXPECT_FALSE(IsPossible(Direction::LEFT,Direction::LOCK_HORIZONTAL));
 EXPECT_FALSE(IsPossible(Direction::RIGHT,Direction::LOCK_HORIZONTAL));
 EXPECT_FALSE(IsPossible(Direction::UP,Direction::LOCK_VERTICAL));
 EXPECT_FALSE(IsPossible(Direction::DOWN,Direction::LOCK_VERTICAL));

}
