//
// Created by studio25 on 01.08.2021.
//

#include "gui_color.h"

sf::Color Light(const sf::Color &color) {
  sf::Color light_color = color;

  int upper_break_point = 255 - 90;

  light_color.r = light_color.r > upper_break_point ? 255 : light_color.r + 90;
  light_color.g = light_color.g > upper_break_point ? 255 : light_color.g + 90;
  light_color.b = light_color.b > upper_break_point ? 255 : light_color.b + 90;
  return light_color;
}