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
  LEVEL_PICKER,
  RUN_SIMULATION,
  SIZE
};


class Gui {
public:
  Gui();
  Gui(LevelInfo &level);
  ~Gui();

private:
  void ThMainLoop();
  void SwitchContext(Contexts new_screen);
  void HandleIncomingEvents(sf::RenderWindow &window, ContextEvent event,
                            Context *&context_storage);
protected:

  sfml_window::Context* current_context_;
  std::thread *window_thread_;
  LevelInfo current_loaded_level_;
  sf::Event event_;

};
} // namespace sfml
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_H_
