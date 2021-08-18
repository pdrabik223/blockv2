//
// Created by studio25 on 17.08.2021.
//

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

  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;
  bool DetectHover(const Coord &press_point) override;
  void DrawToWindow(sf::RenderWindow &window) override;
  void SetButtonColor(const sf::Color &button_color) override {};

  ~ToggleSpriteButton() override = default;
  ToggleSpriteButton  *Clone() override;
  void TurnOn();
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
