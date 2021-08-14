//
// Created by studio25 on 14.08.2021.
//

#include "short_level_info.h"


sfml_window::ShortLevelInfo::ShortLevelInfo(const Coord &position,
                                            std::string level_path,
                                            unsigned int text_size,
                                            sf::Color color) {
  std::string level_name;
  std::string author_name;

  std::ifstream my_file;
  my_file.open(level_path);

  if (!my_file.is_open()) {
    throw "file_error";
  }

  my_file >> level_name;
  level = TextButton(position, level_name, color, false, text_size);
}