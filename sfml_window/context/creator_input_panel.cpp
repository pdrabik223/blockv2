//
// Created by studio25 on 19.08.2021.
//

#include "creator_input_panel.h"

sfml_window::CreatorInputPanel::CreatorInputPanel(unsigned int window_width,
                                                  unsigned int window_height,
                                                  const LevelInfo &target)
    : window_width_(window_width), window_height_(window_height),
      target_(target) {
  LoadButtons();
  LoadBackground();
}


void sfml_window::CreatorInputPanel::DrawToWindow(sf::RenderWindow &window) {
  window.draw(background_sprite_);

  for (const auto &button : buttons_)
    button->DrawToWindow(window);
}
sfml_window::ContextEvent
sfml_window::CreatorInputPanel::HandleEvent(sf::Event &event,
                                            const sf::RenderWindow &window) {
  int mouse_x = sf::Mouse::getPosition(window).x;
  int mouse_y = sf::Mouse::getPosition(window).y;

  mouse_x = mouse_x < 0 ? 0 : mouse_x;
  mouse_y = mouse_y < 0 ? 0 : mouse_y;

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_ - 1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_ - 1;

  bool change = false; // if true window should be re-loaded to display change
  // in appearance

  if (event.type == sf::Event::MouseButtonReleased) {

    for (unsigned id = 0; id < buttons_.size(); id++)

      if (buttons_[id]->DetectInteraction({mouse_x, mouse_y}, event))

        switch ((CreatorInputPanelButton)id) {
      case CreatorInputPanelButton::EXIT:
        return ContextEvent::SWITCH_TO_PREVIOUS;
      }
  } else {

    for (auto &button : buttons_)
      if (button->DetectHover({mouse_x, mouse_y}))
        change = true;
  }

  if (change)
    return ContextEvent::UPDATE_DISPLAY;

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
void sfml_window::CreatorInputPanel::LoadButtons() {
  std::string directory = "../sfml_window/assets/level_creator/";

  buttons_[(unsigned)CreatorInputPanelButton::EXIT] =
      new ImageButton(Rect(Coord(window_width_ - 36, 4), 32, 32),
                      directory + "cancel-button.png",
                      sf::Color::Red);

}
void sfml_window::CreatorInputPanel::LoadBackground() {
  if (!background_texture_.loadFromFile(
      "../sfml_window/assets/level_creator/background.png"))
    throw "error";

  background_texture_.setSmooth(true);
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale(
      (float)window_width_ / (float)background_texture_.getSize().x,
      (float)window_height_ / (float)background_texture_.getSize().y);
}
