//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_

#include "../../game.h"
#include "../window_utility/button.h"
#include "context.h"
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cassert>
#include <image_button.h>
#include <iostream>

namespace sfml_window {
enum class RunSimulationButton {
  EXIT,
  STOP_SIMULATION,
  END_SIMULATION,
  SIZE
};

class RunSimulation : public Context {
public:

  /// run provided simulation
  /// \param level_info full level info object
  /// \param window_height of the window
  /// \param window_width of the window
  RunSimulation(unsigned int window_width, unsigned int window_height,
                LevelInfo &level_info);

  void DrawToWindow(sf::RenderWindow &window) override;

  ContextEvent HandleEvent(sf::Event &event,
                           const sf::RenderWindow &window) override;

  virtual ~RunSimulation();

private:
  void LoadColors() override;

  /// load pre-defined buttons to memory
  void LoadButtons();

  void GenGrid();

  /// display centered grid lines
  /// \param window target window
  void DrawGrid(sf::RenderWindow &window);

protected:
  /// \format in pixels
  /// x axis domain = <0,window_width_>
  unsigned window_width_;

  /// \format in pixels
  /// y axis domain = <0,window_height_>
  unsigned window_height_;

  std::array<Button *, (unsigned)RunSimulationButton::SIZE> buttons_;
  Board local_board_;

  /// size of a square cell
  unsigned cell_size_;

  std::vector<sf::RectangleShape> grid_;

  bool display_grid_ = true;

};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
