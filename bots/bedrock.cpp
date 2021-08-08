//
// Created by studio25 on 29.07.2021.
//

#include "bedrock.h"
Bedrock::Bedrock(const Coord &position) : position_(position) {}
Bedrock::Bedrock() = default;

Bedrock *Bedrock::Clone() { return this; }
void Bedrock::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::BEDROCK<<"\n";
}
 BotType Bedrock::GetType() const {return type_; }
void Bedrock::CalculateMovementDirection(const std::vector<Bot *> &plane) {}
void Bedrock::ClearMovementDirection() {movement_direction_ = movement_direction::Direction::LOCK_GLOBAL;}
