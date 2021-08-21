//
// Created by studio25 on 03.08.2021.
//

#include "level_creator.h"

sfml_window::LevelCreator::LevelCreator(unsigned int window_width,
                                        unsigned int window_height)
    : window_width_(window_width), window_height_(window_height),
      level_(20, 10) {

  GenGrid();
  LoadAssets();
  LoadButtons();
  //  level_ = Board(temp_info);
}


sfml_window::LevelCreator::LevelCreator(unsigned int window_width,
                                        unsigned int window_height,
                                        const LevelInfo &level)
                                        : window_width_(window_width), window_height_(window_height),
                                        level_(level) {
  GenGrid();
  LoadAssets();
  LoadButtons();
}

sfml_window::LevelCreator::LevelCreator(const sfml_window::LevelCreator &other)
: level_(other.level_) {
  window_width_ = other.window_width_;
  window_height_ = other.window_height_;
  level_directory_ = other.level_directory_;

  GenGrid();
  LoadAssets();
  LoadButtons();

}

sfml_window::LevelCreator &sfml_window::LevelCreator::operator=(const LevelCreator &other) {
  if(&other == this) return *this;
  level_ = other.level_;
  window_width_ = other.window_width_;
  window_height_ = other.window_height_;
  level_directory_ = other.level_directory_;

  GenGrid();
  LoadAssets();
  LoadButtons();
  return *this;
}

void sfml_window::LevelCreator::DrawToWindow(sf::RenderWindow &window) {

  window.draw(background_sprite_);
  window.draw(button_background_);
  //  if (display_grid_)
  DrawGrid(window);

  DrawCells(window);

  ClearBotButtonHighlight();
  for (const auto &button : buttons_)
    button->DrawToWindow(window);
}

void sfml_window::LevelCreator::LoadButtons() {
  std::string directory = "../sfml_window/assets/level_creator/";
  buttons_[(unsigned)LevelCreatorButton::EXIT] =
      new ImageButton(Rect(Coord(window_width_ - 36, 4), 32, 32),
                      directory + "back.png", YELLOW);

  buttons_[(unsigned)LevelCreatorButton::RUN_SIMULATION] =
      new ImageButton(Rect(Coord(window_width_ - 74, 4), 32, 32),
                      directory + "run-button.png", BLUE);

  buttons_[(unsigned)LevelCreatorButton::INPUT_PANEL] =
      new ImageButton(Rect(Coord(window_width_  - 110, 4 ) , 32, 32),
                      directory + "information-button.png",BLUE);

  buttons_[(unsigned)LevelCreatorButton::SAVE_LEVEL] =
      new ImageButton(Rect(Coord(window_width_  - 146, 4 ) , 32, 32),
                      directory + "floppy-disk.png", BLUE);



  buttons_[(unsigned)LevelCreatorButton::CREATE_BORDER] =
      new ImageButton(Rect(Coord(window_width_ / 2 + 114 + 36 + 36, 4), 32, 32),
                      directory + "add-border.png", BLUE);




  buttons_[(unsigned)LevelCreatorButton::B_TP] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 178, 4), 32, 32), Texture(Assets::TP));

  buttons_[(unsigned)LevelCreatorButton::B_GOAL] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 142, 4), 32, 32), Texture(Assets::GOAL));

  buttons_[(unsigned)LevelCreatorButton::B_BASIC] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 106, 4), 32, 32), Texture(Assets::BASIC));

  buttons_[(unsigned)LevelCreatorButton::B_BEDROCK] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 70, 4), 32, 32), Texture(Assets::BEDROCK));

  buttons_[(unsigned)LevelCreatorButton::B_ENEMY] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 34, 4), 32, 32), Texture(Assets::ENEMY));

  buttons_[(unsigned)LevelCreatorButton::B_ENGINE] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 + 2, 4), 32, 32), Texture(Assets::ENGINE_U));

  buttons_[(unsigned)LevelCreatorButton::B_FACTORY] =
      new ToggleSpriteButton(Rect(Coord(window_width_ / 2 + 36, 4), 32, 32),
                             Texture(Assets::FACTORY_U));

  buttons_[(unsigned)LevelCreatorButton::B_TURN] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 + 72, 4), 32, 32), Texture(Assets::TURN_C));

  sf::Texture empty;
  if (!empty.loadFromFile(directory + "empty_cell.png")) {
    assert(false);
  }

  buttons_[(unsigned)LevelCreatorButton::B_EMPTY] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 + 108, 4), 32, 32), empty);
}

