//
// Created by studio25 on 03.08.2021.
//

#include "level_picker.h"

void sfml_window::LevelPicker::LoadButtons() {
  std::string directory = "../sfml_window/assets/level_picker/";

  buttons_[(unsigned)LevelPickerButton::EXIT] =
      new ImageButton(Rect(Coord(window_width_ - 36, 4), 32, 32),
                      directory + "cancel-button.png",
                      sf::Color::Red);

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

  bool change = false; // if true window should be re-loaded to display change
                       // in appearance

  if (event.type == sf::Event::MouseButtonReleased) {

    for (unsigned id = 0; id < buttons_.size(); id++)

      if (buttons_[id]->DetectInteraction({mouse_x, mouse_y}, event))

        switch ((LevelPickerButton)id) {
        case LevelPickerButton::EXIT:
          return ContextEvent::SWITCH_TO_MAIN_MENU;
        case LevelPickerButton::PAGE_UP:
          break;
        case LevelPickerButton::PAGE_DOWN:
          if (page_)
            break;
        }
  } else {

    for (auto &button : buttons_)
      if (button->DetectHover({mouse_x, mouse_y}))
        change = true;
  }

  if (event.type == sf::Event::MouseButtonReleased) {
    for (auto &level : levels_)
      if (level.DetectInteraction({mouse_x, mouse_y}, event)) {
        path_to_chosen_level_ = level.GetPath();
        return ContextEvent::SWITCH_TO_LEVEL_PLAYER;
      }
  } else {
    for (auto &level : levels_)
      if (level.DetectHover({mouse_x, mouse_y}))
        change = true;
  }

  if (change)
    return ContextEvent::UPDATE_DISPLAY;

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

  for (const auto &f : file_paths) {
    levels_.emplace_back(ShortLevelInfo(directory + f, font_size_,
                                        Rainbow(i, file_paths.size())));
    i++;
  }
}

void sfml_window::LevelPicker::DrawLevels(sf::RenderWindow &window) {

  // height of one displayed text
  double height = font_size_ * 1.4;

  const int kPx = 40;

  const int kNumberOfLevelsOnScreen = (int)(window_height_ / height) - 2;

  max_page_ = 1 + levels_.size() / kNumberOfLevelsOnScreen;

  int py = (int)height;

  for (int i = 0; i < kNumberOfLevelsOnScreen; i++) {
    if (i == levels_.size())
      break;
    levels_[i + kNumberOfLevelsOnScreen * page_].DrawToWindow(
        window, {kPx, py + i * py});
  }
}

std::string sfml_window::LevelPicker::GetLevelDirectory() {
  return path_to_chosen_level_;
}

sfml_window::LevelPicker *sfml_window::LevelPicker::Clone() {
  return new LevelPicker(*this);
}
LevelInfo sfml_window::LevelPicker::GetLevelInfo() { return LevelInfo(2, 1); }
sfml_window::LevelPicker::~LevelPicker() {
  for (auto &b : buttons_)
    delete b;
}
sfml_window::LevelPicker::LevelPicker(const LevelPicker &other) {
  window_width_ = other.window_width_;
  window_height_ = other.window_height_;
  background_texture_ = other.background_texture_;
  background_sprite_ = other.background_sprite_;

  for (int i = 0; i < other.buttons_.size(); i++)
    buttons_[i] = other.buttons_[i]->Clone();

  font_size_ = other.font_size_;

  page_ = other.page_;
  max_page_ = other.max_page_;

  levels_ = other.levels_;
  path_to_chosen_level_ = other.path_to_chosen_level_;
}
Board sfml_window::LevelPicker::GetLevel() { return Board(LevelInfo(2,1));; }
