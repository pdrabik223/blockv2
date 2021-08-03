//
// Created by studio25 on 25.07.2021.
//

#include "bot.h"
#include "level_info.h"
#include "sfml_window/window.h"
int main() {

  LevelInfo game(10,5);
  game.AddBot({3, 4},BotType::GOAL);
  game.SaveLevel();
  sfml_window::Gui sin;


  return 0;
}