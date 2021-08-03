//
// Created by studio25 on 29.07.2021.
//

#include "transposition.h"

Transposition::Transposition(){}
void Transposition::PushTransposition(TranspositionType target) {
//  transposition_.emplace_back(target, Bot());
}
void Transposition::PushTransposition(TranspositionType target, Bot info) {
//  transposition_.emplace_back(target, info.Clone());
}
Bot *Transposition::Collapse(Bot &target) {
  return &target;
}
