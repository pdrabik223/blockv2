//
// Created by studio25 on 29.07.2021.
//

#include "tp.h"
Tp::Tp(const Coord &position,unsigned id) : position_(position),id_(id) {}
Tp::Tp() {}

Tp *Tp::Clone() { return this; }
void Tp::OutputFoFile(std::ostream &out) const {
  out<<(unsigned)BotType::TP<<"\n";
}
