//
// Created by studio25 on 29.07.2021.
//

#include "basic.h"
Basic::Basic(const Coord &position) : position_(position) {}
Basic::Basic() {}

Basic *Basic::Clone() { return this; }

void Basic::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::BASIC<<"\n";
}
const BotType Basic::GetType() const { return type_; }
