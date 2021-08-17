//
// Created by studio25 on 17.08.2021.
//

#include "toggle_sprite_button.h"

#include <utility>
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

  background_.setPosition(structure.placement.x, structure.placement.y);
  background_.setFillColor({255, 255, 255});
  background_.setSize(
      {(float)structure.width + 2, (float)structure.height + 2});
}

void sfml_window::ToggleSpriteButton::TurnOn() { state_ = State::TOGGLE; }

void sfml_window::ToggleSpriteButton::TurnOff() { state_ = State::DEFAULT; }

bool sfml_window::ToggleSpriteButton::DetectInteraction(
    const Coord &press_point, sf::Event &event) {
  bool hover = structure_.CheckWBoundaries(press_point);

  state_ = state_ == State::TOGGLE ? State::DEFAULT : State::TOGGLE;

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
  if (state_ == State::TOGGLE)
    window.draw(background_);

  if (hover_)
    sprite_.second.setColor(sf::Color::Transparent);
  else
    sprite_.second.setColor({0, 0, 0, 80});

  window.draw(sprite_.second);
}
