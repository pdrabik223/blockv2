//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_H_


#include "context/context_include.h"

#include <SFML/Graphics/Shape.hpp>
#include <iostream>
#include <thread>

namespace sfml_window {

/// creates window object in separate tread
/// window update is done by pushing special event on to event stack

enum class Contexts{
  MAIN_MENU,
  LEVEL_PLAYER,
  LEVEL_CREATOR,
  CREATOR_INPUT_PANEL,
  LEVEL_PICKER,
  RUN_SIMULATION,

  SIZE
};

class Gui {
public:
  /// enty point to Block2 game
  Gui();
  /// constructor creates artificial game based on level
  /// this constructor should not be used by end user,
  Gui(const LevelInfo &level);

  ~Gui();

  /// user is forbidden to copy this object
  Gui &operator=(const Gui &other) = delete;
  /// user is forbidden to copy this object
  Gui(const Gui &other) = delete;

private:
  /// main game loop
  void ThMainLoop();
  /// switches to new screen look
  void SwitchContext(Contexts new_screen);
  /// handles events
  void HandleIncomingEvents(sf::RenderWindow &window, ContextEvent event,
                            Context *&context_storage);

protected:
  /// current displayed context
  sfml_window::Context* current_context_;
  /// whole game runs in seperated thread to main one
  std::thread *window_thread_;
  /// current handled event
  sf::Event event_;

};
} // namespace sfml
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_H_
