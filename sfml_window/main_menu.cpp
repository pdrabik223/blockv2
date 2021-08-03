//
// Created by studio25 on 01.08.2021.
//

#include "main_menu.h"
#include <cassert>
#include <iostream>

sfml_window::MainMenu::MainMenu(unsigned int window_width,
                                unsigned int window_height)
    : window_width_(window_width), window_height_(window_height),
      game_name_(Align(50, 20, 500, 100), "Block v2", sf::Color::Red),
      author_name_(Align(90, 90, 100, 50),
                   "author: piotr233\nversion: alpha 0.1", sf::Color::Red) {

  LoadColors();
  LoadButtons();
}

sfml_window::MainMenu::~MainMenu() {
  for (auto &button : buttons_)
    delete button;
}

void sfml_window::MainMenu::LoadButtons() {

  buttons_[(unsigned)MainMenuButton::EXIT] =
      new TextButton({Coord(window_width_ - 64, 0), 64, 64}, "EXIT",
                     color_palette_[(unsigned)GuiColor::DANGER_COLOR], true);

  buttons_[(unsigned)MainMenuButton::PLAY_LEVEL] = new TextButton(
      Align(10, 30), "Play level",
      color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR], false, 24);

  buttons_[(unsigned)MainMenuButton::CREATE_LEVEL] = new TextButton(
      Align(10, 40), "Create level",
      color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR], false, 24);

  buttons_[(unsigned)MainMenuButton::MULTIPLAYER] = new TextButton(
      Align(10, 50), "Multiplayer mode",
      color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR], false, 24);

  buttons_[(unsigned)MainMenuButton::CREDITS] = new TextButton(
      Align(10, 60), "Credits",
      color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR], false, 24);
}

void sfml_window::MainMenu::DrawToWindow(sf::RenderWindow &window) {

  window.clear(color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR]);

  for (const auto &button : buttons_)
    button->DrawToWindow(window);

  game_name_.DrawToWindow(window);
  author_name_.DrawToWindow(window);
}

sfml_window::ContextEvent
sfml_window::MainMenu::HandleEvent(sf::Event &event,
                                   const sf::RenderWindow &window) {

  int mouse_x = sf::Mouse::getPosition(window).x;
  int mouse_y = sf::Mouse::getPosition(window).y;

  mouse_x = mouse_x < 0 ? 0 : mouse_x;
  mouse_y = mouse_y < 0 ? 0 : mouse_y;

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_-1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_-1;


  for (unsigned id = 0; id < buttons_.size(); id++)

    if (buttons_[id]->DetectInteraction({(unsigned)mouse_x, (unsigned)mouse_y},
                                        event))

      switch ((MainMenuButton)id) {
      case MainMenuButton::EXIT:

        return ContextEvent::EXIT;

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
  color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR] = sf::Color(0x0035d6);
  color_palette_[(unsigned)GuiColor::MENU_SECONDARY_COLOR] =
      sf::Color(0xa000d6);
  color_palette_[(unsigned)GuiColor::MENU_TERTIARY_COLOR] = sf::Color(0xd6a000);
  color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR] =
      sf::Color(27, 27, 27);
  color_palette_[(unsigned)GuiColor::DANGER_COLOR] = sf::Color(255, 0, 0);
  color_palette_[(unsigned)GuiColor::WARNING_COLOR] = sf::Color(255, 255, 0);
  color_palette_[(unsigned)GuiColor::INFORMATIVE_COLOR] = sf::Color(0, 0, 255);
  color_palette_[(unsigned)GuiColor::SAFE_COLOR] = sf::Color(0, 255, 0);
}

Coord sfml_window::MainMenu::Align(double x, double y) {

  return {(unsigned)((x * window_width_) / 100.0),
          (unsigned)((y * window_height_) / 100.0)};
}
Rect sfml_window::MainMenu::Align(double x, double y, unsigned int width,
                                  unsigned int height) {
  return {{(unsigned)(((x * window_width_) / 100.0) - (width / 2)),
           (unsigned)(((y * window_height_) / 100.0) - (height / 2))},
          width,
          height};
}
