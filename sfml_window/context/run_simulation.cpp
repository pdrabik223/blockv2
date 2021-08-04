//
// Created by studio25 on 03.08.2021.
//

#include "run_simulation.h"

sfml_window::RunSimulation::~RunSimulation() {
  for (auto &button : buttons_) {
    delete button;
  }
}
sfml_window::RunSimulation::RunSimulation(unsigned int window_width,
                                          unsigned int window_height,
                                          LevelInfo &level_info)
    : local_board_(level_info), window_width_(window_width),
      window_height_(window_height) {
  LoadColors();
  LoadButtons();
  LoadBackground(level_info.GetName());
  GenGrid();
}
void sfml_window::RunSimulation::DrawToWindow(sf::RenderWindow &window) {
  //window.clear(color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR]);
  window.draw(background_sprite_);
  if (display_grid_)
    DrawGrid(window);

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

  std::string directory = "../sfml_window/assets/";

  buttons_[(unsigned)RunSimulationButton::EXIT] = new ImageButton(
      Rect({window_width_ - 36, 4}, 32, 32), directory + "cancel-button.png",
      color_palette_[(unsigned)GuiColor::DANGER_COLOR]);
  buttons_[(unsigned)RunSimulationButton::STOP_SIMULATION] = new ImageButton(
      Rect({window_width_ - 74, 4}, 32, 32), directory + "pause-button.png",
      color_palette_[(unsigned)GuiColor::WARNING_COLOR]);
  buttons_[(unsigned)RunSimulationButton::END_SIMULATION] = new ImageButton(
      Rect({window_width_ - 112, 4}, 32, 32), directory + "next.png",
      color_palette_[(unsigned)GuiColor::DANGER_COLOR]);
}

/// draws white line between two points width width 3px
/// \param p_1  first point
/// \param p_2  second point
/// \return the shape of the line
sf::RectangleShape DrawLine(const Coord &p_1, const Coord &p_2,
                            sf::RectangleShape &target) {
  // make sure that these are not the same point
  // and are at the same asix

  assert(p_1.x == p_2.x xor p_1.y == p_2.y);

  // example a)
  //  y-axis
  //  .
  // / \
  //  |  c ------------- .  / \
  //  |  |               |   |
  //  | p_1             p_2  height        p_1.y = p_2.y and  p_1.x < p_2.x
  //  |  |               |   |
  //  |  . ------------- .  \ /
  //  .----------------------->  x-axis
  //     <-----width----->

  // example b)
  //  y-axis
  //  .
  // / \
  //  |  c --p_1-- . / \
  //  |  |         |  |
  //  |  |         | height         p_1.x = p_2.x   and  p_1.y > p_2.y
  //  |  |         |  |
  //  |  . --p_2-- . \ /
  //  .----------------------->  x-axis
  //     <-width--->

  // return {c.x,c.y,width,height}

  // example a)

  Coord c;
  if (p_1.y == p_2.y) {
    c = p_1.x > p_2.x ? p_1 : p_2;

    target.setPosition(c.x, c.y + 1);
    target.setSize({abs((float)(p_2.x - p_1.x)), 3});

  } else if (p_1.x == p_2.x) { // example b
    c = p_1.y > p_2.y ? p_1 : p_2;

    target.setPosition(c.x - 1, c.y);
    target.setSize({3, abs((float)(p_1.y - p_2.y))});
  }
  target.setFillColor(sf::Color::White);
  target.setOutlineColor(sf::Color::White);
  // solution_rectangle.setOutlineThickness(1);
  return target;
}
void sfml_window::RunSimulation::DrawGrid(sf::RenderWindow &window) {

  for (const auto &box : grid_)
    window.draw(box);
}
void sfml_window::RunSimulation::GenGrid() {

  // all cells are squares so the width = height
  // between all cells and surrounding them is 3px wide border
  double vertical_cell_size =
      ((window_width_ - 3) - 3 * local_board_.GetWidth()) /
      (double)(local_board_.GetWidth());
  //right border       /\        left border on every cell    /\

  double horizontal_cell_size =
      ((window_height_ - 3) - 3 * local_board_.GetHeight()) /
      (double)(local_board_.GetHeight());
  //right border       /\        left border on every cell    /\


  // the actual cell size must be smaller of the two above
  cell_size_ = vertical_cell_size < horizontal_cell_size
                   ? (unsigned)vertical_cell_size
                   : (unsigned)horizontal_cell_size;

  unsigned pixel_shift = cell_size_ + 3;
  // generate grid
  for (int y = 0; y < local_board_.GetHeight(); ++y)
    for (int x = 0; x < local_board_.GetWidth(); ++x) {
      grid_.push_back(sf::RectangleShape());
      grid_.back().setPosition(3 + x * pixel_shift, 3 + y * pixel_shift);
      grid_.back().setSize({(float)cell_size_, (float)cell_size_});
      grid_.back().setFillColor(sf::Color::Transparent);
      grid_.back().setOutlineColor(sf::Color::White);
      grid_.back().setOutlineThickness(1);
    }

  // center grid
  unsigned right_shift =
      (window_width_ - (3 + local_board_.GetWidth() * pixel_shift)) / 2;
  unsigned down_shift =
      (window_height_ - (3 + local_board_.GetHeight() * pixel_shift)) / 2;

  for (auto &square : grid_) {
    square.move(right_shift, down_shift);
  }
}
void sfml_window::RunSimulation::LoadBackground(const std::string& level_name) {
  if (!background_texture_.loadFromFile("../levels/" + level_name + "/background.png")){
    assert(false);
  }
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale( (float)window_width_/(float)background_texture_.getSize().x,
                               (float)window_height_/(float)background_texture_.getSize().y);
}
