//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_H_

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

#include <array>

#include "../../game.h"

namespace sfml_window {

/// replace with exists[(int)Assets::x]
#define EXIST(x) exists[(int)Assets::x]

enum class FlipDirection { HORIZONTAL, VERTICAL, BOTH };
/// the major way main window communicates with every running context
enum class ContextEvent {
  EXIT,
  SWITCH_TO_MAIN_MENU,
  SWITCH_TO_LEVEL_PICKER,
  SWITCH_TO_LEVEL_CREATOR,
  SWITCH_TO_LEVEL_PLAYER,
  SWITCH_TO_PREVIOUS,
  SWITCH_TO_CREATOR_INPUT_PANEL,
  SWITCH_BACK_TO_CREATOR,
  RUN_SIMULATION,
  LEVEL_WON,
  UPDATE_DISPLAY,
  NONE,
  SIZE
};

enum class Assets {
  BASIC, /// something like stone
  BEDROCK,
  ENEMY,
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
  virtual void DrawToWindow(sf::RenderWindow &window) = 0;

  virtual sfml_window::ContextEvent
  HandleEvent(sf::Event &event, const sf::RenderWindow &window) = 0;

  /// clone function returns pointer to a new object of the Context type,
  /// \note new pointer must be deleted afterwards
  virtual Context *Clone() = 0;

  /// get game object
  virtual GameEngine GetLevel() = 0;
  /// get Full level info object
  virtual LevelInfo GetLevelInfo() = 0;
  /// get level directory path (path to assets)
  virtual std::string GetLevelDirectory() = 0;

  virtual ~Context() = default;
};

/// creates Directory path from level name
std::string DirectoryPath(const std::string &level_path);

/// creates Level path from directory name
std::string LevelPath(const std::string &directory_path);
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_H_
