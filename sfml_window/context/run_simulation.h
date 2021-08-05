//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_

#include "../../game.h"
#include "../window_utility/button.h"
#include "context.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <cassert>
#include <image_button.h>
#include <iostream>
#include <vector>

namespace sfml_window {
enum class RunSimulationButton { EXIT, STOP_SIMULATION, END_SIMULATION, SIZE };
enum class Assets {
  BASIC, /// something like stone
  BEDROCK,
  ENEMY,
  TP,
  GOAL,

  TURN_C,  /// clockwise
  TURN_CC, /// counterclockwise
  ENGINE_U, /// up
  ENGINE_D, /// down
  ENGINE_L, /// left
  ENGINE_R, /// right

  FACTORY_U, /// up
  FACTORY_D, /// down
  FACTORY_L, /// left
  FACTORY_R, /// right
  BACKGROUND,
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

  void LoadBackground(const std::string &level_name);

  void LoadAssets(const std::string &level_name);

  void LoadCell(Assets cell, const std::string &asset_path);

  void CopyCell(Assets copy, Assets original, double angle);

  void GenGrid();

  /// display centered grid lines
  /// \param window target window
  void DrawGrid(sf::RenderWindow &window);

  void DrawCells(sf::RenderWindow &window);

  sf::Texture &Texture(Assets cell);
  sf::Sprite &Sprite(Assets cell);

protected:
  /// \format in pixels
  /// x axis domain = <0,window_width_>
  unsigned window_width_;

  /// \format in pixels
  /// y axis domain = <0,window_height_>
  unsigned window_height_;

  /// background texture
  sf::Texture background_texture_;
  /// background sprite always provided by user
  sf::Sprite background_sprite_;

  std::array<Button *, (unsigned)RunSimulationButton::SIZE> buttons_;

  std::array<std::pair<sf::Texture, sf::Sprite>, (unsigned)Assets::SIZE>
      cells_;
  Board local_board_;

  /// size of a square cell
  unsigned cell_size_;

  std::vector<sf::RectangleShape> grid_;

  bool display_grid_ = true;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
