//
// Created by studio25 on 29.07.2021.
//

#include "goal.h"
Goal::Goal(const Coord &position) : position_(position) {}
Goal::Goal() {}
BotType Goal::type_ = BotType::GOAL;
