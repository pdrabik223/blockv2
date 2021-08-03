//
// Created by studio25 on 03.08.2021.
//

#include "run_simulation.h"

sfml_window::RunSimulation::~RunSimulation() {
  for (auto &button : buttons_) {
    delete button;
  }
}
sfml_window::RunSimulation::RunSimulation(const Board &local_board,
                                          const std::string &directory_path): local_board_(local_board) {


}
