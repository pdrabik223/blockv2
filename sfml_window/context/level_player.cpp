//
// Created by studio25 on 03.08.2021.
//

#include "level_player.h"

sfml_window::LevelPlayer::LevelPlayer(unsigned int window_width,
                                      unsigned int window_height,
                                      const std::string &level_path)
    : window_width_(window_width), window_height_(window_height),
      level_directory_(level_path), level_(LevelInfo(LevelPath(level_path))) {

  GenGrid();
  LevelInfo temp_info(LevelPath(level_path));
  LoadAssets(temp_info.GetName());
  LoadButtons();
  //  level_ = Board(temp_info);
}

void sfml_window::LevelPlayer::DrawToWindow(sf::RenderWindow &window) {

  window.draw(background_sprite_);
  window.draw(button_background_);
  //  if (display_grid_)
  DrawGrid(window);

  DrawCells(window);

  ClearBotButtonHighlight();
  for (const auto &button : buttons_)
    button->DrawToWindow(window);
}

void sfml_window::LevelPlayer::LoadButtons() {
  std::string directory = "../sfml_window/assets/level_player/";
  buttons_[(unsigned)LevelPlayerButton::EXIT] =
      new ImageButton(Rect(Coord(window_width_ - 36, 4), 32, 32),
                      directory + "cancel-button.png", sf::Color::Red);

  buttons_[(unsigned)LevelPlayerButton::RUN_SIMULATION] =
      new ImageButton(Rect(Coord(window_width_ - 74, 4), 32, 32),
                      directory + "run-button.png", sf::Color::Blue);
  // more buttons will shortly follow
  buttons_[(unsigned)LevelPlayerButton::B_BASIC] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 106, 4), 32, 32), Texture(Assets::BASIC));

  buttons_[(unsigned)LevelPlayerButton::B_BEDROCK] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 70, 4), 32, 32), Texture(Assets::BEDROCK));

  buttons_[(unsigned)LevelPlayerButton::B_ENEMY] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 - 34, 4), 32, 32), Texture(Assets::ENEMY));

  buttons_[(unsigned)LevelPlayerButton::B_ENGINE] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 + 2, 4), 32, 32), Texture(Assets::ENGINE_U));

  buttons_[(unsigned)LevelPlayerButton::B_FACTORY] =
      new ToggleSpriteButton(Rect(Coord(window_width_ / 2 + 36, 4), 32, 32),
                             Texture(Assets::FACTORY_U));

  buttons_[(unsigned)LevelPlayerButton::B_TURN] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 + 72, 4), 32, 32), Texture(Assets::TURN_C));

  sf::Texture empty;
  if (!empty.loadFromFile(directory + "empty_cell.png")) {
    assert(false);
  }

  buttons_[(unsigned)LevelPlayerButton::B_EMPTY] = new ToggleSpriteButton(
      Rect(Coord(window_width_ / 2 + 108, 4), 32, 32), empty);
}

void sfml_window::LevelPlayer::LoadBackground(
    const std::string &background_path) {

  if (!background_texture_.loadFromFile(background_path))
    throw "error";
  background_texture_.setSmooth(true);
  background_sprite_.setTexture(background_texture_);
  background_sprite_.setScale(
      (float)window_width_ / (float)background_texture_.getSize().x,
      (float)window_height_ / (float)background_texture_.getSize().y);
}

void sfml_window::LevelPlayer::DrawGrid(sf::RenderWindow &window) {


    for (const auto &box : grid_)
      window.draw(box);
}

void sfml_window::LevelPlayer::GenGrid() {
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
      grid_.back().setOutlineColor(sf::Color::White);
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
    if(!level_.IsLocked(i))
      grid_[i].setOutlineColor({0, 200, 80});
}

