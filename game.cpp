//
// Created by studio25 on 29.07.2021.
//

#include "game.h"
#include <iostream>

Bot *Board::GetCell(Coord position) { return plane_[position.ToInt(width_)]; }

Bot *Board::GetCell(unsigned int position) { return plane_[position]; }

Board::Board(const LevelInfo &level_info) {

  plane_.clear();
  for(const auto& b:level_info.GetPLane())
    plane_.emplace_back(b->Clone());

  width_ = level_info.GetWidth();
  height_ = level_info.GetHeight();

}

unsigned int Board::GetWidth() const { return width_; }

unsigned int Board::GetHeight() const { return height_; }

void Board::GenPosition() {

  ClearMovementDirection();
  CalculateMovementDirection();
  CalculateMovementDirection();

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

void Board::LockEdges() {
  //    for (int i = 0; i < Size(); ++i)
  //      plane_[i]->LockEdges(plane_, Coord(i % width_, i / width_), width_,
  //      height_,);
}

void Board::GenNextPlaneState() {
  std::vector<Bot *> temp_plane;

  temp_plane.reserve(Size());

  for (int i = 0; i < Size(); ++i)
    temp_plane.push_back(nullptr);
  std::cout << "new frame: generating\n";

  for (int y = 0; y < height_; ++y) {
    for (int x = 0; x < width_; ++x) {

      Coord origin(x, y);
      Coord target(GetCell(origin)->GetMovement().Collapse(origin));

      //      if(temp_plane[target.ToInt(width_)] == nullptr) // this is kinda
      //      flimsily solution
      if (temp_plane[target.ToInt(width_)] == nullptr)
        temp_plane[target.ToInt(width_)] = GetCell(origin)->Clone();
      else
        temp_plane[target.ToInt(width_)] =
            CrushBots(temp_plane[target.ToInt(width_)], GetCell(origin));
    }
  }

  for (int i = 0; i < Size(); ++i)
    if (temp_plane[i] == nullptr)
      temp_plane[i] = new Empty();

  for (int i = 0; i < Size(); ++i)
    if (temp_plane[i]->GetType() == BotType::FACTORY)
      ((Factory *)temp_plane[i])
      ->Spawn(temp_plane, Coord(i % width_, i / width_), width_, height_);

  plane_.clear();
  plane_.reserve(Size());

  for (int i = 0; i < Size(); ++i)
    plane_.emplace_back(temp_plane[i]->Clone());

  //    for (int i = 0; i < Size(); ++i) emmm idk I just dont know
  //      delete temp_plane[i];
}

bool Board::CompareGameState(const Board &other) {
  if (width_ not_eq other.GetWidth() or height_ not_eq other.GetHeight())
    return false;

  for (int i = 0; i < Size(); ++i) {
    if (plane_[i]->GetType() not_eq other.GetBotType(i))
      return false;
  }
  return true;
}

size_t Board::Size() const { return width_ * height_; }

BotType Board::GetBotType(unsigned int position) const {
  return plane_[position]->GetType();
}

BotType Board::GetBotType(const Coord &position) const {
  return plane_[position.ToInt(width_)]->GetType();
}

int GetValue(const Bot &bot_a) {

  switch (bot_a.GetType()) {
  case BotType::BASIC:
  case BotType::BEDROCK:
  case BotType::TURN:
  case BotType::TP:
    return 4;
  case BotType::ENEMY:
    return 3;
  case BotType::FACTORY:
  case BotType::ENGINE:
    return 2;
  case BotType::GOAL:
    return 1;
  case BotType::EMPTY:
    return 0;
  case BotType::NONE:
    assert(false);
    break;
  case BotType::SIZE:
    assert(false);
    break;
  }
  assert(false);
  return -1;
}

Bot *Board::CrushBots(Bot *bot_a, Bot *bot_b) {
  int value_of_a_life = GetValue(*bot_a);
  int value_of_b_life = GetValue(*bot_b);
  // empty = 0, goal = 1, engine = 2, factory = 2, kill = 3, tp, turn , basic,
  // bedrock = 4

  return value_of_a_life > value_of_b_life ? bot_a->Clone() : bot_b->Clone();
}

bool Board::IsWon() {
  for (const auto &b : plane_)
    if (b->GetType() == BotType::GOAL)
      return false;

  return true;
}
