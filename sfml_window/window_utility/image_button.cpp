//
// Created by studio25 on 03.08.2021.
//

#include "image_button.h"
#include <cassert>
bool sfml_window::ImageButton::DetectInteraction(const Coord &press_point,
                                                 sf::Event &event) {
  bool hover = structure_.CheckWBoundaries(press_point);

  return hover && (event.type == sf::Event::MouseButtonReleased &&
  event.mouseButton.button == sf::Mouse::Left);
}


void sfml_window::ImageButton::DrawToWindow(sf::RenderWindow &window) {

  if(hover_)
    sprite_.setColor(color_);
  else
    sprite_.setColor(Light(color_));
  window.draw(sprite_);
}
void sfml_window::ImageButton::SetButtonColor(const sf::Color &button_color) {}

sfml_window::ImageButton::ImageButton(const Rect &structure,
                                      const std::string &image_path, const sf::Color &color)
    : structure_(structure),color_(color) {


  if (!texture_.loadFromFile(image_path)){
    assert(false);
  }
  texture_.setSmooth(true);
  sprite_.setTexture(texture_);
  sprite_.setColor(Light(color_));
  sprite_.setPosition((float)structure.placement.x,(float)structure.placement.y);
  sprite_.setScale( (float)structure.width/(float)texture_.getSize().x,
                    (float)structure.height/(float)texture_.getSize().y);
}
bool sfml_window::ImageButton::DetectHover(const Coord &press_point) {

  bool change=
      hover_ not_eq structure_.CheckWBoundaries(press_point) ? true : false;

  hover_ = structure_.CheckWBoundaries(press_point);

  return change;
}

sfml_window::ImageButton *sfml_window::ImageButton::Clone() { return new ImageButton(*this); }
