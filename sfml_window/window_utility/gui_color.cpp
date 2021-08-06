//
// Created by studio25 on 01.08.2021.
//

#include "gui_color.h"

sf::Color Light(const sf::Color& color){
  sf::Color light_color = color;
  int break_point = 255-50;
  light_color.r = color.r > break_point ? 255 : color.r+50;
  light_color.g = color.g > break_point ? 255 : color.g+50;
  light_color.b = color.b > break_point ? 255 : color.b+50;
  return light_color;
}