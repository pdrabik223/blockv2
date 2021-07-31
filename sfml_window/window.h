//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_H_

#include "../bots/bots_main.h"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <thread>

namespace sfml {
/// creates window object in separate tread
/// window update is done by pushing special event on to event stack
class Gui {
public:
  Gui();
  ~Gui();

private:
  void ThMainLoop();

protected:
  std::vector<sf::Shape> images_; // the size of  images is static
  std::thread *window_thread_;
  sf::Event event_;

};
} // namespace sfml
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_H_
