//
// Created by studio25 on 29.07.2021.
//

#include "game.h"
#include <iostream>

Bot *Board::GetCell(const Coord &position) {
  return plane_[position.ToInt(width_)];
}

Bot *Board::GetCell(unsigned int position) { return plane_[position]; }

Board::Board(const LevelInfo &level_info) {

  plane_.clear();

  for (const auto &b : level_info.GetPLane())
    plane_.emplace_back(b->Clone());

  locked_fields_ = level_info.GetLockedFields();

  width_ = level_info.GetWidth();
  height_ = level_info.GetHeight();
}

Board &Board::operator=(const Board &other) {
  if (&other == this)
    return *this;

  for (const auto &b : other.plane_)
    plane_.emplace_back(b->Clone());

  locked_fields_ = other.locked_fields_;

  width_ = other.width_;
  height_ = other.height_;
  return *this;
}

unsigned int Board::GetWidth() const { return width_; }

unsigned int Board::GetHeight() const { return height_; }

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

bool Board::IsWon() {
  for (const auto &b : plane_)
    if (b->GetType() == BotType::GOAL)
      return false;

  return true;
}

void Board::AddCell(int x, int y, BotType type) {
  assert(x < width_ and y < height_);

  delete plane_[y * width_ + x];
  switch (type) {
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
  case BotType::ENGINE:
    plane_[y * width_ + x] = new Engine(Direction::UP);
    break;
  case BotType::FACTORY:
    plane_[y * width_ + x] = new Factory(Direction::UP);
    break;
  case BotType::TP:
    plane_[y * width_ + x] = new Tp(1);
    break;
  case BotType::TURN:
    plane_[y * width_ + x] = new Turn(TurnDirection::CLOCKWISE);
    break;
  case BotType::NONE:
  case BotType::SIZE:
    assert(false);
    throw "bad type";
  }
}

