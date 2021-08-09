//
// Created by studio25 on 29.07.2021.
//

#include "game.h"

Bot *Board::GetCell(Coord position) { return plane_[position.ToInt(width_)]; }

Bot *Board::GetCell(unsigned int position) { return plane_[position]; }

Board::Board(LevelInfo &level_info) {
  plane_ = level_info.GetPLane();
  width_ = level_info.GetWidth();
  height_ = level_info.GetHeight();
}

unsigned int Board::GetWidth() const { return width_; }

unsigned int Board::GetHeight() const { return height_; }

void Board::GenPosition() {
  ClearMovementDirection();
  //  CalculateMovementDirection();
  //  CalculateMovementDirection();
  GenNextPlaneState();
}

void Board::ClearMovementDirection() {
  for (int i = 0; i < Size(); i++)
    plane_[i]->ClearMovementDirection();
}
void Board::CalculateMovementDirection() {
  for (int i = 0; i < Size(); ++i) {
    plane_[i]->Action(plane_, Coord(i % width_, i / width_), width_, height_);
  }
}

void Board::GenNextPlaneState() {
  std::vector<Bot *> temp_plane;

  temp_plane.reserve(Size());

for (int i = 0; i < Size(); ++i)
    temp_plane.push_back(nullptr);

  for (int i = 0; i < Size(); ++i) {
    if (plane_[i]->movement_direction_ == movement_direction::Direction::NONE or
        plane_[i]->movement_direction_ ==
            movement_direction::Direction::LOCK_GLOBAL)
      temp_plane[i] = plane_[i]->Clone();
    else
      temp_plane[NextPosition(
                     (Direction)((int)plane_[i]->movement_direction_ - 1),
                     Coord(i % width_, i / width_))
                     .ToInt(width_)] = plane_[i]->Clone();
  }

  for (int i = 0; i < Size(); ++i)
    if (temp_plane[i] == nullptr)
      temp_plane[i] = new Empty();

  for (int i = 0; i < Size(); ++i)
    plane_[i] = temp_plane[i]->Clone();


  for (int i = 0; i < Size(); ++i)
    delete temp_plane[i];
}

bool Board::CompareGameState(const Board &other) {
  if (width_ not_eq other.GetWidth() or height_ not_eq other.GetHeight())
    return false;

  for (int i = 0; i < Size(); ++i) {
    if (plane_[i]->type_ not_eq other.GetBotType(i))
      return false;
  }
  return true;
}
size_t Board::Size() { return plane_.size(); }
BotType Board::GetBotType(unsigned int position) const {
  return plane_[position]->type_;
}
BotType Board::GetBotType(const Coord &position) const {
  return plane_[position.ToInt(width_)]->type_;
}
