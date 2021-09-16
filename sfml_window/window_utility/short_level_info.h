//
// Created by studio25 on 14.08.2021.
//
/// shorten level info class
/// contains only level name, author name and win state
#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_SHORT_LEVEL_INFO_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_SHORT_LEVEL_INFO_H_

#include "image_button.h"
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
  /// handles information display to sfm::window
  /// \param window targeted display
  void DrawToWindow(sf::RenderWindow &window, const Coord &position);
  /// detects mouse hover
  /// \param press_point coordinates of user mouse
  /// \return true if appearance of button has changed
  bool DetectHover(const Coord &mouse_position);
  /// handles user interaction with the button
  /// \param press_point coordinates of user mouse
  /// \param event action performed by user
  /// \return  true if button was pressed, false if not
  bool DetectInteraction(const Coord &press_point, sf::Event &event);

  std::string GetPath();

private:
  /// level name
  TextButton level_;
  /// full path to loaded level
  std::string path_;
  /// trophy image
  ImageButton *trophy_;
  bool level_won_ = false;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_SHORT_LEVEL_INFO_H_
