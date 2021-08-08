//
// Created by studio25 on 29.07.2021.
//

#include "basic.h"
#include "../game.h"
Basic::Basic(const Coord &position) : position_(position) {}
Basic::Basic() = default;

Basic *Basic::Clone() { return this; }

void Basic::OutputToFile(std::ostream &out) const {
  out<<(unsigned)BotType::BASIC<<"\n";
}
 BotType Basic::GetType() const { return type_; }
 void Basic::CalculateMovementDirection(const std::vector<Bot *> &plane,
                                        const Coord &bot_position,
                                        const unsigned plane_width,
                                        const unsigned plane_height) {

}
void Basic::ClearMovementDirection() { movement_direction_ = movement_direction::Direction::NONE;}

