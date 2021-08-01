//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_BUTTON_H_

#include "../sfml/include/SFML/Graphics/RenderWindow.hpp"
#include "../sfml/include/SFML/Window/Event.hpp"
#include <rect.h>
namespace sfml_window {
class Button {

public:
  virtual bool DetectHover(const Coord &press_point) = 0;
  virtual bool DetectPress(const Coord &press_point,sf::Event& event) = 0;
  virtual void DrawToWindow(sf::RenderWindow &window) = 0;

protected:
  Rect position_;
};
} // namespace sfml
#endif // BLOCK_V2_SFML_WINDOW_BUTTON_H_
