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

/// replace with exists[(int)Assets::x]
#define EXIST(x) exists[(int)Assets::x]

enum class FlipDirection { HORIZONTAL, VERTICAL, BOTH };

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
  SWITCH_TO_PREVIOUS,
  RUN_SIMULATION,

  UPDATE_DISPLAY,
  NONE,
  SIZE
  };

enum class Assets {
  BASIC, /// something like stone
  BEDROCK,
  ENEMY,
  TP,
  GOAL,

  TURN_C,   /// clockwise
  TURN_CC,  /// counterclockwise
  ENGINE_U, /// up
  ENGINE_D, /// down
  ENGINE_L, /// left
  ENGINE_R, /// right

  FACTORY_U, /// up
  FACTORY_D, /// down
  FACTORY_L, /// left
  FACTORY_R, /// right
  BACKGROUND,
  SIZE
};

class Context {
public:
  virtual void LoadColors() = 0;
  virtual void DrawToWindow(sf::RenderWindow &window) = 0;
  virtual sfml_window::ContextEvent HandleEvent(sf::Event &event, const sf::RenderWindow &window) = 0;
  virtual Context* Clone() = 0;

protected:
  std::array<sf::Color, (size_t)GuiColor::SIZE> color_palette_;
};

std::string DirectoryPath(const std::string& level_path);
std::string LevelPath(const std::string& directory_path);
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_H_
