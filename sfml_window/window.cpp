//
// Created by studio25 on 29.07.2021.
//

#include "window.h"
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

  sf::CircleShape shape(50.f);

  // set the shape color to green
  shape.setFillColor(sf::Color(100, 250, 50));
  shape.setPosition(0.f, 0.f);

  window.clear(sf::Color::Black);
  window.draw(shape);
  window.display();
  // run the program as long as the window is open
  auto timer = std::chrono::steady_clock::now();
  while (window.isOpen()) {

    // check all the window's events that were triggered since the last
    // iteration of the loop

    while (window.pollEvent(event_)) {
      // "close requested" event: we close the window
      if (event_.type == sf::Event::Closed)
        window.close();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    shape.setPosition(shape.getPosition().x + 0.4f,
                      shape.getPosition().y + 0.4f);
    window.clear(sf::Color::Black);
    window.draw(shape);
    window.display();
  }
}
Gui::~Gui() { window_thread_->join(); }
