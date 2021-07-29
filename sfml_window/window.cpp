//
// Created by studio25 on 29.07.2021.
//

#include "window.h"
#include <SFML/Graphics/Vertex.hpp>
using namespace sfml;
Gui::Gui() {

  window_thread_ = new std::thread(&Gui::ThMainLoop, this);

  sf::Vertex line[2];
  line[0].position = sf::Vector2f(100, 0  );
  line[0].color  = sf::Color::Red;
  line[1].position = sf::Vector2f(200, 0);
  line[1].color = sf::Color::Blue;

}

void Gui::ThMainLoop() {

  sf::Window window(sf::VideoMode(800, 600), "My window");

  // run the program as long as the window is open
  while (window.isOpen()) {

    // check all the window's events that were triggered since the last
    // iteration of the loop

    while (window.pollEvent(event_)) {
      // "close requested" event: we close the window
      if (event_.type == sf::Event::Closed)
        window.close();
    }
  }
}
Gui::~Gui() { window_thread_->join(); }
