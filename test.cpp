//
// Created by studio25 on 25.07.2021.
//
#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
  std::cout<<"lel";
  sf::Window window;
  window.create(sf::VideoMode(800, 600), "My window");

  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }
  }

  return 0;
}