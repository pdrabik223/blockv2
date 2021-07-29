//
// Created by studio25 on 29.07.2021.
//

#ifndef BLOCK_V2_UTILITY_TRANSPOSITION_H_
#define BLOCK_V2_UTILITY_TRANSPOSITION_H_

#include "../bots/bots_main.h"
#include <vector>
enum class TranspositionType {
  NONE,
  CREATE,
  MOVE_TO,
  TURN,
  SIZE

};

/// the modification of a piece is hard, because
class Transposition {
public:
  Transposition();
  void PushTransposition(TranspositionType target);
  void PushTransposition(TranspositionType target, Bot info);
  Bot& Collapse(Bot& target);

private:
  std::vector<std::pair<TranspositionType, Bot>> transposition_;
};

#endif // BLOCK_V2_UTILITY_TRANSPOSITION_H_
