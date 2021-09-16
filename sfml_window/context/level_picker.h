//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_

#include <Windows.h>
#include <vector>

#include "context.h"
#include "image_button.h"
#include "text_button.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <fstream>
#include <iostream>
#include <short_level_info.h>

/// displays the content of the levels directory, and enables user to choose
/// witch level they want to play

namespace sfml_window {

enum class LevelPickerButton { EXIT, PAGE_UP, PAGE_DOWN, TROPHY_IMAGE, SIZE };

enum class LevelPickerTextBox { PROGRESS_COUNTER, PAGE_NUMBER, SIZE };

class LevelPicker : public Context {
public:
  /// open chose level screen
  /// \param window_height of the window
  /// \param window_width of the window
  LevelPicker(unsigned int window_width, unsigned int window_height);

  LevelPicker(const LevelPicker &other);
  LevelPicker &operator=(const LevelPicker &other);

  LevelPicker *Clone() override;
  void DrawToWindow(sf::RenderWindow &window) override;

  sfml_window::ContextEvent
  HandleEvent(sf::Event &event, const sf::RenderWindow &window) override;

  std::string GetLevelDirectory() override;
  GameEngine GetLevel() override;
  LevelInfo GetLevelInfo() override;

  ~LevelPicker() override;

private:
  /// load buttons to memory
  void LoadButtons();

  /// loads text fields to memory
  void LoadTextFields();

  /// Loads background to memory
  void LoadBackground();

  /// check for all subdirectories for leves
  /// and load short Level info for existing ones to memory
  void LoadLevels();

  /// calculate current positions and display levels
  /// that fit on the screen
  void DrawLevels(sf::RenderWindow &window);

  /// checks levels directory for existing levels and populates levels_ field
  /// wit results of search
  /// created text field will have assigned color and size but not a position
  /// position is calculated ad drawing time
  void LoadLevelInfo(const std::vector<std::string> &file_paths);

  unsigned CountTrophys();

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

  std::array<TextBox, (unsigned)LevelPickerTextBox::SIZE> text_fields_;

  /// level will be displayed with this font size
  unsigned font_size_ = 24;

  /// current displayed levels
  /// every page accommodates 15 levels
  int page_ = 0;

  /// how many pages of levels can be found on drive
  int no_pages_ = 1;

  std::vector<ShortLevelInfo> levels_;

  std::string path_to_chosen_level_ = "none_chosen";
  void UpdatePageNumber();
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_
