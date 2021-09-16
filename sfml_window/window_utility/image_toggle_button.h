//
// Created by studio25 on 13.08.2021.
//
/// toggleable button displaying image
#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_TOGGLE_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_TOGGLE_BUTTON_H_

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "button.h"
#include <array>
namespace sfml_window {

class ImageToggleButton : public Button {
public:
  ImageToggleButton(
      const Rect &structure,
      std::pair<const std::string &, const sf::Color &> default_image,
      std::pair<const std::string &, const sf::Color &> toggle_image);

  ImageToggleButton(const ImageToggleButton &other);
  /// clone function returns pointer to a new object of the Button type,
  /// \note new pointer must be deleted afterwards
  ImageToggleButton *Clone() override;
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

  ~ImageToggleButton() override = default;

protected:
  /// logic body of the button
  Rect structure_;
  bool hover_ = false;
  /// current button state
  State state_ = State::DEFAULT;

  std::array<sf::Texture, (int)State::SIZE> textures_; // this one for sure tho
  std::array<sf::Sprite, (int)State::SIZE> sprites_;
  std::array<sf::Color, (int)State::SIZE> colors_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_TOGGLE_BUTTON_H_
