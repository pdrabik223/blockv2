//
// Created by studio25 on 03.08.2021.
//

#include "run_simulation.h"

sfml_window::RunSimulation::RunSimulation() {}
sfml_window::RunSimulation::~RunSimulation() {
  for (auto& button:buttons_) {
    delete button;
  }
}
