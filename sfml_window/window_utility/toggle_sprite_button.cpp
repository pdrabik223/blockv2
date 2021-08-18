//
// Created by studio25 on 17.08.2021.
//

#include "toggle_sprite_button.h"

sfml_window::ToggleSpriteButton::ToggleSpriteButton(const Rect &structure,
                                                    const sf::Texture &sprite)
    : structure_(structure) {
  sprite_.first = sprite;
  sprite_.first.setSmooth(true);
  sprite_.second.setTexture(sprite_.first);
  sprite_.second.setScale(
      (float)structure.width / (float)sprite_.first.getSize().x,
      (float)structure.height / (float)sprite_.first.getSize().y);
  sprite_.second.setPosition((float)structure.placement.x,
                             (float)structure.placement.y);
}

void sfml_window::ToggleSpriteButton::TurnOn() { state_ = State::TOGGLE; }

void sfml_window::ToggleSpriteButton::TurnOff() { state_ = State::DEFAULT; }

bool sfml_window::ToggleSpriteButton::DetectInteraction(
    const Coord &press_point, sf::Event &event) {

  bool hover = structure_.CheckWBoundaries(press_point);

  if (event.type == sf::Event::MouseButtonReleased &&
      event.mouseButton.button == sf::Mouse::Left)
    state_ = State::TOGGLE;

  return hover && (event.type == sf::Event::MouseButtonReleased &&
                   event.mouseButton.button == sf::Mouse::Left);
}
bool sfml_window::ToggleSpriteButton::DetectHover(const Coord &press_point) {

  bool change =
      hover_ not_eq structure_.CheckWBoundaries(press_point) ? true : false;

  hover_ = structure_.CheckWBoundaries(press_point);

  return change;
}
void sfml_window::ToggleSpriteButton::DrawToWindow(sf::RenderWindow &window) {

  if (hover_ or state_ == State::TOGGLE)
    sprite_.second.setColor({255, 255, 255, 255});
  else
    sprite_.second.setColor({255, 255, 255, 60});

  window.draw(sprite_.second);
}

sfml_window::ToggleSpriteButton *sfml_window::ToggleSpriteButton::Clone() {
  return new ToggleSpriteButton(*this);
}
