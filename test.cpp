//
// Created by studio25 on 25.07.2021.
//

#include "bot.h"
#include "level_info.h"
#include "sfml_window/window.h"
void FillWithBots(LevelInfo &target_level, double fill_level);

void Border(LevelInfo &target_level);

int main() {
  srand(time(NULL));
  LevelInfo game(10, 3);

  //  game.AddBot({32%10, 32/10}, BotType::ENEMY);
  //  game.AddBot({0%10, 0/10}, BotType::ENEMY);
  //  game.AddBot({28%10, 28/10}, BotType::GOAL);
  //
//    FillWithBots(game, 0.3);

 game.AddBot({3, 1}, BotType::ENGINE,Direction::RIGHT);
 game.AddBot({4, 1}, BotType::BASIC);
 game.AddBot({5, 1}, BotType::BASIC);

  Border(game);



    game.SaveLevel();
    sfml_window::Gui sin(game);




  return 0;
}

void FillWithBots(LevelInfo &target_level, double fill_level = 0.3) {
  for (unsigned y = 0; y < target_level.GetHeight(); y++)
    for (unsigned x = 0; x < target_level.GetWidth(); x++)
      if (rand() % 100 < fill_level * 100)
        switch (rand() % 8) {
        case 0:
          target_level.AddBot(Coord(x, y), BotType::BASIC);
          break;
        case 1:
          target_level.AddBot(Coord(x, y), BotType::BEDROCK);
          break;
        case 2:
          target_level.AddBot(Coord(x, y), BotType::TURN,
                              (TurnDirection)(rand() % 2));
          break;
        case 3:
          target_level.AddBot(Coord(x, y), BotType::GOAL);
          break;
        case 4:
          target_level.AddBot(Coord(x, y), BotType::ENEMY);
          break;
        case 5:
          target_level.AddBot(Coord(x, y), BotType::ENGINE, (Direction)(rand() % 4));
          break;
        case 6:
          target_level.AddBot(Coord(x, y), BotType::FACTORY,
                              (Direction)(rand() % 4));
          break;
        case 7:
          target_level.AddBot(Coord(x, y), BotType::TP, rand());
          break;
        }
}

void Border(LevelInfo &target_level) {

  for (unsigned y = 0; y < target_level.GetHeight(); y++) {
    target_level.AddBot(Coord(0, y), BotType::BEDROCK);
    target_level.AddBot(Coord(target_level.GetWidth() - 1, y), BotType::BEDROCK);
  }

  for (unsigned x = 0; x < target_level.GetWidth(); x++) {
    target_level.AddBot(Coord(x, 0), BotType::BEDROCK);
    target_level.AddBot(Coord(x, target_level.GetHeight() - 1), BotType::BEDROCK);
  }
}