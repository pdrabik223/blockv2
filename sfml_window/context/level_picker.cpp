//
// Created by studio25 on 03.08.2021.
//

#include "level_picker.h"
#include <fstream>
#include <iostream>
void sfml_window::LevelPicker::LoadColors() {
  color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR] = sf::Color(0x0035d6);
  color_palette_[(unsigned)GuiColor::MENU_SECONDARY_COLOR] =
      sf::Color(0xa000d6);
  color_palette_[(unsigned)GuiColor::MENU_TERTIARY_COLOR] = sf::Color(0xd6a000);
  color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR] =
      sf::Color(27, 27, 27);
  color_palette_[(unsigned)GuiColor::DANGER_COLOR] = sf::Color(255, 0, 0);
  color_palette_[(unsigned)GuiColor::WARNING_COLOR] = sf::Color(255, 255, 0);
  color_palette_[(unsigned)GuiColor::INFORMATIVE_COLOR] = sf::Color(0, 0, 255);
  color_palette_[(unsigned)GuiColor::SAFE_COLOR] = sf::Color(0, 255, 0);
}

void sfml_window::LevelPicker::LoadButtons() {
  std::string directory = "../sfml_window/assets/level_picker/";

  buttons_[(unsigned)LevelPickerButton::EXIT] =
      new ImageButton(Rect(Coord(window_width_ - 36, 4), 32, 32),
                      directory + "cancel-button.png",
                      color_palette_[(unsigned)GuiColor::DANGER_COLOR]);

  buttons_[(unsigned)LevelPickerButton::PAGE_UP] =
      new ImageButton(Rect(Coord((window_width_ / 4) - 36 * 2, 4), 32, 32),
                      directory + "page_up.png", {255, 255, 255});

  buttons_[(unsigned)LevelPickerButton::PAGE_DOWN] = new ImageButton(
      Rect(Coord((window_width_ / 4) - 36 * 2, window_height_ - 36), 32, 32),
      directory + "page_down.png", {255, 255, 255});
}

sfml_window::LevelPicker::LevelPicker(unsigned int window_width,
                                      unsigned int window_height)
    : window_width_(window_width), window_height_(window_height) {
  LoadColors();
  LoadButtons();
  LoadBackground();
  LoadLevels();
}

void sfml_window::LevelPicker::DrawToWindow(sf::RenderWindow &window) {
  window.draw(background_sprite_);

  for (const auto &button : buttons_)
    button->DrawToWindow(window);

    DrawLevels(window);
}

sfml_window::ContextEvent
sfml_window::LevelPicker::HandleEvent(sf::Event &event,
                                      const sf::RenderWindow &window) {
  int mouse_x = sf::Mouse::getPosition(window).x;
  int mouse_y = sf::Mouse::getPosition(window).y;

  mouse_x = mouse_x < 0 ? 0 : mouse_x;
  mouse_y = mouse_y < 0 ? 0 : mouse_y;

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_ - 1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_ - 1;

  if (event.type == sf::Event::MouseButtonReleased) {

    for (unsigned id = 0; id < buttons_.size(); id++)

      if (buttons_[id]->DetectInteraction({mouse_x, mouse_y}, event))

        switch ((LevelPickerButton)id) {
        case LevelPickerButton::EXIT:
          return ContextEvent::SWITCH_TO_MAIN_MENU;
        }
  } else {

    bool change = false;
    for (auto &button : buttons_)
      if (button->DetectHover({mouse_x, mouse_y}))
        change = true;

    if (change)
      return ContextEvent::UPDATE_DISPLAY;
  }
//  if (event.type == sf::Event::MouseButtonReleased) {
//    // this level_path = short_level.GetPath()
//    // return  ContextEvent::SWITCH_TO_LEVEL_PLAY;
  //  }else {
  //      bool change = false;
  //    for (auto &button : buttons_)
  //      if (level->DetectHover({mouse_x, mouse_y}))
  //        change = true;
  //  }

  return ContextEvent::NONE;
}
void sfml_window::LevelPicker::LoadBackground() {

  if (!background_texture_.loadFromFile(
          "../sfml_window/assets/level_picker/background.png"))
    throw "error";
  background_texture_.setSmooth(true);
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale(
      (float)window_width_ / (float)background_texture_.getSize().x,
      (float)window_height_ / (float)background_texture_.getSize().y);
}

/// populates output with sub-directories for directory
void ReadDirectory(const std::string &directory,
                   std::vector<std::string> &output) {
  std::string pattern(directory);
  // if pattern  = "*" all files in the directory will be found
  pattern.append("*");
  WIN32_FIND_DATA data;
  HANDLE hFind;

  output.clear();

  if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
    do {
      output.emplace_back(data.cFileName);
    } while (FindNextFile(hFind, &data) != 0);
    FindClose(hFind);
  }

  for (int i = output.size() - 1; i >= 0; --i) {
    if (output[i] == "." or output[i] == ".." or output[i] == "default")
      output.erase(output.begin() + i);
  }
}

void sfml_window::LevelPicker::LoadLevels() {
  std::vector<std::string> file_paths;

  ReadDirectory("../levels/", file_paths);
  LoadLevelInfo(file_paths);

  for (auto &i : file_paths)
    std::cout << i << "\n";
}

void sfml_window::LevelPicker::LoadLevelInfo(
    const std::vector<std::string> &file_paths) {

  std::string directory = "../levels/";
  int i = 0;
  const int kLevelSize = file_paths.size();
  levels_ = new ShortLevelInfo[kLevelSize];

  for (const auto &f : file_paths) {
    levels_[i] = ShortLevelInfo(directory + f + "/" + f, font_size_,
                                     Rainbow(i, file_paths.size()));
    i++;
  }

}

void sfml_window::LevelPicker::DrawLevels(sf::RenderWindow &window) {

  // height of one displayed text
  double height = font_size_ * 1.4;

  const int kPx = 40;

  const int kNumberOfLevelsOnScreen = (int)(window_height_ / height) - 2;

  int py = (int)height;

  for (int i = 0; i < 1; i++) {
//    if (i == levels_.size())
//      break;
    levels_[i + kNumberOfLevelsOnScreen * page_].DrawToWindow(
        window, {kPx, py + i * py});
  }
}
