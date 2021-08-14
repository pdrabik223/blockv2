//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_H_

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "coord.h"
#include <array>
namespace sfml_window {

/// all colors across whole platform must be unified
/// all menus, and graphical elements must take one of these pre-defined colors
/// this approach assures easy re-coloring of whole platform by simply editing
/// one vector
enum class GuiColor {
  MENU_PRIMARY_COLOR,
  MENU_SECONDARY_COLOR,
  MENU_TERTIARY_COLOR,
  MENU_BACKGROUND_COLOR,
  /// \default red
  /// \info to indicate dangerous behavior
  DANGER_COLOR,
  /// \default yellow
  /// \info  to indicate not that important stuff
  WARNING_COLOR,
  /// \default blue
  /// \info  to inform player about something
  INFORMATIVE_COLOR,
  /// \default green
  /// \info  stuff that is safe to touch
  SAFE_COLOR,
  SIZE
};

enum class ContextEvent{
  EXIT,
  SWITCH_TO_MAIN_MENU,
  SWITCH_TO_LEVEL_PICKER,
  SWITCH_TO_LEVEL_CREATOR,
  SWITCH_TO_LEVEL_PLAYER,
  NONE,
  UPDATE_DISPLAY,
  SIZE
  };

class Context {
public:
  virtual void LoadColors() = 0;
  virtual void DrawToWindow(sf::RenderWindow &window) = 0;
  virtual sfml_window::ContextEvent HandleEvent(sf::Event &event, const sf::RenderWindow &window) = 0;

protected:
  std::array<sf::Color, (size_t)GuiColor::SIZE> color_palette_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_H_