void Board::RotateCell(int x, int y) {
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

void Board::Lock(const Coord &position) {
  locked_fields_[position.ToInt(width_)] = true;
}

bool Board::IsLocked(const Coord &position) {
  return locked_fields_[position.ToInt(width_)];
}

bool Board::IsLocked(int position) { return locked_fields_[position]; }

void Board::UnLock(const Coord &position) {
  locked_fields_[position.ToInt(width_)] = false;
}

void Board::GenPosition() {

  ClearMovementDirection();
  ClearRotation();

  EngagePush();
  //  ClearRotation();

  EngagePush();
  GenNextPlaneState();

  ActivateSecondAction();

  // first run all the movement
  //  for (int x = 0; x < width_; x++)
  //    for (int y = 0; y < height_; y++) {
  //      switch (GetCell({x, y})->GetType()) {
  //      case BotType::ENGINE:
  //      case BotType::FACTORY:
  //        Snake({x, y});
  //      default:
  //        break;
  //      }
  //    }
}

void Board::ClearMovementDirection() {
  for (int i = 0; i < Size(); i++)
    plane_[i]->ClearMovementDirection();
}

void Board::EngagePush() {
  for (int i = 0; i < Size(); ++i) {
    plane_[i]->Action(plane_, Coord(i % width_, i / width_), width_, height_);
  }
}

void Board::ActivateSecondAction() {
  for (int i = 0; i < Size(); ++i) {
    plane_[i]->SecondAction(plane_, Coord(i % width_, i / width_), width_,
                            height_);
  }
}

void Board::EmplaceBot(std::vector<Bot *> &plane, const Coord &placement,
                       BotType type, int rotation) {

  switch (type) {
  case BotType::BASIC:
    plane[placement.ToInt(width_)] =
        CrushBots(new Basic, plane[placement.ToInt(width_)]);
    break;
  case BotType::BEDROCK:
    plane[placement.ToInt(width_)] =
        CrushBots(new Bedrock, plane[placement.ToInt(width_)]);
    break;
  case BotType::TURN: {
    if (rotation == 0 or rotation == 180 or rotation == -180)
      plane[placement.ToInt(width_)] = CrushBots(
          new Turn(TurnDirection::CLOCKWISE), plane[placement.ToInt(width_)]);
    else if (rotation == 90 or rotation == -90)
      plane[placement.ToInt(width_)] =
          CrushBots(new Turn(TurnDirection::COUNTER_CLOCKWISE),
                    plane[placement.ToInt(width_)]);
    else
      assert(false);
  } break;
  case BotType::TP:
    plane[placement.ToInt(width_)] =
        CrushBots(new Tp(0), plane[placement.ToInt(width_)]);
    break;
  case BotType::GOAL:
    plane[placement.ToInt(width_)] =
        CrushBots(new Goal, plane[placement.ToInt(width_)]);
    break;
  case BotType::ENEMY:
    plane[placement.ToInt(width_)] =
        CrushBots(new Enemy, plane[placement.ToInt(width_)]);
    break;

  case BotType::ENGINE: {
    if (rotation == 0)
      plane[placement.ToInt(width_)] =
          CrushBots(new Engine(Direction::UP), plane[placement.ToInt(width_)]);

    else if (rotation == 90)
      plane[placement.ToInt(width_)] = CrushBots(
          new Engine(Direction::RIGHT), plane[placement.ToInt(width_)]);

    else if (rotation == -90 or rotation == 270)
      plane[placement.ToInt(width_)] = CrushBots(
          new Engine(Direction::LEFT), plane[placement.ToInt(width_)]);

    else if (rotation == 180 or rotation == -180)
      plane[placement.ToInt(width_)] = CrushBots(
          new Engine(Direction::DOWN), plane[placement.ToInt(width_)]);
    else
      assert(false);
  } break;

  case BotType::FACTORY: {
    if (rotation == 0)
      plane[placement.ToInt(width_)] =
          CrushBots(new Factory(Direction::UP), plane[placement.ToInt(width_)]);
    else if (rotation == 90)
      plane[placement.ToInt(width_)] = CrushBots(
          new Factory(Direction::RIGHT), plane[placement.ToInt(width_)]);
    else if (rotation == -90)
      plane[placement.ToInt(width_)] = CrushBots(
          new Factory(Direction::LEFT), plane[placement.ToInt(width_)]);
    else if (rotation == 180 or rotation == -180)
      plane[placement.ToInt(width_)] = CrushBots(
          new Factory(Direction::DOWN), plane[placement.ToInt(width_)]);
    else
      assert(false);

  } break;

  case BotType::EMPTY:
    plane[placement.ToInt(width_)] =
        CrushBots(new Empty, plane[placement.ToInt(width_)]);
    break;

  case BotType::NONE:
  case BotType::SIZE:
    assert(false);
    break;
  }
}

void Board::GenNextPlaneState() {

  std::vector<Bot *> temp_plane;

  temp_plane.reserve(Size());

  for (int i = 0; i < Size(); ++i)
    temp_plane.push_back(nullptr);

  for (int y = 0; y < height_; ++y) {
    for (int x = 0; x < width_; ++x) {

      Coord origin(x, y);

      // calculate new placement for the cell
      Coord target(GetCell(origin)->GetMovement().Collapse(origin));

      int angle = CollapseRotation(origin);

      EmplaceBot(temp_plane, target, GetBotType(origin), angle);

      //
      //      // place cell at it's correct placement
      //      if (!temp_plane[target.ToInt(width_)])
      //        temp_plane[target.ToInt(width_)] = GetCell(origin)->Clone();
      //      else
      //        temp_plane[target.ToInt(width_)] =
      //            CrushBots(temp_plane[target.ToInt(width_)],
      //            GetCell(origin));
      //
      //      if (GetCell(origin)->GetMovement().rotation_angle_ not_eq 0)
      //
      //        temp_plane[target.ToInt(width_)]->SetRotation(
      //            (GetCell(origin)->GetMovement().rotation_angle_));
    }
  }

  for (int i = 0; i < Size(); ++i)
    if (temp_plane[i] == nullptr)
      temp_plane[i] = new Empty();

  plane_.clear();
  plane_.reserve(Size());

  for (int i = 0; i < Size(); ++i)
    plane_.emplace_back(temp_plane[i]->Clone());
}

//
// void Board::LockEdges() {
//   //    for (int i = 0; i < Size(); ++i)
//   //      plane_[i]->LockEdges(plane_, Coord(i % width_, i / width_),
//   width_,
//   //      height_,);
// }
//
// void Board::GenNextPlaneState() {
//   std::vector<Bot *> temp_plane;
//
//   temp_plane.reserve(Size());
//
//   for (int i = 0; i < Size(); ++i)
//     temp_plane.push_back(nullptr);
//   std::cout << "new frame: generating\n";
//
//   for (int y = 0; y < height_; ++y) {
//     for (int x = 0; x < width_; ++x) {
//
//       Coord origin(x, y);
//       Coord target(GetCell(origin)->GetMovement().Collapse(origin));
//
//       //      if(temp_plane[target.ToInt(width_)] == nullptr) // this is
//       kinda
//       //      flimsily solution
//       if (temp_plane[target.ToInt(width_)] == nullptr)
//         temp_plane[target.ToInt(width_)] = GetCell(origin)->Clone();
//       else
//         temp_plane[target.ToInt(width_)] =
//             CrushBots(temp_plane[target.ToInt(width_)], GetCell(origin));
//     }
//   }
//
//   for (int i = 0; i < Size(); ++i)
//     if (temp_plane[i] == nullptr)
//       temp_plane[i] = new Empty();
//
//   for (int i = 0; i < Size(); ++i)
//     if (temp_plane[i]->GetType() == BotType::FACTORY)
//       ((Factory *)temp_plane[i])
//           ->Spawn(temp_plane, Coord(i % width_, i / width_), width_,
//           height_);
//
//   plane_.clear();
//   plane_.reserve(Size());
//
//   for (int i = 0; i < Size(); ++i)
//     plane_.emplace_back(temp_plane[i]->Clone());
//
//   //    for (int i = 0; i < Size(); ++i) emmm idk I just dont know
//   //      delete temp_plane[i];
// }

Bot *Board::CrushBots(Bot *bot_a, Bot *bot_b) {
  if (bot_a == nullptr)
    return bot_b->Clone();
  if (bot_b == nullptr)
    return bot_a->Clone();

  int value_of_a_life = GetValue(*bot_a);
  int value_of_b_life = GetValue(*bot_b);
  // empty = 0, goal = 1, engine = 2, factory = 2, kill = 3, tp, turn ,
  // basic,
  // bedrock = 4

  return value_of_a_life > value_of_b_life ? bot_a->Clone() : bot_b->Clone();
}

void Board::ClearRotation() {
  for (auto &b : plane_)
    b->ClearRotation();
}

int Board::CollapseRotation(const Coord &coord) {

  switch (GetBotType(coord)) {
    // for those rotations doesn't matter
  case BotType::BASIC:
  case BotType::BEDROCK:
  case BotType::GOAL:
  case BotType::ENEMY:
  case BotType::EMPTY:
    return 0;
  case BotType::TURN: {
    int rotation = 0;

    switch (((Turn *)GetCell(coord))->GetDirection()) {
    case TurnDirection::CLOCKWISE:
      break;
    case TurnDirection::COUNTER_CLOCKWISE:
      rotation += 90;
      break;
    }

    return rotation + GetCell(coord)->GetMovement().rotation_angle_;
  }
  case BotType::ENGINE: {
    int rotation = 0;

    switch (((Engine *)GetCell(coord))->GetDirection()) {

    case Direction::UP:
      break;
    case Direction::DOWN:
      rotation += 180;
      break;
    case Direction::LEFT:
      rotation -= 90;
      break;
    case Direction::RIGHT:
      rotation += 90;
      break;
    }
    if (GetCell(coord)->GetMovement().rotation_angle_ != 0) {
      //        break me daddy
    }
    return rotation + GetCell(coord)->GetMovement().rotation_angle_;
  }

  case BotType::FACTORY: {
    int rotation = 0;

    switch (((Factory *)GetCell(coord))->GetDirection()) {
    case Direction::UP:
      break;
    case Direction::DOWN:
      rotation += 180;
      break;
    case Direction::LEFT:
      rotation -= 90;
      break;
    case Direction::RIGHT:
      rotation += 90;
      break;
    }

    return rotation + GetCell(coord)->GetMovement().rotation_angle_;
  }
  case BotType::NONE:
  case BotType::SIZE:
    assert(false);
  }
}
