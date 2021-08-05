//
// Created by studio25 on 29.07.2021.
//

#include "empty.h"
Empty::Empty(const Coord &position) : position_(position) {}
Empty::Empty() {}

Empty *Empty::Clone() { return this; }
void Empty::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::EMPTY<<"\n";
}
const BotType Empty::GetType() const { return type_; }
