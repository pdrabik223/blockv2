//
// Created by studio25 on 29.07.2021.
//

#include "bedrock.h"

Bedrock::Bedrock() = default;

Bedrock *Bedrock::Clone() { return this; }
void Bedrock::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::BEDROCK << "\n";
}
BotType Bedrock::GetType() const { return type_; }
void Bedrock::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                         const Coord &bot_position,
                                         const unsigned plane_width,
                                         const unsigned plane_height,
    const movement_direction::Direction push_direction) {
  // do nothing :P
}
void Bedrock::ClearMovementDirection() {
  movement_direction_ = movement_direction::Direction::LOCK_GLOBAL;
}
void Bedrock::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                     unsigned plane_width,
                     unsigned plane_height) { /*do nothing*/
}
Bedrock::Bedrock(const Bedrock &other) : Bot(other) {
  movement_direction_ = other.movement_direction_;
}
void Bedrock::LockEdge(const std::vector<Bot *> &plane,
                       const Coord &bot_position,
                       const unsigned int plane_width,
                       const unsigned int plane_height,
                       Direction push_direction) {

}
