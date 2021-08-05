//
// Created by studio25 on 29.07.2021.
//

#include "bedrock.h"
Bedrock::Bedrock(const Coord &position) : position_(position) {}
Bedrock::Bedrock() {}

Bedrock *Bedrock::Clone() { return this; }
void Bedrock::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::BEDROCK<<"\n";
}
