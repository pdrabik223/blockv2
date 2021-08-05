//
// Created by studio25 on 25.07.2021.
//

#include "bot.h"
#include "level_info.h"
#include "sfml_window/window.h"
void FillWithBots(LevelInfo &target_level, double fill_level);
int main() {
  srand(time(NULL));
  LevelInfo game(20, 10);

  FillWithBots(game, 0.5);
  //  game.AddBot({0, 0}, BotType::GOAL);
  // game.AddBot({4, 4},BotType::ENGINE,Direction::RIGHT);
  game.SaveLevel();
  sfml_window::Gui sin(game);

  return 0;
}

void FillWithBots(LevelInfo &target_level, double fill_level = 0.3) {
  for (unsigned y = 0; y < target_level.GetHeight(); y++)
    for (unsigned x = 0; x < target_level.GetWidth(); x++)
      if (rand() > fill_level)
        switch (rand() % 8) {
        case 0:
          target_level.AddBot({x, y}, BotType::BASIC);
          break;
        case 1:
          target_level.AddBot({x, y}, BotType::BEDROCK);
          break;
        case 2:
          target_level.AddBot({x, y}, BotType::TURN,
                              (TurnDirection)(rand() % 2));
          break;
        case 3:
          target_level.AddBot({x, y}, BotType::GOAL);
          break;
        case 4:
          target_level.AddBot({x, y}, BotType::ENEMY);
          break;
        case 5:
          target_level.AddBot({x, y}, BotType::ENGINE, (Direction)(rand() % 4));
          break;
        case 6:
          target_level.AddBot({x, y}, BotType::FACTORY,
                              (Direction)(rand() % 4));
          break;
        case 7:
          target_level.AddBot({x, y}, BotType::TP, rand());
          break;
        }
}