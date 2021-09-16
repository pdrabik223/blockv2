//
// Created by studio25 on 03.08.2021.
//
/// button displaying image
#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_BUTTON_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_BUTTON_H_
#include "button.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace sfml_window {
class ImageButton : public Button {
public:
  ImageButton();
  ImageButton(const Rect &structure, const std::string &image_path,
              const sf::Color &color);

  ImageButton(const ImageButton &other);
  ImageButton &operator=(const ImageButton &other);

  /// clone function returns pointer to a new object of the Button type,
  /// \note new pointer must be deleted afterwards
  ImageButton *Clone() override;
  ~ImageButton() override = default;
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

  /// setters for chosen fields

  bool SetHover(bool hover);
  void SetButtonColor(const sf::Color &new_color) override;
  void SetPosition(const Coord &position);
  /// getters for chosen fields

  const Rect &GetStructure() const;
  const sf::Color &GetColor() const;
  bool IsHover() const;

protected:
  Rect structure_;
  sf::Color color_;
  bool hover_ = false;
  sf::Texture texture_; // this one for sure tho
  sf::Sprite sprite_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_IMAGE_BUTTON_H_
