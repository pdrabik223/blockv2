//
// Created by studio25 on 01.08.2021.
//

#include "text_button.h"
#include <SFML/Graphics/RectangleShape.hpp>

bool sfml_window::TextButton::DetectHover(const Coord &press_point) {
  hover_ = position_.CheckWBoundaries(press_point);
  return hover_;
}
bool sfml_window::TextButton::DetectPress(const Coord &press_point,
                                          sf::Event &event) {
  hover_ = position_.CheckWBoundaries(press_point);
  return position_.CheckWBoundaries(press_point) &&
         (event.type == sf::Event::MouseButtonReleased &&
          event.mouseButton.button == sf::Mouse::Left);
}
void sfml_window::TextButton::DrawToWindow(sf::RenderWindow &window) {


  window.draw(background_);

  if(hover_) text_.setScale(1.5,1.5);
  window.draw(text_);
}
sfml_window::TextButton::TextButton(const Rect &position,const std::string& text)
    : position_(position) {

  background_.setSize({(float)position_.width, (float)position_.height});
  background_.setPosition((float)position_.placement.x,
                          (float)position_.placement.y);
  background_.setFillColor(sf::Color(195, 195, 195));
  background_.setOutlineColor(sf::Color(255, 255, 255));
  background_.setOutlineThickness(2);

  sf::Font font;
  if (!font.loadFromFile("assets/STIXTwoMath-Regular.ttf"))
    throw "bad file";

  text_.setFont(font);
  text_.setString(text);
  text_.setCharacterSize(position_.height / 2);
  text_.setStyle(sf::Text::Bold);
}
