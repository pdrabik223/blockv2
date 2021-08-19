//
// Created by studio25 on 19.08.2021.
//

#include "creator_input_panel.h"
void sfml_window::CreatorInputPanel::DrawToWindow(sf::RenderWindow &window) {
  window.draw(background_sprite_);

  for (const auto &button : buttons_)
    button->DrawToWindow(window);
}
sfml_window::ContextEvent
sfml_window::CreatorInputPanel::HandleEvent(sf::Event &event,
                                            const sf::RenderWindow &window) {
  return ContextEvent::NONE;
}
sfml_window::CreatorInputPanel *sfml_window::CreatorInputPanel::Clone() {
  return new CreatorInputPanel(*this);
}
Board sfml_window::CreatorInputPanel::GetLevel() { return Board(target_); }

LevelInfo sfml_window::CreatorInputPanel::GetLevelInfo() { return target_; }
std::string sfml_window::CreatorInputPanel::GetLevelDirectory() {
  return std::string("../levels/" + target_.GetName());
}
sfml_window::CreatorInputPanel::~CreatorInputPanel() {
  for (const auto &button : buttons_)
    delete button;
}
