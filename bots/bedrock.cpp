//
// Created by studio25 on 29.07.2021.
//

#include "bedrock.h"

Bedrock::Bedrock() = default;

Bedrock *Bedrock::Clone() { return new Bedrock(*this); }

void Bedrock::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::BEDROCK << "\n";
}
BotType Bedrock::GetType() const { return type_; }

void Bedrock::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                         const Coord &bot_position,
                                         const unsigned plane_width,
                                         const unsigned plane_height,
                                         const Direction push_direction) {
  // do nothing :P
}
void Bedrock::ClearMovementDirection() {
  movement_.Clear();
  movement_.LockDirection(Direction::LEFT);
  movement_.LockDirection(Direction::RIGHT);
  movement_.LockDirection(Direction::UP);
  movement_.LockDirection(Direction::DOWN);

}
void Bedrock::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                     unsigned plane_width,
                     unsigned plane_height) { /*do nothing*/}

Bedrock::Bedrock(const Bedrock &other) : Bot(other) {
  movement_ = other.movement_;
}

 Transposition Bedrock::GetMovement() const { return movement_; }
