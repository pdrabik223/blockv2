//
// Created by studio25 on 01.08.2021.
//

#include "text_box.h"
void sfml_window::TextBox::DrawToWindow(sf::RenderWindow &window) {
  window.draw(text_);
}
sfml_window::TextBox::TextBox(const Coord &position, const std::string &text)
    : position_(position) {
  sf::Font font;
  if (!font.loadFromFile("assets/STIXTwoMath-Regular.ttf"))
    throw "bad file";

  text_.setFont(font);
  text_.setString(text);
  text_.setCharacterSize(position_.y);
  text_.setStyle(sf::Text::Bold);

}