void sfml_window::LevelCreator::LoadBackground(
    const std::string &background_path) {

  if (!background_texture_.loadFromFile(background_path))
    throw "error";
  background_texture_.setSmooth(true);
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale(
      (float)window_width_ / (float)background_texture_.getSize().x,
      (float)window_height_ / (float)background_texture_.getSize().y);
}

void sfml_window::LevelCreator::DrawGrid(sf::RenderWindow &window) {

  for (const auto &box : grid_)
    window.draw(box);
}

void sfml_window::LevelCreator::GenGrid() {
  // to accommodate top rectangle
  unsigned real_window_height = window_height_ - 40;
  button_background_.setPosition(0, 0);
  button_background_.setSize({(float)window_width_, 40});
  button_background_.setFillColor({0, 0, 0, 80});

  // all cells are squares so the width = height
  // between all cells and surrounding them is 3px wide border
  double horizontal_cell_size = ((window_width_ - 3) - 3 * level_.GetWidth()) /
                                (double)(level_.GetWidth());

  double vertical_cell_size =
      ((real_window_height - 3) - 3 * level_.GetHeight()) /
      (double)(level_.GetHeight());

  // the actual cell size must be smaller of the two above
  cell_size_ = horizontal_cell_size < vertical_cell_size
                   ? (unsigned)horizontal_cell_size
                   : (unsigned)vertical_cell_size;

  unsigned pixel_shift = cell_size_ + 3;
  // generate grid
  for (int y = 0; y < level_.GetHeight(); ++y)
    for (int x = 0; x < level_.GetWidth(); ++x) {
      grid_.emplace_back();
      grid_.back().setPosition(3 + x * pixel_shift, 40 + 3 + y * pixel_shift);
      grid_.back().setSize({(float)cell_size_, (float)cell_size_});
      grid_.back().setFillColor(sf::Color::Transparent);
      grid_.back().setOutlineColor(RED);
      grid_.back().setOutlineThickness(1.5);
    }

  // center grid
  unsigned right_shift =
      (window_width_ - (3 + level_.GetWidth() * pixel_shift)) / 2;

  unsigned down_shift =
      (real_window_height - (3 + level_.GetHeight() * pixel_shift)) / 2;

  for (auto &square : grid_) {
    square.move(right_shift, down_shift);
  }

  for (int i = 0; i < grid_.size(); i++)
    if (!level_.IsLocked(i)) {
      grid_[i].setOutlineColor(GREEN);
      grid_[i].setOutlineThickness(2);
    }
}

