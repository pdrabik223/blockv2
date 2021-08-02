//
// Created by studio25 on 01.08.2021.
//

#include "text_box.h"
void sfml_window::TextBox::DrawToWindow(sf::RenderWindow &window) {
  window.draw(text_);
}

void sfml_window::TextBox::SetFontSize(const Rect &boundaries) {
  // todo test this function
  font_size_ = boundaries.width / raw_text_.size();
  text_.setCharacterSize(font_size_);
}

sfml_window::TextBox::TextBox(const Coord &position,
                              const std::string &raw_text,
                              const sf::Color &text_color,
                              unsigned int font_size)
    : position_(position), raw_text_(raw_text), text_color_(text_color),
      font_size_(font_size) {

  if (!font_.loadFromFile("C:\\Users\\studio25\\Documents\\blockv2\\sfml_"
                          "window\\assets\\Georama-Medium.ttf"))
    throw "bad file";

  text_.setPosition(position_.x, position_.y);
  text_.setFont(font_);
  text_.setString(raw_text);
  text_.setCharacterSize(font_size);
}

sfml_window::TextBox::TextBox(const Rect &position,
                              const std::string &raw_text,
                              const sf::Color &text_color)
    : position_(position.placement), raw_text_(raw_text), text_color_(text_color) {

  if (!font_.loadFromFile("C:\\Users\\studio25\\Documents\\blockv2\\sfml_"
                          "window\\assets\\Georama-Medium.ttf"))
    throw "bad file";

  text_.setPosition(position_.x, position_.y);
  text_.setFont(font_);
  text_.setString(raw_text);
  SetFontSize(position);
}
const Coord &sfml_window::TextBox::GetFontBoundaries() {

}
