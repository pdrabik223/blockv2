//
// Created by studio25 on 14.08.2021.
//

#include "short_level_info.h"

sfml_window::ShortLevelInfo::ShortLevelInfo(const std::string &level_directory,
                                            unsigned int text_size,
                                            sf::Color color) {

  std::string message;
  std::string level_name;
  std::string author_name;

  std::ifstream my_file;
  my_file.open(level_directory);

  if (!my_file.is_open()) {
    throw "file_error";
  }

  my_file >> level_name;
  // for now level name is boubled

  message = level_name + " by " + level_name;


  level_ = TextButton({0, 0}, message,
                      color, false, text_size);
}

sfml_window::ShortLevelInfo::ShortLevelInfo() {
  level_ = TextButton({0, 0}, "None",
                     sf::Color::Red, false, 24);
}
void sfml_window::ShortLevelInfo::DrawToWindow(sf::RenderWindow &window,
                                               Coord position) {
  level_.SetPosition(position);
  level_.DrawToWindow(window);
}
sfml_window::ShortLevelInfo::ShortLevelInfo(const sfml_window::ShortLevelInfo& other) {
  level_ = other.level_;
}
bool sfml_window::ShortLevelInfo::DetectHover(const Coord &mouse_position) {
return level_.DetectHover(mouse_position);
}