void sfml_window::LevelCreator::DrawCells(sf::RenderWindow &window) {
  // todo 2. finish load cells function

  assert(grid_.size() == level_.GetHeight() * level_.GetWidth());

  for (unsigned p = 0; p < grid_.size(); ++p)
    switch (level_.GetCell(p)->GetType()) {
    case BotType::BASIC:
      DrawCell(window, Assets::BASIC, p);
      break;
    case BotType::BEDROCK:
      DrawCell(window, Assets::BEDROCK, p);
      break;
    case BotType::GOAL:
      DrawCell(window, Assets::GOAL, p);
      break;
    case BotType::ENEMY:
      DrawCell(window, Assets::ENEMY, p);
      break;
    case BotType::TP:
      DrawCell(window, Assets::TP, p);
      break;
    case BotType::TURN:
      if (((Turn *)level_.GetCell(p)->Clone())->GetDirection() ==
          TurnDirection::CLOCKWISE)
        DrawCell(window, Assets::TURN_C, p);

      else if (((Turn *)level_.GetCell(p)->Clone())->GetDirection() ==
               TurnDirection::COUNTER_CLOCKWISE)
        DrawCell(window, Assets::TURN_CC, p);
      else
        throw "ERROR";
      break;
    case BotType::ENGINE:
      switch (((Engine *)level_.GetCell(p)->Clone())->GetDirection()) {
      case Direction::UP:
        DrawCell(window, Assets::ENGINE_U, p);
        break;
      case Direction::DOWN:
        DrawCell(window, Assets::ENGINE_D, p);
        break;
      case Direction::LEFT:
        DrawCell(window, Assets::ENGINE_L, p);
        break;
      case Direction::RIGHT:
        DrawCell(window, Assets::ENGINE_R, p);
        break;
      }
      break;
    case BotType::FACTORY:
      switch (((Factory *)level_.GetCell(p)->Clone())->GetDirection()) {
      case Direction::UP:
        DrawCell(window, Assets::FACTORY_U, p);
        break;
      case Direction::DOWN:
        DrawCell(window, Assets::FACTORY_D, p);
        break;
      case Direction::LEFT:
        DrawCell(window, Assets::FACTORY_L, p);
        break;
      case Direction::RIGHT:
        DrawCell(window, Assets::FACTORY_R, p);
        break;
      }
      break;
    case BotType::EMPTY:
      break;
    default:

      throw "error";
    }
}

void sfml_window::LevelCreator::DrawCell(sf::RenderWindow &window,
                                         sfml_window::Assets id,
                                         unsigned int position) {
  Sprite(id).setPosition(grid_[position].getPosition().x + cell_size_ / 2,
                         grid_[position].getPosition().y + cell_size_ / 2);

  window.draw(Sprite(id));
}
sf::Texture &sfml_window::LevelCreator::Texture(sfml_window::Assets cell) {
  return cells_[(unsigned)cell].first;
}

sf::Sprite &sfml_window::LevelCreator::Sprite(sfml_window::Assets cell) {
  return cells_[(unsigned)cell].second;
}

void sfml_window::LevelCreator::LoadAssets() {

  bool exists[(unsigned)Assets::SIZE];
  static std::string file_names[(unsigned)Assets::SIZE];
  {
    file_names[(unsigned)Assets::BASIC] = "basic.png";
    file_names[(unsigned)Assets::BEDROCK] = "bedrock.png";
    file_names[(unsigned)Assets::TURN_C] = "turn_clockwise.png";
    file_names[(unsigned)Assets::TURN_CC] = "turn_counterclockwise.png";
    file_names[(unsigned)Assets::GOAL] = "goal.png";
    file_names[(unsigned)Assets::ENEMY] = "enemy.png";
    file_names[(unsigned)Assets::ENGINE_U] = "engine_up.png";
    file_names[(unsigned)Assets::ENGINE_D] = "engine_down.png";
    file_names[(unsigned)Assets::ENGINE_L] = "engine_left.png";
    file_names[(unsigned)Assets::ENGINE_R] = "engine_right.png";
    file_names[(unsigned)Assets::FACTORY_U] = "factory_up.png";
    file_names[(unsigned)Assets::FACTORY_D] = "factory_down.png";
    file_names[(unsigned)Assets::FACTORY_L] = "factory_left.png";
    file_names[(unsigned)Assets::FACTORY_R] = "factory_right.png";
    file_names[(unsigned)Assets::TP] = "tp.png";
    file_names[(unsigned)Assets::BACKGROUND] = "background.png";
  } // set filenames

  const std::string kDefaultDir = "../levels/default/";

  LoadBackground(kDefaultDir + file_names[(unsigned)Assets::BACKGROUND]);

  // load custom assets (if one exist)
  // all loaded this way assets are simple meaning they have defined counterpart
  // in default directory
  for (int i = 0; i < (unsigned)Assets::TURN_C; i++) {
    std::string full_path = kDefaultDir + file_names[i];
    LoadCell((Assets)i, full_path);
  }

  LoadCell(Assets::TURN_C, kDefaultDir + file_names[(int)Assets::TURN_C]);
  CopyCell(Assets::TURN_CC, Assets::TURN_C, FlipDirection::VERTICAL);

  LoadCell(Assets::ENGINE_U, kDefaultDir + file_names[(int)Assets::ENGINE_U]);

  CopyCell(Assets::ENGINE_R, Assets::ENGINE_U, FlipDirection::BOTH);

  CopyCell(Assets::ENGINE_D, Assets::ENGINE_U, FlipDirection::VERTICAL);

  CopyCell(Assets::ENGINE_L, Assets::ENGINE_D, FlipDirection::HORIZONTAL);

  LoadCell(Assets::FACTORY_U, kDefaultDir + file_names[(int)Assets::FACTORY_U]);
  CopyCell(Assets::FACTORY_R, Assets::FACTORY_U, FlipDirection::BOTH);

  CopyCell(Assets::FACTORY_D, Assets::FACTORY_U, FlipDirection::VERTICAL);

  CopyCell(Assets::FACTORY_L, Assets::FACTORY_D, FlipDirection::HORIZONTAL);
}

