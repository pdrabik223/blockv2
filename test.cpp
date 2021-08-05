//
// Created by studio25 on 25.07.2021.
//

#include "bot.h"
#include "level_info.h"
#include "sfml_window/window.h"
int main() {

  LevelInfo game(10,5);
  game.AddBot({3, 4},BotType::GOAL);
 // game.AddBot({4, 4},BotType::ENGINE,Direction::RIGHT);
  game.SaveLevel();
  sfml_window::Gui sin(game);


  return 0;
}