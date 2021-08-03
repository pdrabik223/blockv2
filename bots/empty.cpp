//
// Created by studio25 on 29.07.2021.
//

#include "empty.h"
Empty::Empty(const Coord &position) : position_(position) {}
Empty::Empty() {}
BotType Empty::type_ = BotType::EMPTY;
Empty *Empty::Clone() { return this; }
void Empty::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::EMPTY<<"\n";
}