void sfml_window::LevelCreator::LoadCell(sfml_window::Assets cell,
                                         const std::string &asset_path) {

  if (!Texture(cell).loadFromFile(asset_path))
    throw "error";

  Texture(cell).setSmooth(true);

  Sprite(cell).setTexture(Texture(cell));

  Sprite(cell).setScale((float)cell_size_ / (float)Texture(cell).getSize().x,
                        (float)cell_size_ / (float)Texture(cell).getSize().y);

  Sprite(cell).setOrigin(Texture(cell).getSize().x / 2,
                         Texture(cell).getSize().y / 2);
}

void sfml_window::LevelCreator::CopyCell(sfml_window::Assets copy,
                                         sfml_window::Assets original,
                                         FlipDirection flip) {
  Texture(copy).create(Texture(original).getSize().x,
                       Texture(original).getSize().y);
  Texture(copy).update(Texture(original), 0, 0);
  Texture(copy).setSmooth(true);

  Sprite(copy).setTexture(Texture(copy));

  Sprite(copy).setOrigin(Texture(copy).getSize().x / 2,
                         Texture(copy).getSize().y / 2);

  if (flip == FlipDirection::HORIZONTAL) {
    Sprite(copy).rotate(-90);
  } else if (flip == FlipDirection::VERTICAL) {
    Sprite(copy).rotate(180);
  } else {
    Sprite(copy).rotate(-90);
    Sprite(copy).rotate(180);
  }

  Sprite(copy).setScale((float)cell_size_ / (float)Texture(copy).getSize().x,
                        (float)cell_size_ / (float)Texture(copy).getSize().y);
}

