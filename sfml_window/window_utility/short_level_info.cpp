//
// Created by studio25 on 14.08.2021.
//

#include "short_level_info.h"
#include <iostream>
sfml_window::ShortLevelInfo::ShortLevelInfo(const std::string &level_directory,
                                            unsigned int text_size,
                                            sf::Color color)
    : path_(level_directory) {

  std::string full_path = level_directory;

  std::reverse(full_path.begin(), full_path.end());

  int i = 0;
  while (full_path[i] != '/')
    i++;

  std::string level_name = full_path.substr(0, i);
  std::reverse(level_name.begin(), level_name.end());

  std::string author_name = "none";

  std::ifstream my_file;
  my_file.open(path_ + '/' + level_name);

  if (!my_file.is_open()) {
    throw "file_error";
  }
  int level_width, level_height;

  my_file >> level_name;
  my_file >> level_width;
  my_file >> level_height;
  my_file >> level_won_;
  my_file.close();

  level_ = TextButton({0, 0}, level_name + " by " + author_name, color, false,
                      text_size);
  if (level_won_)
    trophy_ =
        ImageButton(Rect({600, 0}, 32, 32),
                    "../sfml_window/assets/level_picker/trophy.png", GOLD);
  else
    trophy_ =
        ImageButton(Rect({600, 0}, 32, 32),
                    "../sfml_window/assets/level_picker/trophy.png", GRAY);
}

sfml_window::ShortLevelInfo::ShortLevelInfo() : path_("none") {

  level_ = TextButton({0, 0}, "None", RED, false, 24);

  trophy_ = ImageButton(Rect({600, 0}, 32, 32),
                        "../sfml_window/assets/level_picker/trophy.png", GRAY);
}

void sfml_window::ShortLevelInfo::DrawToWindow(sf::RenderWindow &window,
                                               const Coord &position) {
  level_.SetPosition(position);

  //  std::cout << level_.GetButtonWidth() << " <width\n";
  trophy_.SetPosition({600, position.y});

  level_.DrawToWindow(window);
  trophy_.DrawToWindow(window);
}
sfml_window::ShortLevelInfo::ShortLevelInfo(
    const sfml_window::ShortLevelInfo &other) {
  level_ = other.level_;
  path_ = other.path_;
}

bool sfml_window::ShortLevelInfo::DetectHover(const Coord &mouse_position) {
  return level_.DetectHover(mouse_position);
}

bool sfml_window::ShortLevelInfo::DetectInteraction(const Coord &press_point,
                                                    sf::Event &event) {
  return level_.DetectInteraction(press_point, event);
}

std::string sfml_window::ShortLevelInfo::GetPath() { return path_; }

sfml_window::ShortLevelInfo &
sfml_window::ShortLevelInfo::operator=(const ShortLevelInfo &other) {
  if (&other != this)
    return *this;
  level_ = other.level_;
  path_ = other.path_;
  return *this;
}
