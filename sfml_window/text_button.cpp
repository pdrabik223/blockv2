//
// Created by studio25 on 01.08.2021.
//

#include "text_button.h"
bool sfml_window::TextButton::DetectInteraction(const Coord &press_point,
                                                sf::Event &event) {
  hover_ = structure_.CheckWBoundaries(press_point);

  return hover_ && (event.type == sf::Event::MouseButtonReleased &&
                    event.mouseButton.button == sf::Mouse::Left);
}
void sfml_window::TextButton::DrawToWindow(sf::RenderWindow &window) {

  if (hover_)
    window.draw(background_);

  text_.DrawToWindow(window);
}

void sfml_window::TextButton::SetButtonColor(const sf::Color &button_color) {
  button_color_ = button_color;
  background_.setFillColor(Light(button_color_));
  background_.setOutlineColor(button_color_);
}
sfml_window::TextButton::TextButton(const Rect &structure,
                                    const std::string &text,
                                    const sf::Color &button_color,
                                    bool display_background = false)
    : structure_(structure), text_(structure, text, button_color_),
      button_color_(button_color), display_background_(display_background),
      hover_(false) {

  background_.setFillColor(Light(button_color_));
  background_.setOutlineColor(button_color_);

  background_.setPosition((float)structure_.placement.x,
                          (float)structure_.placement.y);

  background_.setSize({(float)structure_.width, (float)structure_.height});
  text_.SetFontSize(structure);
}
sfml_window::TextButton::TextButton(const Coord &position,
                                    const std::string &text,
                                    const sf::Color &button_color,
                                    bool display_background,
                                    unsigned int font_size)
    : text_(position, text, button_color_, font_size),
      button_color_(button_color), display_background_(display_background) {

  background_.setFillColor(Light(button_color_));
  background_.setOutlineColor(button_color_);

  background_.setSize({(float)structure_.width, (float)structure_.height});
  structure_ = text_.GetFontBoundaries();

  background_.setPosition((float)structure_.placement.x,
                          (float)structure_.placement.y);
  background_.setSize({(float)structure_.width, (float)structure_.height});
}
