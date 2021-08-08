//
// Created by studio25 on 08.08.2021.
//

#ifndef BLOCK_V2_UTILITY_MOVEMENT_DIRECTION_H_
#define BLOCK_V2_UTILITY_MOVEMENT_DIRECTION_H_
#include <vector>
namespace movement_direction {

enum class Direction {
  NONE = 0,
  UP = 1,
  DOWN = 2,
  LEFT = 3,
  RIGHT = 4,
  LOCK_HORIZONTAL = 5,
  LOCK_VERTICAL = 6,
  LOCK_GLOBAL = 7,
  SIZE
};
// todo bot cirection to movemnet_direction casting
const Direction truth_table[(unsigned long long)Direction::SIZE][(
    unsigned long long)Direction::SIZE] = {
    {Direction::NONE, Direction::UP, Direction::DOWN, Direction::LEFT,
     Direction::RIGHT, Direction::LOCK_HORIZONTAL, Direction::LOCK_VERTICAL,
     Direction::LOCK_GLOBAL},
    {Direction::UP, Direction::UP, Direction::LOCK_VERTICAL, Direction::LEFT,
     Direction::UP, Direction::UP, Direction::LOCK_VERTICAL,
     Direction::LOCK_GLOBAL},
    {Direction::DOWN, Direction::LOCK_VERTICAL, Direction::DOWN,
     Direction::DOWN, Direction::RIGHT, Direction::DOWN,
     Direction::LOCK_VERTICAL, Direction::LOCK_GLOBAL},
    {Direction::LEFT, Direction::LEFT, Direction::DOWN, Direction::LEFT,
     Direction::LOCK_HORIZONTAL, Direction::LOCK_HORIZONTAL, Direction::LEFT,
     Direction::LOCK_GLOBAL},
    {Direction::RIGHT, Direction::UP, Direction::RIGHT,
     Direction::LOCK_HORIZONTAL, Direction::RIGHT, Direction::LOCK_HORIZONTAL,
     Direction::RIGHT, Direction::LOCK_GLOBAL},
    {Direction::LOCK_HORIZONTAL, Direction::UP, Direction::DOWN,
     Direction::LOCK_HORIZONTAL, Direction::LOCK_HORIZONTAL,
     Direction::LOCK_HORIZONTAL, Direction::LOCK_GLOBAL,
     Direction::LOCK_GLOBAL},
    {Direction::LOCK_VERTICAL, Direction::LOCK_VERTICAL,
     Direction::LOCK_VERTICAL, Direction::LEFT, Direction::RIGHT,
     Direction::LOCK_GLOBAL, Direction::LOCK_VERTICAL, Direction::LOCK_GLOBAL},
    {Direction::LOCK_GLOBAL, Direction::LOCK_GLOBAL, Direction::LOCK_GLOBAL,
     Direction::LOCK_GLOBAL, Direction::LOCK_GLOBAL, Direction::LOCK_GLOBAL,
     Direction::LOCK_GLOBAL, Direction::LOCK_GLOBAL}};
///
/// \param a first argument
/// \param b second argument
/// \return sum of it's arguments, following the <a href="../README.md">truth
/// table</a>

Direction operator+(const Direction &a, const Direction &b);

Direction& operator+=(Direction &a, const Direction &b);

} // namespace movement_direction
#endif // BLOCK_V2_UTILITY_MOVEMENT_DIRECTION_H_
