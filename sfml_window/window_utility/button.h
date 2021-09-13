//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_BUTTON_H_


#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Window/Event.hpp"

#include <rect.h>
#include "gui_color.h"

namespace sfml_window {

enum class State { DEFAULT, TOGGLE, SIZE };
class Button {

public:
  virtual bool DetectInteraction(const Coord &press_point, sf::Event &event) = 0;
  virtual void DrawToWindow(sf::RenderWindow &window) = 0;
  virtual bool DetectHover(const Coord &press_point) = 0;
  virtual void SetButtonColor(const sf::Color &new_color) = 0;
  virtual Button *Clone() = 0;
  virtual ~Button() = default;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_BUTTON_H_
