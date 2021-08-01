//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_H_

#include "../sfml/include/SFML/Graphics/RenderWindow.hpp"
#include "../sfml/include/SFML/Window/Event.hpp"
#include "../utility/coord.h"

namespace sfml_window {
class Context {
public:

  virtual void DrawToWindow(sf::RenderWindow &window) = 0;
  virtual void HandleEvent(sf::Event& event, Coord mouse_position) = 0;

};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_H_
