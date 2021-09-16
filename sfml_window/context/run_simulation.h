//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_

#include "context.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include <SFML/Graphics/RectangleShape.hpp>

#include <image_button.h>
#include <image_toggle_button.h>
#include <thread>
namespace sfml_window {
/// list  of buttons
enum class RunSimulationButton {
  TROPHY,
  STEP_SIMULATION,
  //  STOP_START_SIMULATION,
  EXIT,
  SIZE
};

class RunSimulation : public Context {
public:
  /// run provided simulation
  /// \param level_info full level info object
  /// \param window_height of the window
  /// \param window_width of the window
  RunSimulation(unsigned int window_width, unsigned int window_height,
                const GameEngine &level_info,
                const std::string &directory_path);

  RunSimulation(const RunSimulation &other);
  RunSimulation &operator=(const RunSimulation &other);

  /// display current context to window
  /// \param window target to display button to
  void DrawToWindow(sf::RenderWindow &window) override;

  ///  handles incoming events,
  /// translates incoming event, and mouse position to ContextEvent
  /// \param event new even
  /// \param window source of mouse position info
  /// \return new translated event
  ContextEvent HandleEvent(sf::Event &event,
                           const sf::RenderWindow &window) override;

  /// clone function returns pointer to a new object of the Context type,
  /// \note new pointer must be deleted afterwards
  RunSimulation *Clone() override;

  LevelInfo GetLevelInfo() override;

  GameEngine GetLevel() override;

  std::string GetLevelDirectory() override;

  ~RunSimulation() override;

private:
  /// load pre-defined buttons to memory
  void LoadButtons();
  /// load background to memory and scale it to screen
  /// \param background_path path to wanted background
  void LoadBackground(const std::string &background_path);

  /// loads assets from file to memory
  void LoadAssets(const std::string &level_name);

  /// creates copy of a given cell, used to generate assets by rotating already
  /// existing ones
  /// \param copy id of created cell
  /// \param original original cell id
  /// \param flip the transformation witch will bu used to create new cell
  void CopyCell(Assets copy, Assets original, FlipDirection flip);

  /// loads cell from file to memory
  /// \param cell cell id
  /// \param asset_path path to the correct .png file
  void LoadCell(Assets cell, const std::string &asset_path);

  /// generates centered and scaled to size set of square geometries
  /// used to orient blocks on the screen and display grid
  void GenGrid();

  /// display centered grid lines
  /// \param window target window
  void DrawGrid(sf::RenderWindow &window);
  /// display cells to window
  /// \param window target to display button to
  void DrawCells(sf::RenderWindow &window);
  /// display cell to window
  /// \param window target to display button to
  void DrawCell(sf::RenderWindow &window, sfml_window::Assets id,
                unsigned position);

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
  /// the gray button background on top of the screen
  sf::RectangleShape button_background_;
  /// all of the buttons
  std::array<Button *, (unsigned)RunSimulationButton::SIZE> buttons_;
  /// list of used cells assets
  std::array<std::pair<sf::Texture, sf::Sprite>, (unsigned)Assets::SIZE> cells_;
  /// played level
  GameEngine local_board_;

  /// size of a square cell
  unsigned cell_size_;

  std::vector<sf::RectangleShape> grid_;

  bool display_grid_ = false;
  /// path to loaded level directory
  std::string level_directory_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_RUN_SIMULATION_H_
