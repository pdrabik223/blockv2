//
// Created by studio25 on 03.08.2021.
//

#include "level_info.h"


LevelInfo::LevelInfo(const std::string &file_path) { LoadLevel(file_path); }

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
    return new Empty();
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
const std::vector<bool>& LevelInfo::GetLockedFields()const  { return locked_fields_; }
