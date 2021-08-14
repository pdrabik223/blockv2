//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "context.h"
#include "text_button.h"
/// displays the content of the levels directory, and enables user to choose
/// witch level they want to play

namespace sfml_window {
enum class LevelPickerButton { EXIT, SIZE };
class LevelPicker : public Context {

  void LoadColors() {}
  void DrawToWindow(sf::RenderWindow &window) {}
  sfml_window::ContextEvent HandleEvent(sf::Event &event,
                                        const sf::RenderWindow &window) {
    return sfml_window::ContextEvent::NONE;
  }

public:
  /// \format in pixels
  /// x axis domain = <0,window_width_>
  unsigned window_width_;

  /// \format in pixels
  /// y axis domain = <0,window_height_>
  unsigned window_height_;

  /// background texture
  sf::Texture background_texture_;
  /// background sprite always provided by user
  sf::Sprite background_sprite_;

  std::array<Button *, (unsigned)LevelPickerButton::SIZE> buttons_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_
