//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_H_

#include "../bots/bots_include.h"
#include "context/context_include.h"
#include "../level_info.h"

#include <SFML/Graphics/Shape.hpp>
#include <iostream>
#include <thread>

namespace sfml_window {

/// creates window object in separate tread
/// window update is done by pushing special event on to event stack

enum class Contexts{
  MAIN_MENU,
  LEVEL_PLAYER,
  LEVEL_EDITOR,
  LEVEL_PICKER,
  SIZE
};


class Gui {
public:
  Gui();
  Gui(const LevelInfo&  level);
  ~Gui();

private:
  void ThMainLoop();
  void SwitchContext(Contexts new_screen);
protected:

  sfml_window::Context* current_context_;
  std::thread *window_thread_;
  sf::Event event_;

};
} // namespace sfml
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_H_
