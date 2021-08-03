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
  ImageButton(const Rect &structure, const std::string &image_path);

public:
  bool DetectInteraction(const Coord &press_point, sf::Event &event) override;
  void DrawToWindow(sf::RenderWindow &window) override;
  void SetButtonColor(const sf::Color &button_color) override;

protected:
  Rect structure_;
  sf::Image image_; // I don't know if this needs to exist
  sf::Texture texture_; // this one for sure tho
  sf::Sprite sprite_;

};
}
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_BUTTON_H_
