//
// Created by studio25 on 13.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_TOGGLE_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_TOGGLE_BUTTON_H_

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "button.h"
namespace sfml_window {
enum class State { DEFAULT, TOGGLE };
class ImageToggleButton : public Button {
  ImageToggleButton(const Rect &structure, const std::string &image_path,
                    const sf::Color &color);

public:
  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;
  bool DetectHover(const Coord &press_point) override;
  void DrawToWindow(sf::RenderWindow &window) override;
  void SetButtonColor(const sf::Color &button_color) override;

protected:
  Rect structure_;
  sf::Color color_;
  bool hover_ = false;

  State state_ = State::DEFAULT;
  std::vector<sf::Texture> textures_; // this one for sure tho
  std::vector<sf::Sprite> sprites_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_TOGGLE_BUTTON_H_
