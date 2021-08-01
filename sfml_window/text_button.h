//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_

#include "../sfml_window/button.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
namespace sfml_window {
class TextButton : public Button {

public:
  TextButton(const Rect &position, const std::string &text);
  bool DetectHover(const Coord &press_point) override;
  bool DetectPress(const Coord &press_point, sf::Event &event) override;
  void DrawToWindow(sf::RenderWindow &window) override;

protected:
  Rect position_;
  sf::Text text_;
  sf::RectangleShape background_;
  /// if mouse is hovering over the button the font is larger
  bool hover_;

  sf::Font font_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_
