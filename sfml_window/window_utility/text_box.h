//
// Created by studio25 on 01.08.2021.
//
/// displays text on the screen
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

  TextBox(const TextBox &other);
  TextBox &operator=(const TextBox &other);

  /// create an handle text on screen
  /// \param position boundaries the text will fill
  /// \param raw_text displayed message
  /// \param text_color color of text
  /// \note the size of the text depends on position param
  TextBox(const Rect &position, const std::string &raw_text,
          const sf::Color &text_color);

  /// handles button display to sfm::window
  /// \param window targeted display
  void DrawToWindow(sf::RenderWindow &window);

  Rect GetFontBoundaries();
  std::string GetText();

  void SetFontSize(const Rect &boundaries);
  void SetPosition(const Coord &position);
  void SetText(const std::string &text);

  /// scales and, centres text to fit withing given boundaries
  void CenterText(const Rect &boundaries);

  ~TextBox() = default;

protected:
  /// placement of top left corner of text
  Coord position_;
  /// raw text
  std::string raw_text_;

  sf::Text text_;
  /// font used to display text
  static sf::Font font_;
  /// text color
  sf::Color text_color_;
  /// text size
  unsigned font_size_;
};
} // namespace sfml_window

#endif // BLOCK_V2_SFML_WINDOW_TEXT_BOX_H_
