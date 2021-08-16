//
// Created by studio25 on 17.08.2021.
//

#include "toggle_sprite_button.h"

#include <utility>
sfml_window::ToggleSpriteButton::ToggleSpriteButton(
    const Rect &structure, std::pair<sf::Texture, sf::Sprite> sprite):structure_(structure),sprite_(std::move(sprite)) {

}
void sfml_window::ToggleSpriteButton::TurnOn() {state_ = true;}
void sfml_window::ToggleSpriteButton::TurnOff() {state_ = false;}
