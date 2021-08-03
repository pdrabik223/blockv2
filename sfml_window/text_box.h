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
  TextBox() = default;

  /// create an handle text on screen
  /// \param position placement of the text
  /// \param raw_text displayed message
  /// \param text_color color of text
  /// \param font_size the size of the displayed text
  TextBox(const Coord &position, const std::string &raw_text,
          const sf::Color &text_color, unsigned int font_size);

  /// create an handle text on screen
  /// \param position boundaries the text will fill
  /// \param raw_text displayed message
  /// \param text_color color of text
  /// \note the size of the text depends on position param
  TextBox(const Rect &position, const std::string &raw_text,
          const sf::Color &text_color);

  void DrawToWindow(sf::RenderWindow &window);

  void SetFontSize(const Rect &boundaries);

  void CenterText(const Rect &boundaries);

  Rect GetFontBoundaries();

protected:
  Coord position_;
  std::string raw_text_;
  sf::Text text_;
  sf::Font font_;
  sf::Color text_color_;
  unsigned font_size_;
};
} // namespace sfml_window

#endif // BLOCK_V2_SFML_WINDOW_TEXT_BOX_H_
