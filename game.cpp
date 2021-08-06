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
