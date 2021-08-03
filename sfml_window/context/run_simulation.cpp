//
// Created by studio25 on 03.08.2021.
//

#include "run_simulation.h"
#include <image_button.h>

sfml_window::RunSimulation::~RunSimulation() {
  for (auto &button : buttons_) {
    delete button;
  }
}
sfml_window::RunSimulation::RunSimulation(unsigned int window_width,
                                          unsigned int window_height,
                                          LevelInfo &level_info)
    : local_board_(level_info), window_width_(window_width),
      window_height_(window_height) {}
void sfml_window::RunSimulation::DrawToWindow(sf::RenderWindow &window) {
  window.clear(color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR]);

  for (const auto &button : buttons_)
    button->DrawToWindow(window);
}
sfml_window::ContextEvent
sfml_window::RunSimulation::HandleEvent(sf::Event &event,
                                        const sf::RenderWindow &window) {

  int mouse_x = sf::Mouse::getPosition(window).x;
  int mouse_y = sf::Mouse::getPosition(window).y;

  mouse_x = mouse_x < 0 ? 0 : mouse_x;
  mouse_y = mouse_y < 0 ? 0 : mouse_y;

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_ - 1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_ - 1;

  for (unsigned id = 0; id < buttons_.size(); id++)

    if (buttons_[id]->DetectInteraction({(unsigned)mouse_x, (unsigned)mouse_y},
                                        event))

      switch ((RunSimulationButton)id) {

      case RunSimulationButton::EXIT:
        return ContextEvent::EXIT;
      case RunSimulationButton::STOP_SIMULATION:
        break;
      case RunSimulationButton::END_SIMULATION:
        break;
      case RunSimulationButton::SIZE:
        break;
      }
}
void sfml_window::RunSimulation::LoadColors() {
  color_palette_[(unsigned)GuiColor::MENU_PRIMARY_COLOR] = sf::Color(0x0035d6);
  color_palette_[(unsigned)GuiColor::MENU_SECONDARY_COLOR] =
      sf::Color(0xa000d6);
  color_palette_[(unsigned)GuiColor::MENU_TERTIARY_COLOR] = sf::Color(0xd6a000);
  color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR] =
      sf::Color(27, 27, 27);
  color_palette_[(unsigned)GuiColor::DANGER_COLOR] = sf::Color(255, 0, 0);
  color_palette_[(unsigned)GuiColor::WARNING_COLOR] = sf::Color(255, 255, 0);
  color_palette_[(unsigned)GuiColor::INFORMATIVE_COLOR] = sf::Color(0, 0, 255);
  color_palette_[(unsigned)GuiColor::SAFE_COLOR] = sf::Color(0, 255, 0);
}
void sfml_window::RunSimulation::LoadButtons() {

  buttons_[(unsigned)RunSimulationButton::EXIT] =
      new ImageButton(Rect({20, 20}, 64, 64), "no_path_yet");
  buttons_[(unsigned)RunSimulationButton::STOP_SIMULATION] =
      new ImageButton(Rect({120, 120}, 64, 64), "no_path_yet");
  buttons_[(unsigned)RunSimulationButton::END_SIMULATION] =
      new ImageButton(Rect({220, 220}, 64, 64), "no_path_yet");
}
