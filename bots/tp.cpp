//
// Created by studio25 on 29.07.2021.
//

#include "tp.h"
#include "../game.h"
Tp::Tp() = default;
Tp &Tp::operator=(const Tp& other) {
  if(&other == this) return * this;
  movement_ = other.movement_;
  id_ = other.id_;
  return *this;
}
Tp::Tp(const Tp &other) : Bot(other) {
  movement_ = other.movement_;
  id_ = other.id_;
}
Tp *Tp::Clone() { return new Tp(*this); }
void Tp::OutputToFile(std::ostream &out) const {
  out << (unsigned)BotType::TP << " " << id_ << "\n";
}
BotType Tp::GetType() const { return type_; }
void Tp::Push(const std::vector<Bot *> &plane,
                                    const Coord &bot_position,
                                    unsigned plane_width,
                                    unsigned plane_height,
              Direction push_direction) {

}
void Tp::ClearMovementDirection() { movement_.Clear(); }

Tp::Tp(unsigned int id) : id_(id) {}
void Tp::Action(const std::vector<Bot *> &plane, const Coord &bot_position,
                unsigned int plane_width, unsigned int plane_height) {}

Transposition Tp::GetMovement() const { return movement_; }



void Tp::ClearRotation() {  movement_.ClearRotation(); }
