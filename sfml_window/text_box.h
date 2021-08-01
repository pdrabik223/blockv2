//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_TEXT_BOX_H_
#define BLOCK_V2_SFML_WINDOW_TEXT_BOX_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <rect.h>
namespace sfml_window {
class TextBox {
public:
  TextBox(const Coord &position, const std::string &text);
  void DrawToWindow(sf::RenderWindow &window);
  void SetButtonColor(const sf::Color &button_color);

protected:
  Coord position_;
  sf::Text text_;
  sf::Font font_;
  sf::Color text_color_;
};
}
#endif // BLOCK_V2_SFML_WINDOW_TEXT_BOX_H_
