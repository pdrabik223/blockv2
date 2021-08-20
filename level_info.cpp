//
// Created by studio25 on 03.08.2021.
//

#include "level_info.h"

LevelInfo::LevelInfo(const std::string &file_path) { LoadLevel(file_path); }
LevelInfo::LevelInfo(const LevelInfo &other) {
  name_ = other.name_;
  width_ = other.width_;
  height_ = other.height_;

  for (const auto &b : other.plane_)
    plane_.emplace_back(b->Clone());

  locked_fields_ = other.locked_fields_;
}
LevelInfo &LevelInfo::operator=(const LevelInfo &other) {
  if (&other == this)
    return *this;
  name_ = other.name_;
  width_ = other.width_;
  height_ = other.height_;

  for (const auto &b : other.plane_)
    plane_.emplace_back(b->Clone());

  locked_fields_ = other.locked_fields_;
  return *this;
}

LevelInfo::~LevelInfo() {

  for (auto &bot : plane_)
    delete bot;
}

LevelInfo::LevelInfo(unsigned int width, unsigned int height)
    : width_(width), height_(height) {
  name_ = "no_name_given";

  plane_.reserve(width_ * height_);

  for (auto i = 0; i < plane_.capacity(); i++)
    plane_.emplace_back(new Empty());

  for (auto i = 0; i < plane_.capacity(); i++)
    locked_fields_.emplace_back(false);
}
void LevelInfo::SaveLevel() {

  std::ofstream my_file;

  std::string directory_path = "..\\levels\\" + name_;
  CreateDirectoryA(directory_path.c_str(), NULL);

  int k = 1;
  while (CreateDirectoryA(std::string(directory_path + (char)k).c_str(),
                          NULL) == ERROR_ALREADY_EXISTS) {
    k++;
  }

  std::string file_path = "../levels/" + name_ + "/" + name_;

  my_file.open(file_path);
  if (!my_file.is_open()) {
    throw "file_error";
  }
  my_file << name_ << "\n";
  my_file << width_ << " " << height_ << "\n";

  for (const Bot *bot : plane_)
    bot->OutputToFile(my_file);

  for (const auto l : locked_fields_)
    my_file << l << " ";

  my_file.close();
}
void LevelInfo::LoadLevel(const std::string &file_path) {
  std::ifstream my_file;
  my_file.open(file_path);

  if (!my_file.is_open()) {
    throw "file_error";
  }

  my_file >> name_;
  my_file >> width_;
  my_file >> height_;

  for (unsigned x = 0; x < width_; ++x)
    for (unsigned y = 0; y < height_; ++y)
      plane_.emplace_back(PushBot(my_file, Coord(x, y)));

  for (unsigned x = 0; x < height_ * width_; ++x) {
    bool info;
    my_file >> info;
    locked_fields_.emplace_back(info);
  }
}
/// creates bot object and returns ptr to it
/// \important the returned hanging pointer must be deleted manually!
/// \param in ifstream handle, the cursor position within will be modified!
/// \param position position of the bot on the plane (may be unnecessary but for
/// now it stays) \return the pointer to new bot object
Bot *LevelInfo::PushBot(std::ifstream &in, const Coord &position) {
  assert(position.x < width_ and position.y < height_);
  int temp_int;
  in >> temp_int;
  switch ((BotType)temp_int) {
  case BotType::EMPTY:
    return new Empty();
  case BotType::BASIC:
    return new Basic();
  case BotType::BEDROCK:
    return new Bedrock();
  case BotType::TURN:
    in >> temp_int;
    return new Turn((TurnDirection)temp_int);
  case BotType::GOAL:
    return new Goal();
  case BotType::ENEMY:
    return new Enemy();
  case BotType::ENGINE:
    in >> temp_int;
    return new Engine((Direction)temp_int);
  case BotType::FACTORY:
    in >> temp_int;
    return new Factory((Direction)temp_int);
  case BotType::TP:
    in >> temp_int;
    return new Tp(temp_int);
  case BotType::NONE:
  case BotType::SIZE:
    throw "error";
  }
  throw "error";
}

