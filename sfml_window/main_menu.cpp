//
// Created by studio25 on 01.08.2021.
//

#include "main_menu.h"
sfml_window::MainMenu::MainMenu() {}
sfml_window::MainMenu::~MainMenu() {
  for(auto& button : buttons_ )
    delete button;
}
void sfml_window::MainMenu::LoadButtons() {}
