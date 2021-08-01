//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_
#define BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_

#include "button.h"
#include "context.h"
#include "text_box.h"
#include <array>
namespace sfml_window {
/// white background
enum class MainMenuButton {
  EXIT,
  PLAY_LEVEL,
  CREATE_LEVEL,
  MULTIPLAYER,
  CREDITS,
  SIZE
};

class MainMenu : public Context {
public:
  MainMenu();
  void LoadButtons();
  virtual ~MainMenu();

private:
  std::array<Button *, (unsigned)MainMenuButton::SIZE> buttons_;
  TextBox game_name_ = {{0, 0},"Block v2"};
  TextBox author_name_ = {{100,100},"author: piotr233"};

};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_
