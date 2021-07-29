//
// Created by studio25 on 29.07.2021.
//

#include "window.h"
using namespace sfml;
Window::Window() {

  window_thread_ = new std::thread(&Window::ThMainLoop, this);

}

void Window::ThMainLoop() {

  sf::Window window(sf::VideoMode(800, 600), "My window");

  // run the program as long as the window is open
  while (window.isOpen()){

    // check all the window's events that were triggered since the last iteration of the loop

    while (window.pollEvent(event_))
    {
      // "close requested" event: we close the window
      if (event_.type == sf::Event::Closed)
        window.close();
    }
  }
}
Window::~Window() {
  window_thread_->join();
}
