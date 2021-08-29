//
// Created by studio25 on 29.07.2021.
//

#include "bedrock.h"

Bedrock::Bedrock() = default;

Bedrock *Bedrock::Clone() { return new Bedrock(*this); }

Bedrock::Bedrock(const Bedrock &other) : Bot(other) {
  movement_ = other.movement_;
}

Bedrock &Bedrock::operator=(const Bedrock &other) {
  if (&other == this)
    return *this;
  movement_ = other.movement_;
  return *this;
}

void Bedrock::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::BEDROCK << "\n";
}

BotType Bedrock::GetType() const { return type_; }

void Bedrock::ClearMovementDirection() {
  movement_.Clear();
  movement_.LockDirection(Direction::LEFT);
  movement_.LockDirection(Direction::RIGHT);
  movement_.LockDirection(Direction::UP);
  movement_.LockDirection(Direction::DOWN);
}

Transposition Bedrock::GetMovement() const { return movement_; }
void Bedrock::SetMovement(const Transposition &movement) {
  movement_ = movement;
}
void Bedrock::RotateCell(int angle)  { movement_.Rotate(angle); }
void Bedrock::ClearRotation() {  movement_.ClearRotation(); }
