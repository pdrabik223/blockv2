//
// Created by studio25 on 01.08.2021.
//

#include "text_box.h"
void sfml_window::TextBox::DrawToWindow(sf::RenderWindow &window) {
  window.draw(text_);
}
sfml_window::TextBox::TextBox(const Coord &position, const std::string &text)
    : position_(position) {

  if (!font_.loadFromFile("C:\\Users\\studio25\\Documents\\blockv2\\sfml_"
                         "window\\assets\\Georama-Medium.ttf"))
    throw "bad file";

  text_.setFont(font_);
  text_.setString(text);
  text_.setCharacterSize(30);
//  text_.setStyle(sf::Text::Bold);
}
void sfml_window::TextBox::SetButtonColor(const sf::Color &button_color) {
  text_color_ = button_color;
  text_.setOutlineColor(text_color_);
}
