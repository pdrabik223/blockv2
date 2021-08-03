//
// Created by studio25 on 03.08.2021.
//

#include "image_button.h"
bool sfml_window::ImageButton::DetectInteraction(const Coord &press_point,
                                                 sf::Event &event) {
  bool hover = structure_.CheckWBoundaries(press_point);

  return hover && (event.type == sf::Event::MouseButtonReleased &&
                   event.mouseButton.button == sf::Mouse::Left);
}
void sfml_window::ImageButton::DrawToWindow(sf::RenderWindow &window) {
  window.draw(sprite_);
}
void sfml_window::ImageButton::SetButtonColor(const sf::Color &button_color) {}

sfml_window::ImageButton::ImageButton(const Rect &structure,
                                      const std::string &image_path)
    : structure_(structure) {
  image_.loadFromFile(image_path);
  texture_.update(image_);
  texture_.setSmooth(true);
  sprite_.setTexture(texture_);
  sprite_.setPosition(structure.placement.x, structure.placement.y);
  sprite_.setScale(structure.width / image_.getSize().x,
                   structure.height / image_.getSize().y);
}
