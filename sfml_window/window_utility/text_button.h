//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_

#include "../window_utility/button.h"
#include "../window_utility/text_box.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
namespace sfml_window {
/// the size of the button depends on the text within
class TextButton : public Button {

public:
  TextButton() = default;

  ///
  /// \param structure  the position on screen and boundaries the text will fill
  /// \param text displayed text
  /// \param button_color color of the text
  /// \param display_background true if the background should be displayed, false if not
  TextButton(const Rect &structure, const std::string &text,
             const sf::Color &button_color, bool display_background);

  /// \param position  the position on screen, actual size of button will be set to the size of text
  /// \param text displayed text
  /// \param button_color color of the text
  /// \param display_background true if the background should be displayed, false if not
  /// \param font_size the size of button letters
  TextButton(const Coord &position,const std::string &text, const sf::Color &button_color,
             bool display_background,unsigned font_size);

  /// updates look of a button depending on the position of mouse
  /// \param press_point current mouse position on screen
  /// \param event last window event
  /// \return true if button is pressed
  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;

  /// display current look of a button to window
  /// \param window target to display button to
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

};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_TEXT_BUTTON_H_
