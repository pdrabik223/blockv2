//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_BUTTON_H_
#include "button.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace sfml_window {
class ImageButton : public Button {
public:
  ImageButton(const Rect &structure, const std::string &image_path,
              const sf::Color &color);

  ImageButton(const ImageButton& other);
  ImageButton & operator=(const ImageButton& other);

  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;
  bool DetectHover(const Coord &press_point) override;
  void DrawToWindow(sf::RenderWindow &window) override;
  void SetButtonColor(const sf::Color &button_color) override;
  ~ImageButton() override = default;
  ImageButton *Clone() override;

protected:
  Rect structure_;
  sf::Color color_;
  bool hover_ = false;
  sf::Texture texture_; // this one for sure tho
  sf::Sprite sprite_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_BUTTON_H_
