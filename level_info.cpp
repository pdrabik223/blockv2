//
// Created by studio25 on 03.08.2021.
//

#include "level_info.h"
#include <fstream>
LevelInfo::LevelInfo(const std::string &file_path) {}

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
  my_file<<name_<<"\n";

  for (const Bot* bot : plane_)
    my_file << *bot << " ";

  my_file.close();

}
void LevelInfo::LoadLevel(const std::string &file_path) {
  std::ifstream my_file;
  my_file.open(file_path);

  if (!my_file.is_open()) {
    throw "file_error";
  }

  my_file >> name_;



}
