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
  LoadCells(level_info.GetName());
  GenGrid();
}
void sfml_window::RunSimulation::DrawToWindow(sf::RenderWindow &window) {
  // window.clear(color_palette_[(unsigned)GuiColor::MENU_BACKGROUND_COLOR]);
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
void sfml_window::RunSimulation::LoadBackground(const std::string &level_name) {
  if (!background_texture_.loadFromFile("../levels/" + level_name +
                                        "/background.png")) {
    assert(false);
  }
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale(
      (float)window_width_ / (float)background_texture_.getSize().x,
      (float)window_height_ / (float)background_texture_.getSize().y);
}
void sfml_window::RunSimulation::LoadCells(const std::string &level_name) {
  // loading images is hard
  // because user is dudu,
  // and I need to apologise for it
  //
  // ok nessery images:
  // basic, bedrock, goal, enemy
  //
  // turn has 2 versions
  // engine 4
  // factory 4
  // and tp infinite but it's hard to have infinite

  // ok, basic rules :
  // 1. the names of the files are strict,
  // 2. if directory has image for block use this one
  // if not use default one
  // 3.  only one of the variant blocks must be present, rest will be created by
  // flipping
  //  a) if the up is present down will be created first
  //   than the check will be run for left and right ones
  //  b) if the left and right are present that's it
  //   if only one is present the second will be created by vertical flip
  std::string dir = "../levels/" + level_name + "/";
  std::string default_dir = "../levels/default/";

  // easy ones
  LoadCell(CellSprite::BASIC, "basic.png");

  LoadCell(CellSprite::BEDROCK, "bedrock.png");

  LoadCell(CellSprite::GOAL, "goal.png");

  LoadCell(CellSprite::ENEMY, "enemy.png");

  LoadCell(CellSprite::TP, "tp.png");

  // now for tha hard ones
  bool turn_c =
      Texture(CellSprite::TURN_C).loadFromFile(dir + "turn_clockwise.png");
  bool turn_cc = Texture(CellSprite::TURN_CC)
                     .loadFromFile(default_dir + "turn_counterclockwise.png");

  if (turn_c and !turn_cc) {
    LoadCell(CellSprite::TURN_CC, CellSprite::TURN_C, 180);

  } else if (!turn_c and turn_cc) {

    LoadCell(CellSprite::TURN_C, CellSprite::TURN_CC, 180);

  } else if (!turn_c and !turn_cc) {
    if (Texture(CellSprite::TURN_CC)
            .loadFromFile(default_dir + "turn_counterclockwise.png")) {
      LoadCell(CellSprite::TURN_C, CellSprite::TURN_CC, 180);
    } else
      throw "error";
  }

  Texture(CellSprite::ENGINE_U).loadFromFile(default_dir + "engine_up.png");

  LoadCell(CellSprite::ENGINE_D, CellSprite::ENGINE_U, 180);
  LoadCell(CellSprite::ENGINE_R, CellSprite::ENGINE_U, 90);
  LoadCell(CellSprite::ENGINE_L, CellSprite::ENGINE_R, 180);

  Texture(CellSprite::FACTORY_R)
      .loadFromFile(default_dir + "factory_right.png");
  LoadCell(CellSprite::FACTORY_L, CellSprite::FACTORY_R, 180);

  LoadCell(CellSprite::FACTORY_U, CellSprite::FACTORY_L, 90);

  LoadCell(CellSprite::FACTORY_D, CellSprite::FACTORY_U, 180);

  //
  //  bool engine_u =
  //      Texture(CellSprite::ENGINE_U).loadFromFile(dir + "engine_up.png");
  //  bool engine_d =
  //      Texture(CellSprite::ENGINE_D).loadFromFile(dir + "engine_down.png");
  //  bool engine_l =
  //      Texture(CellSprite::ENGINE_L).loadFromFile(dir + "engine_left.png");
  //  bool engine_r =
  //      Texture(CellSprite::ENGINE_R).loadFromFile(dir + "engine_right.png");
  //
  //  if(engine_u and !engine_d){
  //    Sprite(CellSprite::ENGINE_U).setTexture(Texture(CellSprite::ENGINE_U));
  //    Texture(CellSprite::ENGINE_D).update(Texture(CellSprite::ENGINE_U));
  //
  //    Sprite(CellSprite::ENGINE_D).setTexture(Texture(CellSprite::ENGINE_D));
  //    Sprite(CellSprite::ENGINE_D).rotate(180);
  //  }else if(!engine_u and engine_d){
  //  }
}

sf::Texture &sfml_window::RunSimulation::Texture(sfml_window::CellSprite cell) {
  return cells_[(unsigned)cell].first;
}
sf::Sprite &sfml_window::RunSimulation::Sprite(sfml_window::CellSprite cell) {
  return cells_[(unsigned)cell].second;
}

void sfml_window::RunSimulation::LoadCell(CellSprite cell_to,
                                          CellSprite cell_from, double angle) {
  Sprite(cell_from).setTexture(Texture(cell_from));

  Texture(cell_to).update(Texture(cell_from));

  Sprite(cell_to).setTexture(Texture(cell_to));
  Sprite(cell_to).rotate(angle);
}
void sfml_window::RunSimulation::LoadCell(CellSprite cell,
                                          const std::string &level_name) {
  std::string dir = "../levels/" + level_name + "/";
  std::string default_dir = "../levels/default/";

  if (!Texture(cell).loadFromFile(dir + level_name))
    if (!Texture(cell).loadFromFile(default_dir + level_name))
      throw "error";
    else
      Sprite(cell).setTexture(Texture(cell));
}
void sfml_window::RunSimulation::DrawCells(sf::RenderWindow &window) {
  // todo 1. proper display (this function)

  // todo 2. finish load cells function

  // todo 3. test this shit

  // todo 4. better assets

  // todo 5. let ti move 
  for (unsigned y = 0; y < local_board_.GetHeight(); ++y)
    for (unsigned  x = 0; x < local_board_.GetWidth(); ++x)
      switch (local_board_.GetCell({x, y})->type_) {
      case BotType::BASIC:
        break;
      case BotType::BEDROCK:
        break;
      case BotType::TURN:
        break;
      case BotType::GOAL:
        break;
      case BotType::ENEMY:
        break;
      case BotType::ENGINE:
        break;
      case BotType::FACTORY:
        break;
      case BotType::TP:
        break;
      case BotType::EMPTY:
        break;
      default:
        throw "error";
      }
}
