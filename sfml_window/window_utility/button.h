//
// Created by studio25 on 01.08.2021.
//
/// template class for button class tree
#ifndef BLOCK_V2_SFML_WINDOW_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_BUTTON_H_


#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Window/Event.hpp"

#include <rect.h>
#include "gui_color.h"

namespace sfml_window {
/// common button states
enum class State { DEFAULT, TOGGLE, SIZE };
class Button {
public:
  /// handles user interaction with the button
  /// \param press_point coordinates of user mouse
  /// \param event action performed by user
  /// \return  true if button was pressed, false if not
  virtual bool DetectInteraction(const Coord &press_point,
                                 sf::Event &event) = 0;
  /// handles button display to sfm::window
  /// \param window targeted display
  virtual void DrawToWindow(sf::RenderWindow &window) = 0;
  /// detects mouse hover
  /// \param press_point coordinates of user mouse
  /// \return true if appearance of button has changed
  virtual bool DetectHover(const Coord &press_point) = 0;

  virtual void SetButtonColor(const sf::Color &new_color) = 0;
  /// clone function returns pointer to a new object of the Button type,
  /// \note new pointer must be deleted afterwards
  virtual Button *Clone() = 0;
  virtual ~Button() = default;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_BUTTON_H_
