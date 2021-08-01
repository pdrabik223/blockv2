//
// Created by studio25 on 01.08.2021.
//

#include "main_menu.h"
#include <iostream>

sfml_window::MainMenu::MainMenu(unsigned int window_width,
                                unsigned int window_height)
    : window_width_(window_width), window_height_(window_height) {

  LoadColors();
  LoadButtons();
}

sfml_window::MainMenu::~MainMenu() {
  for (auto &button : buttons_)
    delete button;
}

void sfml_window::MainMenu::LoadButtons() {

  buttons_[(unsigned)MainMenuButton::EXIT] =
      new TextButton({window_width_ - 64, 0}, std::string("EXIT"));

  buttons_[(unsigned)MainMenuButton::EXIT]->SetButtonColor(
      color_palette_[(unsigned)GuiColor::DANGER_COLOR]);

  buttons_[(unsigned)MainMenuButton::PLAY_LEVEL] =
      new TextButton(Align(10, 30), std::string("Play level"));
  buttons_[(unsigned)MainMenuButton::PLAY_LEVEL]->SetButtonColor(
      color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR]);

  buttons_[(unsigned)MainMenuButton::CREATE_LEVEL] =
      new TextButton(Align(10, 40), std::string("Create level"));
  buttons_[(unsigned)MainMenuButton::CREATE_LEVEL]->SetButtonColor(
      color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR]);

  buttons_[(unsigned)MainMenuButton::MULTIPLAYER] =
      new TextButton(Align(10, 50), std::string("Multiplayer mode"));

  buttons_[(unsigned)MainMenuButton::MULTIPLAYER]->SetButtonColor(
      color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR]);

  buttons_[(unsigned)MainMenuButton::CREDITS] =
      new TextButton(Align(10, 60), std::string("Credits"));

  buttons_[(unsigned)MainMenuButton::CREDITS]->SetButtonColor(
      color_palette_[(unsigned)GuiColor::INFORMATIVE_COLOR]);
}

void sfml_window::MainMenu::DrawToWindow(sf::RenderWindow &window) {
  window.clear(color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR]);
  for (const auto &button : buttons_)
    button->DrawToWindow(window);

  game_name_.DrawToWindow(window);
  author_name_.DrawToWindow(window);
}

void sfml_window::MainMenu::HandleEvent(sf::Event &event) {

  Coord mouse_position =
  {(unsigned)sf::Mouse::getPosition().x,
   (unsigned)sf::Mouse::getPosition().y};

  for (unsigned id = 0; id < buttons_.size(); id++)
    if (buttons_[id]->DetectInteraction(mouse_position, event))
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
        // switch context to display credits
        break;
      }

}
void sfml_window::MainMenu::ResizeWindow(unsigned int new_width,
                                         unsigned int new_height) {
  window_width_ = new_width;
  window_height_ = new_height;
}

void sfml_window::MainMenu::LoadColors() {
  color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR] = sf::Color(0xd81717);
  color_palette_[(unsigned)GuiColor::MENU_SECONDARY_COLOR] =
      sf::Color(0x9800ff);
  color_palette_[(unsigned)GuiColor::MENU_TERTIARY_COLOR] = sf::Color(0xff9900);
  color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR] =
      sf::Color(27, 27, 27);
  color_palette_[(unsigned)GuiColor::DANGER_COLOR] = sf::Color(255, 0, 0);
  color_palette_[(unsigned)GuiColor::WARNING_COLOR] = sf::Color(255, 255, 0);
  color_palette_[(unsigned)GuiColor::INFORMATIVE_COLOR] = sf::Color(0, 0, 255);
  color_palette_[(unsigned)GuiColor::SAFE_COLOR] = sf::Color(0, 255, 0);
}

Coord sfml_window::MainMenu::Align(double x, double y) {
  std::cout << window_width_;
  return {(unsigned)((x * window_width_) / 100.0),
          (unsigned)((y * window_height_) / 100.0)};
}
