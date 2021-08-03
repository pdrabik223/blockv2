//
// Created by studio25 on 29.07.2021.
//

#include "basic.h"
Basic::Basic(const Coord &position) : position_(position) {}
Basic::Basic() {}
BotType Basic::type_ = BotType::BASIC;
Basic *Basic::Clone() { return this; }

void Basic::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::BASIC<<"\n";
}

