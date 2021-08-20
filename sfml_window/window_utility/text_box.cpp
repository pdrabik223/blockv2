//
// Created by studio25 on 01.08.2021.
//

#include "text_box.h"
#include <cassert>
#include <iostream>

sf::Font sfml_window::TextBox::font_;
void sfml_window::TextBox::DrawToWindow(sf::RenderWindow &window) {

  window.draw(text_);
}

void sfml_window::TextBox::SetFontSize(const Rect &boundaries) {
  if ((boundaries.height / 1.4) <
      (boundaries.width * 2 / (double)raw_text_.size()))
    font_size_ = (unsigned)(boundaries.height / 1.4);
  else
    font_size_ = (unsigned)(boundaries.width * 2 / raw_text_.size());

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

sfml_window::TextBox::TextBox(const Rect &position, const std::string &raw_text,
                              const sf::Color &text_color)
    : position_(position.placement), raw_text_(raw_text),
      text_color_(text_color) {

  if (!font_.loadFromFile("C:\\Users\\studio25\\Documents\\blockv2\\sfml_"
                          "window\\assets\\Georama-Medium.ttf"))
    throw "bad file";

  text_.setPosition(position_.x, position_.y);
  text_.setFont(font_);
  text_.setString(raw_text);
  SetFontSize(position);
  CenterText(position);
}
Rect sfml_window::TextBox::GetFontBoundaries() {

  return {{position_.x, position_.y},
          (unsigned)((font_size_ * raw_text_.size()) / 1.8),
          (unsigned)(font_size_ * 1.4)};
}
void sfml_window::TextBox::CenterText(const Rect &boundaries) {

  double width = (font_size_ * raw_text_.size()) / 2.0;
  double height = font_size_ * 1.4;

  assert(boundaries.width - width >= 0);
  assert(boundaries.height - height >= 0);

  position_ = boundaries.placement;
  if (boundaries.width - width > 1)
    position_.x += (unsigned)(boundaries.width - width) / 2;
  if (boundaries.height - height > 1)
    position_.y += (unsigned)(boundaries.height - height) / 2;
  text_.setPosition(position_.x, position_.y);
}
void sfml_window::TextBox::SetPosition(const Coord &position) {
  position_ = position;
  text_.setPosition(position_.x, position_.y);
}
void sfml_window::TextBox::SetText(const std::string &text) {
  raw_text_ = text;
  text_.setString(text);
}
std::string sfml_window::TextBox::GetText() { return raw_text_; }
