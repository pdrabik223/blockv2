//
// Created by studio25 on 29.07.2021.
//

#include "window.h"

using namespace sfml_window;
Gui::Gui() : current_loaded_level_(2, 1) {
  current_context_ = new MainMenu(1200, 600);
  window_thread_ = new std::thread(&Gui::ThMainLoop, this);
}

Gui::Gui(LevelInfo &level) : current_loaded_level_(level) {
  current_context_ = new RunSimulation(1200, 600, current_loaded_level_);
  window_thread_ = new std::thread(&Gui::ThMainLoop, this);
}

void Gui::ThMainLoop() {

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(1200, 600), "My window",
                          sf::Style::None, settings);

  window.setPosition(sf::Vector2i(0, 0));

  // run the program as long as the window is open
  current_context_->DrawToWindow(window);
  window.display();
  while (window.isOpen()) {

    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (window.waitEvent(event_)) {

      if (event_.type == sf::Event::Closed)
        window.close();
      else
        HandleIncomingEvents(window,
                             current_context_->HandleEvent(event_, window));
    }
  }
}
void Gui::HandleIncomingEvents(sf::RenderWindow &window, ContextEvent event) {
  switch (event) {
  case ContextEvent::EXIT:
    window.close();
    break;
  case ContextEvent::UPDATE_DISPLAY:
    goto update_display;
  case ContextEvent::SWITCH_TO_LEVEL_PICKER:
    SwitchContext(Contexts::LEVEL_PICKER);
    goto update_display;
  case ContextEvent::SWITCH_TO_MAIN_MENU:
    SwitchContext(Contexts::MAIN_MENU);
    goto update_display;
  case ContextEvent::SWITCH_TO_LEVEL_CREATOR:
    SwitchContext(Contexts::LEVEL_CREATOR);
    goto update_display;
  case ContextEvent::SWITCH_TO_LEVEL_PLAYER:
    goto update_display;
  }
  return;

update_display:
  current_context_->DrawToWindow(window);
  window.display();
}
Gui::~Gui() { window_thread_->join(); }

void Gui::SwitchContext(Contexts new_screen) {
  delete current_context_;

  switch (new_screen) {
  case Contexts::MAIN_MENU:
    current_context_ = new MainMenu(1200, 600);
    break;
  case Contexts::LEVEL_PICKER:
    current_context_ = new LevelPicker(1200, 600);
    break;
  case Contexts::LEVEL_PLAYER:
    break;
  case Contexts::LEVEL_CREATOR:
    break;
  case Contexts::RUN_SIMULATION:
    current_context_ = new RunSimulation(1200, 600, current_loaded_level_);
    break;
  case Contexts::SIZE:
    assert(false);
    break;
  }
}
