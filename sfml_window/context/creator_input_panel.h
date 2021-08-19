//
// Created by studio25 on 19.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_CREATOR_INPUT_PANEL_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_CREATOR_INPUT_PANEL_H_

#include "context.h"

#include "image_button.h"
#include "text_button.h"
#include <toggle_sprite_button.h>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <short_level_info.h>

namespace sfml_window {
enum class CreatorInputPanelButtons{
  EXIT,
  SIZE
};

class CreatorInputPanel : public Context {
public:
  void DrawToWindow(sf::RenderWindow &window) override;
  ContextEvent HandleEvent(sf::Event &event,
                           const sf::RenderWindow &window) override;
  CreatorInputPanel *Clone() override;
  Board GetLevel() override;
  LevelInfo GetLevelInfo() override;
  std::string GetLevelDirectory() override;
  ~CreatorInputPanel() override;
protected:
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

  sf::RectangleShape button_background_;

  std::array<Button *, (unsigned)CreatorInputPanelButtons::SIZE> buttons_;

  LevelInfo target_;

};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_CREATOR_INPUT_PANEL_H_
