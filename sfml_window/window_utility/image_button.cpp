//
// Created by studio25 on 03.08.2021.
//

#include "image_button.h"
#include <cassert>
#include <iostream>

bool sfml_window::ImageButton::DetectInteraction(const Coord &press_point,
                                                 sf::Event &event) {
  bool hover = structure_.CheckWBoundaries(press_point);

  return hover && (event.type == sf::Event::MouseButtonReleased &&
                   event.mouseButton.button == sf::Mouse::Left);
}
sfml_window::ImageButton::ImageButton() : structure_(), color_(RED) {

  texture_ = sf::Texture();
  texture_.setSmooth(true);
  sprite_.setTexture(texture_);
  sprite_.setColor(Light(color_));
  sprite_.setPosition((float)structure_.placement.x,
                      (float)structure_.placement.y);
  sprite_.setScale((float)structure_.width / (float)texture_.getSize().x,
                   (float)structure_.height / (float)texture_.getSize().y);
}

sfml_window::ImageButton::ImageButton(const ImageButton &other) {
  structure_ = other.structure_;
  color_ = other.color_;
  hover_ = other.hover_;
  texture_ = other.texture_;
  sprite_ = other.sprite_;
}
sfml_window::ImageButton &
sfml_window::ImageButton::operator=(const sfml_window::ImageButton &other) {

  if(&other == this) return *this;

  structure_ = other.structure_;
  color_ = other.color_;
  hover_ = other.hover_;
  texture_ = other.texture_;
  sprite_ = other.sprite_;

  return *this;
}


void sfml_window::ImageButton::DrawToWindow(sf::RenderWindow &window) {

  if(hover_)
    sprite_.setColor(color_);
  else
    sprite_.setColor(Light(color_));
  window.draw(sprite_);
}

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

void sfml_window::ImageButton::SetColor(const sf::Color &new_color) {
  color_ = new_color;
  sprite_.setColor(Light(color_));
}
void sfml_window::ImageButton::SetPosition(const Coord &position) {
  structure_.placement = position;
  sprite_.setPosition((float)structure_.placement.x,
                      (float)structure_.placement.y);

  //  std::cout<<"\nplacement :"<<
  //  structure_.placement.x<<"\t"<<structure_.placement.y;
}
