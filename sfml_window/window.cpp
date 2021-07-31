//
// Created by studio25 on 29.07.2021.
//

#include "window.h"
#include "context.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
using namespace sfml;
Gui::Gui() { window_thread_ = new std::thread(&Gui::ThMainLoop, this); }

void Gui::ThMainLoop() {

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(800, 600), "My window",
                          sf::Style::Default, settings);

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
