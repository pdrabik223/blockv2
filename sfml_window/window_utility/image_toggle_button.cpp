//
// Created by studio25 on 13.08.2021.
//

#include "image_toggle_button.h"
sfml_window::ImageToggleButton::ImageToggleButton(
    const Rect &structure,
    std::pair<const std::string &, const sf::Color &> default_image,
    std::pair<const std::string &, const sf::Color &> toggle_image)
    : structure_(structure) {
  colors_[(int)State::DEFAULT] = default_image.second;
  colors_[(int)State::TOGGLE] = toggle_image.second;

  if (!textures_[(int)State::DEFAULT].loadFromFile(default_image.first)) {
    assert(false);
  }
  if (!textures_[(int)State::TOGGLE].loadFromFile(toggle_image.first)) {
    assert(false);
  }
  for (auto &t : textures_)
    t.setSmooth(true);
  sprites_[(int)State::DEFAULT].setTexture(textures_[(int)State::DEFAULT]);
  sprites_[(int)State::DEFAULT].setColor(Light(default_image.second));

  sprites_[(int)State::DEFAULT].setScale(
      (float)structure.width /
          (float)textures_[(int)State::DEFAULT].getSize().x,
      (float)structure.height /
          (float)textures_[(int)State::DEFAULT].getSize().y);

  sprites_[(int)State::TOGGLE].setTexture(textures_[(int)State::TOGGLE]);
  sprites_[(int)State::TOGGLE].setColor(Light(toggle_image.second));

  sprites_[(int)State::TOGGLE].setScale(
      (float)structure.width / (float)textures_[(int)State::TOGGLE].getSize().x,
      (float)structure.height /
          (float)textures_[(int)State::TOGGLE].getSize().y);

  for (auto &s : sprites_)
    s.setPosition((float)structure.placement.x, (float)structure.placement.y);
}
void sfml_window::ImageToggleButton::DrawToWindow(sf::RenderWindow &window) {
  if (hover_)
    sprites_[(int)state_].setColor(colors_[(int)state_]);
  else
    sprites_[(int)state_].setColor(Light(colors_[(int)state_]));
  window.draw(sprites_[(int)state_]);
}

bool sfml_window::ImageToggleButton::DetectHover(const Coord &press_point) {

  bool change =
      hover_ not_eq structure_.CheckWBoundaries(press_point) ? true : false;

  hover_ = structure_.CheckWBoundaries(press_point);

  return change;
}
bool sfml_window::ImageToggleButton::DetectInteraction(const Coord &press_point,
                                                       sf::Event &event) {
  bool hover = structure_.CheckWBoundaries(press_point);

  state_ = state_ == State::TOGGLE ? State::DEFAULT : State::TOGGLE;

  return hover && (event.type == sf::Event::MouseButtonReleased &&
                   event.mouseButton.button == sf::Mouse::Left);
}

sfml_window::ImageToggleButton::ImageToggleButton(
    const ImageToggleButton &other) {
  structure_ = other.structure_;
  hover_ = other.hover_;

  state_ = other.state_;
  textures_ = other.textures_; // this one for sure tho
  sprites_ = other.sprites_;
  colors_ = other.colors_;
}
sfml_window::ImageToggleButton *sfml_window::ImageToggleButton::Clone() {
  return new ImageToggleButton(*this);
}
void sfml_window::ImageToggleButton::SetButtonColor(
    const sf::Color &new_color) {
  /* this button can not change colors*/
}
