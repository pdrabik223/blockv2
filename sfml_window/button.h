//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_BUTTON_H_

#include "../sfml/include/SFML/Graphics/RenderWindow.hpp"
#include "../sfml/include/SFML/Window/Event.hpp"
#include <gui_color.h>
#include <rect.h>
namespace sfml_window {
class Button {

public:
  virtual bool DetectInteraction(const Coord &press_point, sf::Event &event) = 0;
  virtual void DrawToWindow(sf::RenderWindow &window) = 0;
  virtual void SetButtonColor(const sf::Color &button_color) = 0;

protected:
  Rect position_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_BUTTON_H_
