//
// Created by studio25 on 29.07.2021.
//

#include "game.h"
unsigned Board::Conv2D(Coord position){return position.y*width_+position.x;};

Board::Board(unsigned int width, unsigned int height)
    : width_(width), height_(height) {}

Bot *Board::GetCell(Coord position) { return plane_[Conv2D(position)];}

void Board::CollapseTranspositionTable() {
//
//  for (int i = 0; i < transposition_table_.size(); ++i) {
//    plane_[i] = transposition_table_[i].Collapse(*GetCell(i));
//  }

}
Bot *Board::GetCell(unsigned int position) { return plane_[position]; }

Board::Board( LevelInfo &level_info) {
    plane_ = level_info.GetPLane();
    width_ = level_info.GetWidth();
    height_ = level_info.GetHeight();
}
unsigned int Board::GetWidth() const { return width_; }
unsigned int Board::GetHeight() const { return height_; }
