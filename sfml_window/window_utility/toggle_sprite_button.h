//
// Created by studio25 on 17.08.2021.
//
/// toggleable button created from sprite object
#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_TOGGLE_SPRITE_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_TOGGLE_SPRITE_BUTTON_H_

#include "button.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace sfml_window {

/// the sprite the button has is pre defined
/// the button must react to being turned on by press
/// and hovered by mouse
class ToggleSpriteButton : public Button {
public:
  ToggleSpriteButton(const Rect &structure, const sf::Texture &sprite);
  ToggleSpriteButton(const ToggleSpriteButton &other);
  ToggleSpriteButton &operator=(const ToggleSpriteButton &other);

  /// clone function returns pointer to a new object of the Button type,
  /// \note new pointer must be deleted afterwards
  ToggleSpriteButton *Clone() override;
  /// handles user interaction with the button
  /// \param press_point coordinates of user mouse
  /// \param event action performed by user
  /// \return  true if button was pressed, false if not
  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;
  /// detects mouse hover
  /// \param press_point coordinates of user mouse
  /// \return true if appearance of button has changed
  bool DetectHover(const Coord &press_point) override;
  /// handles button display to sfm::window
  /// \param window targeted display
  void DrawToWindow(sf::RenderWindow &window) override;

  void SetButtonColor(const sf::Color &new_color) override;

  ~ToggleSpriteButton() override = default;
  /// switch button to it's on state
  void TurnOn();
  /// switch button to it's off state
  void TurnOff();

private:
  Rect structure_;

  /// true if the mouse us hovering
  bool hover_ = false;

  /// if true the button is turned on
  State state_ = State::DEFAULT;

  std::pair<sf::Texture,sf::Sprite> sprite_;


};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_TOGGLE_SPRITE_BUTTON_H_
