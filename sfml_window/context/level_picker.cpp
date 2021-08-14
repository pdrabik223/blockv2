//
// Created by studio25 on 03.08.2021.
//

#include "level_picker.h"
#include <fstream>
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
sfml_window::LevelPicker::LevelPicker(unsigned int window_width,
                                      unsigned int window_height)
    : window_width_(window_width), window_height_(window_height) {}

void sfml_window::LevelPicker::DrawToWindow(sf::RenderWindow &window) {
  window.draw(background_sprite_);

  // for (const auto &level_info : levels_)
  // level_info->DrawToWindow(window);

  for (const auto &button : buttons_)
    button->DrawToWindow(window);
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

  return sfml_window::ContextEvent::NONE;
}
void sfml_window::LevelPicker::LoadLevelInfo() {}

sfml_window::LevelInfo::LevelInfo(Coord position, std::string level_path,
                                  unsigned int text_size, sf::Color color) {

  std::string level_name;
  std::string author_name;

  std::ifstream my_file;
  my_file.open(level_path);

  if (!my_file.is_open()) {
    throw "file_error";
  }

  my_file >> level_name;
  level = TextButton(position,level_name,color,false,text_size);

}

void ReadDirectory(const std::string &name, std::vector<std::string> &output) {
  std::string pattern(name);
  pattern.append("*.txt");
  WIN32_FIND_DATA data;
  HANDLE hFind;
  if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {

    do {
      output.emplace_back(data.cFileName);
    } while (FindNextFile(hFind, &data) != 0);
    FindClose(hFind);
  }
}
