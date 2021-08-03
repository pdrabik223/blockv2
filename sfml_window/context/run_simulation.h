//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_

#include "../../game.h"
#include "../window_utility/button.h"
#include "context.h"

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
  /// \param local_board the starting position
  /// \param directory_path the path to assets
  /// \param window_height of the window
  /// \param window_width of the window
  RunSimulation(const Board &local_board, const std::string &directory_path,
                unsigned int window_width, unsigned int window_height);

  void DrawToWindow(sf::RenderWindow &window) override;

  ContextEvent HandleEvent(sf::Event &event,
                           const sf::RenderWindow &window) override;

  virtual ~RunSimulation();

private:
  void LoadColors() override;

  /// load pre-defined buttons to memory
  void LoadButtons();

protected:
  /// \format in pixels
  /// x axis domain = <0,window_width_>
  unsigned window_width_;

  /// \format in pixels
  /// y axis domain = <0,window_height_>
  unsigned window_height_;

  std::array<Button *, (unsigned)RunSimulationButton::SIZE> buttons_{};
  Board local_board_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
