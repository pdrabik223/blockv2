//
// Created by studio25 on 29.07.2021.
//

#include "game.h"
unsigned Board::Conv2D(Coord position){return position.y*width_+position.x;};

Board::Board(unsigned int width, unsigned int height)
    : width_(width), height_(height) {}
Bot &Board::GetCell(Coord position) { return plane_[Conv2D(position)];}
void Board::CollapseTranspositionTable() {

  for (int i = 0; i < transposition_table_.size(); ++i) {
    plane_[i] = transposition_table_[i].Collapse(GetCell(i));
  }

}
Bot &Board::GetCell(unsigned int position) { return plane_[position]; }