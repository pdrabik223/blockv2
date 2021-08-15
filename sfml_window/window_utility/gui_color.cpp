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

sf::Color Rainbow(unsigned value, unsigned max_value) {

  char witch_third = (double)value / (double)((double)max_value / 3.0);

  double height_in_radians;
  switch (witch_third) {
  case 0:
    height_in_radians = value * 3.1415 / (max_value / 3) / 2;

    return sf::Color(cos(height_in_radians) * 255, sin(height_in_radians) * 255,
                     0);
  case 1:
    value -= max_value / 3;
    height_in_radians = value * 3.1415 / (max_value / 3) / 2;
    return sf::Color(0, cos(height_in_radians) * 255,
                     sin(height_in_radians) * 255);

  case 2:
    value -= 2 * max_value / 3;
    height_in_radians = value * 3.1415 / (max_value / 3) / 2;
    return sf::Color(sin(height_in_radians) * 255, 0,
                     cos(height_in_radians) * 255);
  }

  return {255, 0, 0};
}