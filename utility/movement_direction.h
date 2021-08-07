//
// Created by studio25 on 08.08.2021.
//

#ifndef BLOCK_V2_UTILITY_MOVEMENT_DIRECTION_H_
#define BLOCK_V2_UTILITY_MOVEMENT_DIRECTION_H_
namespace movement_direction {
enum class Direction {
  NONE,
  UP,
  DOWN,
  LEFT,
  RIGHT,
  LOCK_HORIZONTAL,
  LOCK_VERTICAL,
  LOCK_GLOBAL,
  SIZE
};

Direction &operator+(const Direction &other);

} // namespace movement_direction
#endif // BLOCK_V2_UTILITY_MOVEMENT_DIRECTION_H_
