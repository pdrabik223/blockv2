//
// Created by studio25 on 14.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_SHORT_LEVEL_INFO_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_SHORT_LEVEL_INFO_H_

#include "text_button.h"
#include <coord.h>
#include <fstream>
namespace sfml_window {
/// stores info about level, when displaying in pick level window
/// the position of the displayed text can change dynamically
/// so do the color, and displayed buttons must correctly detect user interaction
struct ShortLevelInfo {

  ShortLevelInfo(const Coord &position, std::string level_path,
                 unsigned text_size, sf::Color color);

  void DrawToWindow(sf::RenderWindow &window);

  TextButton level;
  // throfeas
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_SHORT_LEVEL_INFO_H_
