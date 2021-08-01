//
// Created by studio25 on 29.07.2021.
//

#include "window.h"

using namespace sfml_window;
Gui::Gui() {
  current_context_ = new MainMenu(1200, 600);
  window_thread_ = new std::thread(&Gui::ThMainLoop, this);
}

void Gui::ThMainLoop() {

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(1200, 600), "My window",
                          sf::Style::Default, settings);

  // run the program as long as the window is open
  current_context_->DrawToWindow(window);
  window.display();
  while (window.isOpen()) {

    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (window.pollEvent(event_)) {
      // "close requested" event: we close the window
      if (event_.type == sf::Event::Closed)
        window.close();
      else
        current_context_->HandleEvent(event_);

    }
    current_context_->DrawToWindow(window);
    window.display();

  }

}
Gui::~Gui() { window_thread_->join(); }
