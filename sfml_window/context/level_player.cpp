//
// Created by studio25 on 03.08.2021.
//

#include "level_player.h"


sfml_window::LevelPlayer::LevelPlayer(unsigned int window_width,
                                      unsigned int window_height,
                                      LevelInfo &level_info) {}


void sfml_window::LevelPlayer::DrawToWindow(sf::RenderWindow &window) {

}

void sfml_window::LevelPlayer::LoadButtons() {
  std::string directory = "../sfml_window/assets/level_player/";
  buttons_[(unsigned)LevelPlayerButton::EXIT] =
      new ImageButton(Rect(Coord(window_width_ - 36, 4), 32, 32),
                      directory + "cancel-button.png",
                      color_palette_[(unsigned)GuiColor::DANGER_COLOR]);

  buttons_[(unsigned)LevelPlayerButton::RUN_SIMULATION] =
      new ImageButton(Rect(Coord(window_width_ - 74, 4), 32, 32),
          directory + "run-button.png",
           color_palette_[(unsigned)GuiColor::INFORMATIVE_COLOR]);
}