sfml_window::ContextEvent
sfml_window::LevelCreator::HandleEvent(sf::Event &event,
                                       const sf::RenderWindow &window) {
  int mouse_x = sf::Mouse::getPosition(window).x;
  int mouse_y = sf::Mouse::getPosition(window).y;

  mouse_x = mouse_x < 0 ? 0 : mouse_x;
  mouse_y = mouse_y < 0 ? 0 : mouse_y;

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_ - 1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_ - 1;

  bool change = false;

  if (event.type == sf::Event::MouseButtonReleased) {
    if (AddBotToGame({mouse_x, mouse_y}, event))
      return ContextEvent::UPDATE_DISPLAY;

    if (RotateBot({mouse_x, mouse_y}, event))
      return ContextEvent::UPDATE_DISPLAY;

    if (FlipSquareLock({mouse_x, mouse_y}, event))
      return ContextEvent::UPDATE_DISPLAY;

    for (unsigned id = 0; id < buttons_.size(); id++)
      if (buttons_[id]->DetectInteraction({mouse_x, mouse_y}, event))
        switch ((LevelCreatorButton)id) {
        case LevelCreatorButton::EXIT:
          return ContextEvent::SWITCH_TO_MAIN_MENU;

        case LevelCreatorButton::RUN_SIMULATION:
          return ContextEvent::RUN_SIMULATION;

        case LevelCreatorButton::CREATE_BORDER: {
          DrawBorder();
          return ContextEvent::UPDATE_DISPLAY;
        }

        case LevelCreatorButton::INPUT_PANEL:
          return ContextEvent::SWITCH_TO_CREATOR_INPUT_PANEL;

          case LevelCreatorButton::SAVE_LEVEL:
            level_.SaveLevel();



        case LevelCreatorButton::B_BASIC: {
          brush_ = BotType::BASIC;
          change = true;
        } break;
        case LevelCreatorButton::B_BEDROCK: {
          brush_ = BotType::BEDROCK;
          change = true;

        } break;
        case LevelCreatorButton::B_ENEMY: {
          brush_ = BotType::ENEMY;
          change = true;

        } break;
        case LevelCreatorButton::B_ENGINE: {
          brush_ = BotType::ENGINE;
          change = true;

        } break;
        case LevelCreatorButton::B_FACTORY: {
          brush_ = BotType::FACTORY;
          change = true;

        } break;
        case LevelCreatorButton::B_TURN: {
          brush_ = BotType::TURN;
          change = true;

        } break;
        case LevelCreatorButton::B_EMPTY: {
          brush_ = BotType::EMPTY;
          change = true;
        } break;
        case LevelCreatorButton::B_TP: {
          brush_ = BotType::TP;
          change = true;
        } break;
        case LevelCreatorButton::B_GOAL: {
          brush_ = BotType::GOAL;
          change = true;
        } break;
        }
  }

  for (auto &button : buttons_)
    if (button->DetectHover({mouse_x, mouse_y}))
      change = true;

  if (change)
    return ContextEvent::UPDATE_DISPLAY;

  return ContextEvent::NONE;
}

unsigned sfml_window::LevelCreator::Align(double x) {
  return (unsigned)((x * window_width_) / 100.0);
}

void sfml_window::LevelCreator::ClearBotButtonHighlight() {

  for (int i = (int)LevelCreatorButton::B_EMPTY;
       i <= (int)LevelCreatorButton::B_BASIC; i++) {

    ((ToggleSpriteButton *)buttons_[i])->TurnOff();
  }
  switch (brush_) {
  case BotType::BASIC:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_BASIC])
        ->TurnOn();
    return;
  case BotType::BEDROCK:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_BEDROCK])
        ->TurnOn();
    return;
  case BotType::TURN:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_TURN])->TurnOn();
    return;
  case BotType::ENEMY:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_ENEMY])
        ->TurnOn();
    return;
  case BotType::ENGINE:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_ENGINE])
        ->TurnOn();
    return;
  case BotType::FACTORY:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_FACTORY])
        ->TurnOn();
    return;
  case BotType::EMPTY:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_EMPTY])
        ->TurnOn();
  case BotType::TP:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_TP])->TurnOn();
    return;
  case BotType::GOAL:
    ((ToggleSpriteButton *)buttons_[(int)LevelCreatorButton::B_GOAL])->TurnOn();
    return;
  }
}