void sfml_window::LevelPlayer::DrawCells(sf::RenderWindow &window) {
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

void sfml_window::LevelPlayer::DrawCell(sf::RenderWindow &window,
                                        sfml_window::Assets id,
                                        unsigned int position) {
  Sprite(id).setPosition(grid_[position].getPosition().x + cell_size_ / 2,
                         grid_[position].getPosition().y + cell_size_ / 2);
  if (level_.IsLocked(position))
    Sprite(id).setColor({225, 225, 225, 180});

  window.draw(Sprite(id));
}
sf::Texture &sfml_window::LevelPlayer::Texture(sfml_window::Assets cell) {
  return cells_[(unsigned)cell].first;
}

sf::Sprite &sfml_window::LevelPlayer::Sprite(sfml_window::Assets cell) {
  return cells_[(unsigned)cell].second;
}

void sfml_window::LevelPlayer::LoadAssets(const std::string &level_name) {

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

  const std::string kDir = "../levels/" + level_name + "/";
  const std::string kDefaultDir = "../levels/default/";

  // detect custom assets
  std::fstream file;
  for (int i = 0; i < (unsigned)Assets::SIZE; i++) {
    std::string full_path = kDir + file_names[i];
    file.open(full_path.c_str());
    exists[i] = file.good();
    file.close();
  }

  // for background
  if (exists[(unsigned)Assets::BACKGROUND])
    LoadBackground(kDir + file_names[(unsigned)Assets::BACKGROUND]);
  else
    LoadBackground(kDefaultDir + file_names[(unsigned)Assets::BACKGROUND]);

  // load custom assets (if one exist)
  // all loaded this way assets are simple meaning they have defined counterpart
  // in default directory
  for (int i = 0; i < (unsigned)Assets::TURN_C; i++)
    if (exists[i]) {
      std::string full_path = kDir + file_names[i];
      LoadCell((Assets)i, full_path);
    } else {
      std::string full_path = kDefaultDir + file_names[i];
      LoadCell((Assets)i, full_path);
    }

  if (EXIST(TURN_C) and not EXIST(TURN_CC)) {
    CopyCell(Assets::TURN_CC, Assets::TURN_C, FlipDirection::HORIZONTAL);
  } else if (not EXIST(TURN_C) and EXIST(TURN_CC)) {
    CopyCell(Assets::TURN_C, Assets::TURN_CC, FlipDirection::HORIZONTAL);
  } else if (not EXIST(TURN_C) and not EXIST(TURN_CC)) {
    LoadCell(Assets::TURN_C, kDefaultDir + file_names[(int)Assets::TURN_C]);
    CopyCell(Assets::TURN_CC, Assets::TURN_C, FlipDirection::HORIZONTAL);
  } else
    throw "error";
  // todo these  need to be done better

  if (not EXIST(ENGINE_U) and not EXIST(ENGINE_D) and not EXIST(ENGINE_L) and
      not EXIST(ENGINE_R)) {
    LoadCell(Assets::ENGINE_U, kDefaultDir + file_names[(int)Assets::ENGINE_U]);

    CopyCell(Assets::ENGINE_R, Assets::ENGINE_U, FlipDirection::BOTH);

    CopyCell(Assets::ENGINE_D, Assets::ENGINE_U, FlipDirection::VERTICAL);

    CopyCell(Assets::ENGINE_L, Assets::ENGINE_D, FlipDirection::HORIZONTAL);
  }
  if (not EXIST(FACTORY_U) and not EXIST(FACTORY_D) and not EXIST(FACTORY_L) and
      not EXIST(FACTORY_R)) {

    LoadCell(Assets::FACTORY_U,
             kDefaultDir + file_names[(int)Assets::FACTORY_U]);
    CopyCell(Assets::FACTORY_R, Assets::FACTORY_U, FlipDirection::BOTH);

    CopyCell(Assets::FACTORY_D, Assets::FACTORY_U, FlipDirection::VERTICAL);

    CopyCell(Assets::FACTORY_L, Assets::FACTORY_D, FlipDirection::HORIZONTAL);
  }
}

void sfml_window::LevelPlayer::LoadCell(sfml_window::Assets cell,
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

void sfml_window::LevelPlayer::CopyCell(sfml_window::Assets copy,
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
sfml_window::LevelPlayer::HandleEvent(sf::Event &event,
                                      const sf::RenderWindow &window) {
  int mouse_x = sf::Mouse::getPosition(window).x;
  int mouse_y = sf::Mouse::getPosition(window).y;

  mouse_x = mouse_x < 0 ? 0 : mouse_x;
  mouse_y = mouse_y < 0 ? 0 : mouse_y;

  mouse_x = mouse_x <= window_width_ ? mouse_x : window_width_ - 1;
  mouse_y = mouse_y <= window_height_ ? mouse_y : window_height_ - 1;

  bool change = false;

  if (event.type == sf::Event::MouseButtonReleased) {

    if (AddBotToGame({mouse_x, mouse_y}))
      return ContextEvent::UPDATE_DISPLAY;

    for (unsigned id = 0; id < buttons_.size(); id++)
      if (buttons_[id]->DetectInteraction({mouse_x, mouse_y}, event))
        switch ((LevelPlayerButton)id) {
        case LevelPlayerButton::EXIT:
          return ContextEvent::SWITCH_TO_LEVEL_PICKER;
        case LevelPlayerButton::RUN_SIMULATION:
          return ContextEvent::RUN_SIMULATION;

        case LevelPlayerButton::B_BASIC: {
          brush_ = BotType::BASIC;
          change = true;
        } break;
        case LevelPlayerButton::B_BEDROCK: {
          brush_ = BotType::BEDROCK;
          change = true;

        } break;
        case LevelPlayerButton::B_ENEMY: {
          brush_ = BotType::ENEMY;
          change = true;

        } break;
        case LevelPlayerButton::B_ENGINE: {
          brush_ = BotType::ENGINE;
          change = true;

        } break;
        case LevelPlayerButton::B_FACTORY: {
          brush_ = BotType::FACTORY;
          change = true;

        } break;
        case LevelPlayerButton::B_TURN: {
          brush_ = BotType::TURN;
          change = true;

        } break;
        case LevelPlayerButton::B_EMPTY: {
          brush_ = BotType::EMPTY;
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

unsigned sfml_window::LevelPlayer::Align(double x) {
  return (unsigned)((x * window_width_) / 100.0);
}

void sfml_window::LevelPlayer::ClearBotButtonHighlight() {

  for (int i = (int)LevelPlayerButton::B_EMPTY;
       i <= (int)LevelPlayerButton::B_BASIC; i++) {
    ((ToggleSpriteButton *)buttons_[i])->TurnOff();
  }
  switch (brush_) {
  case BotType::BASIC:
    ((ToggleSpriteButton *)buttons_[(int)LevelPlayerButton::B_BASIC])->TurnOn();
    return;
  case BotType::BEDROCK:
    ((ToggleSpriteButton *)buttons_[(int)LevelPlayerButton::B_BEDROCK])
        ->TurnOn();
    return;
  case BotType::TURN:
    ((ToggleSpriteButton *)buttons_[(int)LevelPlayerButton::B_TURN])->TurnOn();
    return;
  case BotType::ENEMY:
    ((ToggleSpriteButton *)buttons_[(int)LevelPlayerButton::B_ENEMY])->TurnOn();
    return;
  case BotType::ENGINE:
    ((ToggleSpriteButton *)buttons_[(int)LevelPlayerButton::B_ENGINE])
        ->TurnOn();
    return;
  case BotType::FACTORY:
    ((ToggleSpriteButton *)buttons_[(int)LevelPlayerButton::B_FACTORY])
        ->TurnOn();
    return;
  case BotType::EMPTY:
    ((ToggleSpriteButton *)buttons_[(int)LevelPlayerButton::B_EMPTY])->TurnOn();
  }
}

bool sfml_window::LevelPlayer::AddBotToGame(const Coord &mouse_position) {

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

sfml_window::LevelPlayer *sfml_window::LevelPlayer::Clone() {
  return new LevelPlayer(*this);
}

LevelInfo sfml_window::LevelPlayer::GetLevelInfo() {
  return LevelInfo(LevelPath(level_directory_));
}
sfml_window::LevelPlayer::~LevelPlayer() {

  for (auto &b : buttons_)
    delete b;
}
sfml_window::LevelPlayer::LevelPlayer(const sfml_window::LevelPlayer &other)
    : level_(other.level_) {
  window_width_ = other.window_width_;
  window_height_ = other.window_height_;
  background_texture_ = other.background_texture_;
  background_sprite_ = other.background_sprite_;
  button_background_ = other.button_background_;
  level_directory_ = other.level_directory_;

  cell_size_ = other.cell_size_;

  for (int i = 0; i < other.buttons_.size(); i++)
    buttons_[i] = other.buttons_[i]->Clone();

  brush_ = other.brush_;
  cells_ = other.cells_;
  grid_ = other.grid_;
}

Board sfml_window::LevelPlayer::GetLevel() { return level_; }

std::string sfml_window::LevelPlayer::GetLevelDirectory() {
  return level_directory_;
}
