//
// Created by studio25 on 01.08.2021.
//

#include "main_menu.h"

sfml_window::MainMenu::MainMenu() {}
sfml_window::MainMenu::~MainMenu() {
  for (auto &button : buttons_)
    delete button;
}
void sfml_window::MainMenu::LoadButtons() {
  buttons_[(unsigned)MainMenuButton::EXIT] = new TextButton(Rect({0, 0},4,10),std::string("cos"));
  buttons_[(unsigned)MainMenuButton::PLAY_LEVEL] = new TextButton(Rect({0, 0},4,10),std::string("cos"));
  buttons_[(unsigned)MainMenuButton::CREATE_LEVEL] = new TextButton(Rect({0, 0},4,10),std::string("cos"));
  buttons_[(unsigned)MainMenuButton::MULTIPLAYER] = new TextButton(Rect({0, 0},4,10),std::string("cos"));
  buttons_[(unsigned)MainMenuButton::CREDITS] = new TextButton(Rect({0, 0},4,10),std::string("cos"));

}

void sfml_window::MainMenu::DrawToWindow(sf::RenderWindow &window) {
  for (const auto &button : buttons_)
    button->DrawToWindow(window);
}
void sfml_window::MainMenu::HandleEvent(sf::Event &event,
                                        Coord mouse_position) {
  for (unsigned id = 0; id < buttons_.size(); id++)
    if (buttons_[id]->DetectPress(mouse_position, event))
      switch ((MainMenuButton)id) {
      case MainMenuButton::EXIT:
        // exit the game
        break;
      case MainMenuButton::PLAY_LEVEL:
        // switch context to play level
        break;
      case MainMenuButton::CREATE_LEVEL:
        // switch context to create level
        break;
      case MainMenuButton::MULTIPLAYER:
        // do nothing
        break;
      case MainMenuButton::CREDITS:
        // switch context to dispaly credits
        break;
      }
}
