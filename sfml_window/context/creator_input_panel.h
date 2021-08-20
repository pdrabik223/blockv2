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
#include <toggle_text_button.h>

namespace sfml_window {
enum class CreatorInputPanelButton {
  EXIT,
  SAVE_LEVEL,
  SIZE
};
enum class CreatorInputPanelTextField {
  LEVEL_NAME,
  AUTHOR_NAME,
  WIDTH,
  HEIGHT,
  SIZE
};

class CreatorInputPanel : public Context {
public:
  CreatorInputPanel(unsigned int window_width, unsigned int window_height,
                    const LevelInfo &target);
  CreatorInputPanel(const CreatorInputPanel& other);


  void DrawToWindow(sf::RenderWindow &window) override;

  ContextEvent HandleEvent(sf::Event &event,
                           const sf::RenderWindow &window) override;

  CreatorInputPanel *Clone() override;
  Board GetLevel() override;
  LevelInfo GetLevelInfo() override;
  std::string GetLevelDirectory() override;
  ~CreatorInputPanel() override;

private:
  /// load buttons to memory
  void LoadButtons();

  /// Loads background to memory
  void LoadBackground();

  /// Load Text Boxes
  void LoadCreatorInputPanelTexts();

  /// Load Text Boxes labels
  void LoadLabels();

  void ClearHighlight();

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

  std::array<Button *, (unsigned)CreatorInputPanelButton::SIZE> buttons_;

  std::array<ToggleTextButton, (unsigned)CreatorInputPanelTextField::SIZE> input_panels_;
  std::array<TextBox, (unsigned)CreatorInputPanelTextField::SIZE> input_panels_labels_;

  LevelInfo target_;

  CreatorInputPanelTextField in_focus_ = CreatorInputPanelTextField::LEVEL_NAME;


};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_CREATOR_INPUT_PANEL_H_
