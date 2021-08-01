//
// Created by studio25 on 01.08.2021.
//

#include "gui_color.h"

sf::Color& Light(sf::Color& color){

  int break_point = 255-60;
  color.r = color.r > break_point ? 255 : color.r+60;
  color.g = color.g > break_point ? 255 : color.g+60;
  color.b = color.b > break_point ? 255 : color.b+60;
  return color;
}