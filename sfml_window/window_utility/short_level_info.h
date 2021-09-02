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
/// so do the color, and displayed buttons must correctly detect user
/// interaction
class ShortLevelInfo {
public:
  ShortLevelInfo();

  ShortLevelInfo(const std::string &level_directory, unsigned int text_size,
                 sf::Color color);

  ShortLevelInfo(const ShortLevelInfo &other);
  ShortLevelInfo &operator=(const ShortLevelInfo &other);
  void DrawToWindow(sf::RenderWindow &window, const Coord &position);
  bool DetectHover(const Coord &mouse_position);
  bool DetectInteraction(const Coord &press_point, sf::Event &event);

  std::string GetPath();

private:
  TextButton level_;
  std::string path_;
  // throfeas
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_SHORT_LEVEL_INFO_H_
