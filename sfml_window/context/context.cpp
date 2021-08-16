//
// Created by studio25 on 01.08.2021.
//

#include "context.h"
std::string sfml_window::LevelPath(const std::string &directory_path) {
  std::string full_path = directory_path;

  std::reverse(full_path.begin(), full_path.end());

  int i=0;
  while(full_path[i] != '/') i++;

  std::string level_name = full_path.substr(0,i);
  std::reverse(level_name.begin(), level_name.end());

  return directory_path + "/" + level_name;
}
