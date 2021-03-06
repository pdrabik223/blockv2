//
// Created by studio25 on 20.08.2021.
//
/// toggleable text button
#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_TOGGLE_TEXT_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_TOGGLE_TEXT_BUTTON_H_


#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "button.h"
#include "text_box.h"
 namespace sfml_window {
/// the size of the button depends on the text within
class ToggleTextButton : public Button {
public:
  ToggleTextButton() = default;
  ToggleTextButton(const ToggleTextButton& other);
  ToggleTextButton& operator=(const ToggleTextButton& other);

  ///
  /// \param structure  the position on screen and boundaries the text will fill
  /// \param text displayed text
  /// \param button_color color of the text
  /// \param display_background true if the background should be displayed, false if not
  ToggleTextButton(const Rect &structure, const std::string &text,
                   const sf::Color &button_color, bool display_background);

  /// \param position  the position on screen, actual size of button will be set
  /// to the size of text \param text displayed text \param button_color color
  /// of the text \param display_background true if the background should be
  /// displayed, false if not \param font_size the size of button letters
  ToggleTextButton(const Coord &position, const std::string &text,
                   const sf::Color &button_color, bool display_background,
                   unsigned font_size);

  /// clone function returns pointer to a new object of the Button type,
  /// \note new pointer must be deleted afterwards
  ToggleTextButton *Clone() override;
  ~ToggleTextButton() override;

  /// updates look of a button depending on the position of mouse
  /// \param press_point current mouse position on screen
  /// \param event last window event
  /// \return true if button is pressed
  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;

  /// detects mouse hover
  /// \param press_point coordinates of user mouse
  /// \return true if appearance of button has changed

  bool DetectHover(const Coord &press_point) override;

  /// display current look of a button to window
  /// \param window target to display button to
  void DrawToWindow(sf::RenderWindow &window) override;

  void SetPosition(const Coord &position);
  void SetButtonColor(const sf::Color &new_color) override;

  void SetText(const std::string &text);
  std::string GetText();

  /// switch button to it's on state
  void TurnOn();
  /// switch button to it's off state
  void TurnOff();

protected:
  Rect structure_;
  sf::RectangleShape background_;
  TextBox text_;

  sf::Color button_color_;
  /// if mouse is hovering over the background is displaying
  bool hover_ = false;
  State state_ = State::DEFAULT;
  bool display_background_ = false;
};
}
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_TOGGLE_TEXT_BUTTON_H_