void LevelInfo::AddBot(const Coord &position, BotType type) {
  assert(position.x < width_ and position.y < height_);
  delete plane_[position.ToInt(width_)];
  switch (type) {
  case BotType::EMPTY:
    plane_[position.ToInt(width_)] = new Empty();
    break;
  case BotType::BASIC:
    plane_[position.ToInt(width_)] = new Basic();
    break;
  case BotType::BEDROCK:
    plane_[position.ToInt(width_)] = new Bedrock();
    break;
  case BotType::GOAL:
    plane_[position.ToInt(width_)] = new Goal();
    break;
  case BotType::ENEMY:
    plane_[position.ToInt(width_)] = new Enemy();
    break;
  default:
    throw "bad type";
  }
}
void LevelInfo::AddBot(const Coord &position, BotType type,
                       Direction direction) {

  delete plane_[position.ToInt(width_)];

  assert(position.x < width_ and position.y < height_);
  switch (type) {
  case BotType::ENGINE:
    plane_[position.ToInt(width_)] = new Engine(direction);
    break;
  case BotType::FACTORY:
    plane_[position.ToInt(width_)] = new Factory(direction);
    break;
  default:
    throw "bad type";
  }
}
void LevelInfo::AddBot(const Coord &position, BotType type,
                       TurnDirection turn_direction) {
  assert(position.x < width_ and position.y < height_);
  delete plane_[position.ToInt(width_)];
  switch (type) {
  case BotType::TURN:
    plane_[position.ToInt(width_)] = new Turn(turn_direction);
    break;
  default:
    throw "bad type";
  }
}
void LevelInfo::AddBot(const Coord &position, BotType type, int id) {
  assert(position.x < width_ and position.y < height_);
  delete plane_[position.ToInt(width_)];
  switch (type) {
  case BotType::TP:
    plane_[position.ToInt(width_)] = new Tp(id);
    break;
  default:
    throw "bad type";
  }
}
unsigned int LevelInfo::GetWidth() const { return width_; }
unsigned int LevelInfo::GetHeight() const { return height_; }
const std::string &LevelInfo::GetName() const { return name_; }

void LevelInfo::Lock(Coord position) {
  locked_fields_[position.ToInt(width_)] = true;
}
bool LevelInfo::IsLocked(Coord position) {
  return locked_fields_[position.ToInt(width_)];
}
bool LevelInfo::IsLocked(int position) { return locked_fields_[position]; }

const std::vector<bool> &LevelInfo::GetLockedFields() const {
  return locked_fields_;
}
Bot *LevelInfo::GetCell(int position) { return plane_[position]; }

void LevelInfo::AddCell(int x, int y, BotType type) {
  assert(x < width_ and y < height_);
  switch (type) {
  case BotType::ENGINE:
    plane_[y * width_ + x] = new Engine(Direction::UP);
    break;
  case BotType::FACTORY:
    plane_[y * width_ + x] = new Factory(Direction::UP);
    break;
  case BotType::EMPTY:
    plane_[y * width_ + x] = new Empty();
    break;
  case BotType::BASIC:
    plane_[y * width_ + x] = new Basic();
    break;
  case BotType::BEDROCK:
    plane_[y * width_ + x] = new Bedrock();
    break;
  case BotType::GOAL:
    plane_[y * width_ + x] = new Goal();
    break;
  case BotType::ENEMY:
    plane_[y * width_ + x] = new Enemy();
    break;
  case BotType::TURN:
    plane_[y * width_ + x] = new Turn(TurnDirection::CLOCKWISE);
    break;
  case BotType::TP:
    plane_[y * width_ + x] = new Tp(1);
    break;
  }
}
void LevelInfo::RotateCell(int x, int y) {
  assert(x < width_ and y < height_);

  switch (plane_[y * width_ + x]->GetType()) {
  case BotType::BASIC:
  case BotType::BEDROCK:
  case BotType::GOAL:
  case BotType::ENEMY:
  case BotType::TP:
  case BotType::EMPTY:
    return;
  case BotType::TURN:
    ((Turn *)plane_[y * width_ + x])->RotateCell();
    return;
  case BotType::ENGINE:
    ((Engine *)plane_[y * width_ + x])->RotateCell();
    return;
  case BotType::FACTORY:
    ((Factory *)plane_[y * width_ + x])->RotateCell();
    return;

  case BotType::NONE:
  case BotType::SIZE:
    assert(false);
    return;
  }
}
void LevelInfo::UnLock(Coord position) {
  locked_fields_[position.ToInt(width_)] = false;
}
void LevelInfo::SetName(const std::string &name) { name_ = name; }
void LevelInfo::Resize(const int new_width, const int new_height) {

  std::vector<Bot *> level_copy = plane_;
  std::vector<bool> locked_fields_copy = locked_fields_;

  unsigned i = 0;
  plane_.clear();
  locked_fields_.clear();
  plane_.reserve(new_height * new_width);
  locked_fields_.reserve(new_height * new_width);
  for (int x = 0; x < new_height; x++) {
    for (int y = 0; y < new_width; y++) {
      if (x < height_ && y < width_) {

        plane_.push_back(level_copy[i]->Clone());
        locked_fields_.emplace_back(locked_fields_copy[i]);
        ++i;

      } else
        plane_.push_back(new Empty());
      locked_fields_.emplace_back(false);
    }
    if (new_width < width_)
      i += width_ - new_width;
  }
  width_ = new_width;
  height_ = new_height;

}
