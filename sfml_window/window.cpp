//
// Created by studio25 on 29.07.2021.
//

#include "window.h"

using namespace sfml_window;
Gui::Gui()  {
  current_context_ = new MainMenu(1200, 600);
  window_thread_ = new std::thread(&Gui::ThMainLoop, this);
}

Gui::Gui(LevelInfo &level)  {
  current_context_ = new RunSimulation(1200, 600, GameEngine(level),
                                       "../levels/no_name_given/no_name_given");
  window_thread_ = new std::thread(&Gui::ThMainLoop, this);
}

Gui::~Gui() { window_thread_->join(); }

void Gui::ThMainLoop() {

  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(1200, 600), "My window",
                          sf::Style::None, settings);

  window.setPosition(sf::Vector2i(0, 0));
  window.setKeyRepeatEnabled(false);


  // run the program as long as the window is open
  current_context_->DrawToWindow(window);


  window.display();
  Context *context_storage = nullptr;
  while (window.isOpen()) {

    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (window.waitEvent(event_)) {

      if (event_.type == sf::Event::Closed)
        window.close();
      else {

        HandleIncomingEvents(window,
                             current_context_->HandleEvent(event_, window),
                             context_storage);
      }
    }
  }
  delete context_storage;
}

void Gui::HandleIncomingEvents(sf::RenderWindow &window, ContextEvent event,
                               Context *&context_storage) {
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
    SwitchContext(Contexts::LEVEL_PLAYER);
    goto update_display;

  case ContextEvent::RUN_SIMULATION: {
    delete context_storage;
    context_storage = current_context_->Clone();

    SwitchContext(Contexts::RUN_SIMULATION);
    goto update_display;
  }

  case ContextEvent::SWITCH_TO_CREATOR_INPUT_PANEL: {
    delete context_storage;
    SwitchContext(Contexts::CREATOR_INPUT_PANEL);
    goto update_display;
  }

  case ContextEvent::SWITCH_BACK_TO_CREATOR: {

    LevelInfo chosen_level = current_context_->GetLevelInfo();

    delete current_context_;
    current_context_ = new LevelCreator(1200, 600, chosen_level);

    goto update_display;
  }

  case ContextEvent::SWITCH_TO_PREVIOUS: {

    delete current_context_;
    current_context_ = context_storage->Clone();

    delete context_storage;
    context_storage = nullptr;

    goto update_display;
  }
  case ContextEvent::LEVEL_WON: {
    context_storage->GetLevelInfo().LevelCompleted();

    goto update_display;
  }

  update_display:
    current_context_->DrawToWindow(window);
    window.display();
  }
}

void Gui::SwitchContext(Contexts new_screen) {

  switch (new_screen) {
  case Contexts::MAIN_MENU: {
    delete current_context_;
    current_context_ = new MainMenu(1200, 600);
  } break;
  case Contexts::LEVEL_PICKER: {
    delete current_context_;
    current_context_ = new LevelPicker(1200, 600);
  } break;
  case Contexts::LEVEL_PLAYER: {
    std::string chosen_level_path =
        ((LevelPicker *)current_context_)->GetLevelDirectory();
    delete current_context_;
    current_context_ = new LevelPlayer(1200, 600, chosen_level_path);

  } break;

  case Contexts::LEVEL_CREATOR: {
    delete current_context_;
    current_context_ = new LevelCreator(1200, 600);
  } break;

  case Contexts::RUN_SIMULATION: {
    GameEngine chosen_level = current_context_->GetLevel();

    std::string level_path =
        current_context_->GetLevelDirectory(); // for assets

    delete current_context_;
    current_context_ = new RunSimulation(1200, 600, chosen_level, level_path);
  } break;

  case Contexts::CREATOR_INPUT_PANEL: {
    LevelInfo edited_level = current_context_->GetLevelInfo();

    current_context_ = new CreatorInputPanel(1200, 600, edited_level);

  } break;

  case Contexts::SIZE: {
    assert(false);
  }
  }
}
