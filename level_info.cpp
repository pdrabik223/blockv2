//
// Created by studio25 on 03.08.2021.
//

#include "level_info.h"
#include <fstream>

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
    plane_[i] = new Empty();
}
void LevelInfo::SaveLevel() {

  std::ofstream my_file;
  std::string file_path = "levels/" + name_;

  my_file.open(file_path);
  if (!my_file.is_open()) {
    throw "file_error";
  }
  my_file << name_ << "\n";
  my_file << width_ << " " << height_;

  for (const Bot *bot : plane_)
    bot->OutputFoFile(my_file);

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
      plane_.emplace_back(PushBot(my_file, {x, y}));
}
/// creates bot object and returns ptr to it
/// \important the returned hanging pointer must be deleted manually!
/// \param in ifstream handle, the cursor position within will be modified!
/// \param position position of the bot on the plane (may be unnecessary but for
/// now it stays) \return the pointer to new bot object
Bot *LevelInfo::PushBot(std::ifstream &in, const Coord &position) {
  int temp_int;
  in >> temp_int;
  switch ((BotType)temp_int) {
  case BotType::EMPTY:
    return new Empty(position);
  case BotType::BASIC:
    return new Basic(position);
  case BotType::BEDROCK:
    return new Empty(position);
  case BotType::TURN:
    in >> temp_int;
    return new Turn(position, (TurnDirection)temp_int);
  case BotType::GOAL:
    return new Goal(position);
  case BotType::ENEMY:
    return new Enemy(position);
  case BotType::ENGINE:
    in >> temp_int;
    return new Engine(position, (Direction)temp_int);
  case BotType::FACTORY:
    in >> temp_int;
    return new Factory(position, (Direction)temp_int);
  case BotType::TP:
    in >> temp_int;
    return new Tp(position, temp_int);
  case BotType::NONE:
  case BotType::SIZE:
    throw "error";
  }
}
