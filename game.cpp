//
// Created by studio25 on 29.07.2021.
//

#include "game.h"

Bot *Board::GetCell(Coord position) { return plane_[position.ToInt(width_)];}

Bot *Board::GetCell(unsigned int position) { return plane_[position]; }

Board::Board( LevelInfo &level_info) {
    plane_ = level_info.GetPLane();
    width_ = level_info.GetWidth();
    height_ = level_info.GetHeight();
}

unsigned int Board::GetWidth() const { return width_; }

unsigned int Board::GetHeight() const { return height_; }

void Board::GenPosition() {
  ClearMovementDirection();


}
void Board::ClearMovementDirection() {
  for(auto & b:plane_)
    b->movement_direction_ = movement_direction::Direction::NONE;
}
void Board::CalculateMovementDirection() {
  for (int i = 0; i < Size(); ++i) {

  }
}

bool Board::CompareGameState(const Board& other) {
  if(width_ not_eq other.GetWidth() or height_ not_eq other.GetHeight())
    return false;

  for (int i = 0; i < Size(); ++i) {
    if(plane_[i]->type_ not_eq other.GetBotType(i))
      return false;

  }
  return true;
}
size_t Board::Size() { return plane_.size();   }
BotType Board::GetBotType(unsigned int position) const { return plane_[position]->type_; }
BotType Board::GetBotType(const Coord& position)const { return plane_[position.ToInt(width_)]->type_; }
