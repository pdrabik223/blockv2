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
      author_name_(Align(90, 90, 200, 50),
                   "author: piotr233\nversion: alpha 0.1", sf::Color::Red) {

  LoadColors();
  LoadButtons();
  LoadBackground();
}

sfml_window::MainMenu::~MainMenu() {
  for (auto &button : buttons_)
    delete button;
}

void sfml_window::MainMenu::LoadButtons() {



  buttons_[(unsigned)MainMenuButton::EXIT] = new TextButton(
      Align(10, 70), "EXIT", Rainbow(Align(10, 70).y,window_height_),
      false, 24);

  buttons_[(unsigned)MainMenuButton::PLAY_LEVEL] = new TextButton(
      Align(10, 30), "Play level",
      Rainbow(Align(10, 30).y,window_height_), false, 24);

  buttons_[(unsigned)MainMenuButton::CREATE_LEVEL] = new TextButton(
      Align(10, 40), "Create level",
      Rainbow(Align(10, 40).y,window_height_), false, 24);

  buttons_[(unsigned)MainMenuButton::MULTIPLAYER] = new TextButton(
      Align(10, 50), "Multiplayer mode",
      Rainbow(Align(10, 50).y,window_height_), false, 24);

  buttons_[(unsigned)MainMenuButton::CREDITS] = new TextButton(
      Align(10, 60), "Credits",
      Rainbow(Align(10, 60).y,window_height_), false, 24);
}

void sfml_window::MainMenu::DrawToWindow(sf::RenderWindow &window) {

  //  window.clear(color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR]);
  window.draw(background_sprite_);

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

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_ - 1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_ - 1;

  if (event.type == sf::Event::MouseButtonReleased) {

    for (unsigned id = 0; id < buttons_.size(); id++)

      if (buttons_[id]->DetectInteraction({mouse_x, mouse_y}, event))

        switch ((MainMenuButton)id) {
        case MainMenuButton::EXIT:
          return ContextEvent::EXIT;
        case MainMenuButton::PLAY_LEVEL:
          return ContextEvent::SWITCH_TO_LEVEL_PICKER;
        case MainMenuButton::CREATE_LEVEL:
          return ContextEvent::SWITCH_TO_LEVEL_CREATOR;
        case MainMenuButton::MULTIPLAYER:
          // do nothing
          break;
        case MainMenuButton::CREDITS:
          // switch context to display credits
          break;
        }
  } else {
    bool change = false;
    for (auto &button : buttons_)
      if (button->DetectHover({mouse_x, mouse_y}))
        change = true;

    if (change)
      return ContextEvent::UPDATE_DISPLAY;
  }
  return ContextEvent::NONE;
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

  return {(int)((x * window_width_) / 100.0),
          (int)((y * window_height_) / 100.0)};
}
Rect sfml_window::MainMenu::Align(double x, double y, unsigned int width,
                                  unsigned int height) {
  return {{(int)(((x * window_width_) / 100.0) - (width / 2)),
           (int)(((y * window_height_) / 100.0) - (height / 2))},
          width,
          height};
}

void sfml_window::MainMenu::LoadBackground() {
  if (!background_texture_.loadFromFile(
          "..\\sfml_window\\assets\\main_menu\\background.png"))
    throw "error";
  background_texture_.setSmooth(true);
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale(
      (float)window_width_ / (float)background_texture_.getSize().x,
      (float)window_height_ / (float)background_texture_.getSize().y);
}
