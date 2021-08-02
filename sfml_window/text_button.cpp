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

  if (display_background_)

    if (hover_)
      window.draw(background_);
  //  else
  //  text_.setFillColor(Light(button_color_));

  text_.DrawToWindow(window);
}
sfml_window::TextButton::TextButton(const Coord &position,
                                    const std::string &text)
    : text_(position, text) {

  background_.setPosition((float)position.x, (float)position.y);

  background_.setFillColor(sf::Color(195, 195, 195));
  background_.setOutlineColor(sf::Color(255, 255, 255));
  background_.setOutlineThickness(2);

  structure_ = {position, (unsigned)(22 * text.size()), (unsigned)(24 * 2)};
  background_.setSize({(float)structure_.width, (float)structure_.height});
  text_.SetFontSize(structure_.height / 2);
}
void sfml_window::TextButton::SetButtonColor(const sf::Color &button_color) {
  button_color_ = button_color;
  text_.SetTextColor(button_color);

  background_.setFillColor(Light(button_color_));
  background_.setOutlineColor(button_color_);
}
sfml_window::TextButton::TextButton(const Rect &structure,
                                    const std::string &text,
                                    const sf::Color &button_color,
                                    bool display_background = true,
                                    bool rigid_structure = true)
    : structure_(structure), text_(structure.placement,text), button_color_(button_color),
      display_background_(display_background),
      rigid_structure_(rigid_structure) {

  // set color
  text_.SetTextColor(button_color_);
  background_.setFillColor(Light(button_color_));
  background_.setOutlineColor(button_color_);

  background_.setPosition((float)structure_.placement.x,
                          (float)structure_.placement.y);

  if (rigid_structure) {
    background_.setSize({(float)structure_.width, (float)structure_.height});
    text_.SetFontSize(structure);
  }else{

  }
}
