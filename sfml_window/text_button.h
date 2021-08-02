//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_

#include "../sfml_window/button.h"
#include "text_box.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
namespace sfml_window {
/// the size of the button depends on the text within
class TextButton : public Button {

public:
  TextButton(const Rect &structure, const std::string &text,
             const sf::Color &button_color, bool display_background,
             bool rigid_structure);

  TextButton(const Coord &position, const std::string &text);
  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;
  void DrawToWindow(sf::RenderWindow &window) override;
  void SetButtonColor(const sf::Color &button_color) override;

protected:
  Rect structure_;
  sf::RectangleShape background_;
  TextBox text_;

  /// if mouse is hovering over the button the font is larger
  bool hover_;

  sf::Color button_color_;

  bool display_background_;
  bool rigid_structure_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_