bool sfml_window::LevelCreator::AddBotToGame(const Coord &mouse_position,
                                             const sf::Event &event) {
  if (event.type != sf::Event::MouseButtonReleased or
      event.mouseButton.button != sf::Mouse::Left)
    return false;

  int square_x;
  int square_y;

  for (int i = 0; i < grid_.size(); ++i) {

    if (mouse_position.x > grid_[i].getPosition().x and
        mouse_position.y > grid_[i].getPosition().y)
      if (mouse_position.x - grid_[i].getPosition().x < grid_[i].getSize().x and
          mouse_position.y - grid_[i].getPosition().y < grid_[i].getSize().y) {
        square_x = i % level_.GetWidth();
        square_y = i / level_.GetWidth();

        level_.AddCell(square_x, square_y, brush_);
        return true;
      }
  }
  return false;
}

bool sfml_window::LevelCreator::RotateBot(const Coord &mouse_position,
                                          const sf::Event &event) {
  if (event.type != sf::Event::MouseButtonReleased or
      event.mouseButton.button != sf::Mouse::Right)
    return false;

  int square_x;
  int square_y;

  for (int i = 0; i < grid_.size(); ++i) {
    if (mouse_position.x > grid_[i].getPosition().x and
        mouse_position.y > grid_[i].getPosition().y)
      if (mouse_position.x - grid_[i].getPosition().x < grid_[i].getSize().x and
          mouse_position.y - grid_[i].getPosition().y < grid_[i].getSize().y) {
        square_x = i % level_.GetWidth();
        square_y = i / level_.GetWidth();

        level_.RotateCell(square_x, square_y);
        return true;
      }
  }
  return false;
}

sfml_window::LevelCreator *sfml_window::LevelCreator::Clone() {
  return new LevelCreator(*this);
}

LevelInfo sfml_window::LevelCreator::GetLevelInfo() {
  return level_;
}

sfml_window::LevelCreator::~LevelCreator() {

  for (auto &b : buttons_)
    delete b;
}

Board sfml_window::LevelCreator::GetLevel() { return Board(level_); }

std::string sfml_window::LevelCreator::GetLevelDirectory() {
  return level_directory_;
}

bool sfml_window::LevelCreator::FlipSquareLock(const Coord &mouse_position,
                                               const sf::Event &event) {
  if (event.type != sf::Event::MouseButtonReleased or
      event.mouseButton.button != sf::Mouse::Middle)
    return false;
  std::cout << "press";
  //    if (event.type != sf::Event::KeyPressed or
  //        event.key.code != sf::Keyboard::L)

  int square_x;
  int square_y;

  for (int i = 0; i < grid_.size(); ++i) {
    if (mouse_position.x > grid_[i].getPosition().x and
        mouse_position.y > grid_[i].getPosition().y)
      if (mouse_position.x - grid_[i].getPosition().x < grid_[i].getSize().x and
          mouse_position.y - grid_[i].getPosition().y < grid_[i].getSize().y) {
        square_x = i % level_.GetWidth();
        square_y = i / level_.GetWidth();

        if (level_.IsLocked({(int)square_x, (int)square_y}))
          level_.UnLock({(int)square_x, (int)square_y});
        else
          level_.Lock({(int)square_x, (int)square_y});

        if (!level_.IsLocked({(int)square_x, (int)square_y})) {
          grid_[i].setOutlineColor({0, 200, 80});
        } else {
          grid_[i].setOutlineColor({250, 80, 0});
        }

        return true;
      }
  }
  return false;
}

void sfml_window::LevelCreator::DrawBorder() {


  for (unsigned y = 0; y < level_.GetHeight(); y++) {
      level_.AddBot(Coord(0, y), BotType::BEDROCK);

      level_.AddBot(Coord(level_.GetWidth() - 1, y),
                          BotType::BEDROCK);
    }

  for (unsigned x = 0; x < level_.GetWidth(); x++) {
      level_.AddBot(Coord(x, 0), BotType::BEDROCK);

      level_.AddBot(Coord(x, level_.GetHeight() - 1),
                          BotType::BEDROCK);
    }



}
