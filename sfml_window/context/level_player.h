//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PLAYER_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PLAYER_H_

#include "../../level_info.h"
#include "context.h"
#include "image_button.h"
#include "text_button.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <short_level_info.h>

namespace sfml_window {

enum class LevelPlayerButton { EXIT, RUN_SIMULATION, SIZE };

class LevelPlayer : public Context {
public:

  /// run provided simulation
  /// \param level_info full level info object
  /// \param window_height of the window
  /// \param window_width of the window
  LevelPlayer(unsigned int window_width, unsigned int window_height, LevelInfo &level_info);

public:
  void LoadColors() override;

  void DrawToWindow(sf::RenderWindow &window) override;

  sfml_window::ContextEvent
  HandleEvent(sf::Event &event, const sf::RenderWindow &window) override;

private:
  void LoadButtons();
  void LoadBackground();

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
}
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PLAYER_H_
