//
// Created by studio25 on 01.08.2021.
//

#include "gui_color.h"

sf::Color& Light(sf::Color& color){

  int break_point = 255-40;
  color.r = color.r > break_point ? 255 : color.r+40;
  color.g = color.g > break_point ? 255 : color.g+40;
  color.b = color.b > break_point ? 255 : color.b+40;
  return color;
}