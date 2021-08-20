//
// Created by studio25 on 20.08.2021.
//

#include "toggle_text_button.h"

bool sfml_window::ToggleTextButton::DetectInteraction(const Coord &press_point,
                                                sf::Event &event) {
  hover_ = structure_.CheckWBoundaries(press_point);

  return hover_ && (event.type == sf::Event::MouseButtonReleased &&
  event.mouseButton.button == sf::Mouse::Left);
}

bool sfml_window::ToggleTextButton::DetectHover(const Coord &press_point) {
  bool change =
      hover_ not_eq structure_.CheckWBoundaries(press_point) ? true : false;
  hover_ = structure_.CheckWBoundaries(press_point);
  return change;
}
void sfml_window::ToggleTextButton::DrawToWindow(sf::RenderWindow &window) {

  if (hover_)
    window.draw(background_);

  text_.DrawToWindow(window);
}

sfml_window::ToggleTextButton& sfml_window::ToggleTextButton::operator=(const ToggleTextButton& other){
  if(&other == this) return *this;
  structure_ = other.structure_;
  background_ = other.background_;
  text_ = other.text_;
  hover_ = other.hover_;
  button_color_ = other.button_color_;
  display_background_ = other.display_background_;
  return *this;
}
void sfml_window::ToggleTextButton::SetButtonColor(const sf::Color &button_color) {
  button_color_ = button_color;
  background_.setFillColor(Light(button_color_));
  background_.setOutlineColor(button_color_);
}
sfml_window::ToggleTextButton::ToggleTextButton(const Rect &structure,
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
sfml_window::ToggleTextButton::ToggleTextButton(const Coord &position,
                                    const std::string &text,
                                    const sf::Color &button_color,
                                    bool display_background,
                                    unsigned int font_size)
                                    : text_(position, text, button_color_, font_size),
                                    button_color_(button_color), display_background_(display_background),
                                    hover_(false) {

  background_.setFillColor(Light(button_color_));
  background_.setOutlineColor(button_color_);

  structure_ = text_.GetFontBoundaries();
  background_.setSize({(float)structure_.width, (float)structure_.height});

  background_.setPosition((float)structure_.placement.x,
                          (float)structure_.placement.y);

  background_.setSize({(float)structure_.width, (float)structure_.height});
}
sfml_window::ToggleTextButton::ToggleTextButton(const sfml_window::ToggleTextButton& other) {
  structure_ = other.structure_;
  background_ = other.background_;
  text_ = other.text_;
  hover_ = other.hover_;
  button_color_ = other.button_color_;
  display_background_ = other.display_background_;
}
void sfml_window::ToggleTextButton::SetPosition(const Coord &position) {

  structure_.SetPlacement(position);
  background_.setPosition((float)structure_.placement.x,
                          (float)structure_.placement.y);
  text_.SetPosition(position);
}
sfml_window::ToggleTextButton *sfml_window::ToggleTextButton::Clone() { return new ToggleTextButton(*this); }
void sfml_window::ToggleTextButton::SetText(const std::string &text) {
  text_.SetText(text);

}

sfml_window::ToggleTextButton::~ToggleTextButton() = default;
