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
/// list  of buttons
enum class CreatorInputPanelButton {
  EXIT,
  SAVE_LEVEL,
  WIDTH_UP,
  WIDTH_DOWN,
  HEIGHT_DOWN,
  HEIGHT_UP,
  SIZE
};
/// list of text fields
enum class CreatorInputPanelTextField {
  LEVEL_NAME,
  AUTHOR_NAME,
  WIDTH,
  HEIGHT,
  SIZE
};
/// additional info input panel
class CreatorInputPanel : public Context {
public:
  CreatorInputPanel(unsigned int window_width, unsigned int window_height,
                    const LevelInfo &target);

  CreatorInputPanel(const CreatorInputPanel &other);
  CreatorInputPanel &operator=(const CreatorInputPanel &other);

  /// display current context to window
  /// \param window target to display button to
  void DrawToWindow(sf::RenderWindow &window) override;

  ///  handles incoming events,
  /// translates incoming event, and mouse position to ContextEvent
  /// \param event new even
  /// \param window source of mouse position info
  /// \return new translated event
  ContextEvent HandleEvent(sf::Event &event,
                           const sf::RenderWindow &window) override;
  /// clone function returns pointer to a new object of the Context type,
  /// \note new pointer must be deleted afterwards
  CreatorInputPanel *Clone() override;

  GameEngine GetLevel() override;
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

  /// clear button highlights
  void ClearHighlight();
  /// handle incoming keyboard event
  /// \param event incoming keyboard press
  /// \return true if pressed button was a number
  bool HandleNumber(const sf::Event &event);
  /// handle incoming keyboard event
  /// \param event incoming keyboard press
  /// \return true if pressed button was a letter
  bool HandleLetter(const sf::Event &event);
  /// handle incoming keyboard event
  /// \param event incoming keyboard press
  /// \return true if pressed button was other button like a space
  bool HandleFunctional(const sf::Event &event);
  /// update level information based on information in buttons
  void UpdateLevel();

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
  /// the gray button background on top of the screen
  sf::RectangleShape button_background_;

  /// all of the buttons
  std::array<Button *, (unsigned)CreatorInputPanelButton::SIZE> buttons_;
  /// input panels
  std::array<ToggleTextButton, (unsigned)CreatorInputPanelTextField::SIZE> input_panels_;
  /// text boxes
  std::array<TextBox, (unsigned)CreatorInputPanelTextField::SIZE> input_panels_labels_;

  /// edited level
  LevelInfo target_;

  /// current edited button
  CreatorInputPanelTextField in_focus_ = CreatorInputPanelTextField::SIZE;


};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_CREATOR_INPUT_PANEL_H_
