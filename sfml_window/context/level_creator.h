//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_CREATOR_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_CREATOR_H_

#include "context.h"

#include "image_button.h"
#include "text_button.h"
#include <toggle_sprite_button.h>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <short_level_info.h>
namespace sfml_window {

enum class LevelCreatorButton {
  EXIT,
  RUN_SIMULATION,
  CREATE_BORDER,
  INPUT_PANEL,
  SAVE_LEVEL,

  B_EMPTY,
  B_BEDROCK,
  B_ENEMY,
  B_ENGINE,
  B_FACTORY,
  B_TURN,
  B_GOAL,
  B_BASIC,

  SIZE
};

class LevelCreator : public Context {
public:
  /// run provided simulation
  /// \param level_info full level info object
  /// \param window_height of the window
  /// \param window_width of the window
  LevelCreator(unsigned int window_width, unsigned int window_height,
               const LevelInfo &level);

  LevelCreator(unsigned int window_width, unsigned int window_height);

  LevelCreator(const LevelCreator &other);

  LevelCreator& operator=(const LevelCreator &other);


  LevelCreator *Clone() override;

  void DrawToWindow(sf::RenderWindow &window) override;

  sfml_window::ContextEvent
  HandleEvent(sf::Event &event, const sf::RenderWindow &window) override;

  LevelInfo GetLevelInfo() override;
  GameEngine GetLevel() override;
  std::string GetLevelDirectory() override;
  ~LevelCreator() override;

private:
  void LoadButtons();
  /// loads assets from file to memory
  void LoadAssets();

  void DrawBorder();

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

  /// load background to memory and scale it to screen
  /// \param background_path path to wanted background
  void LoadBackground(const std::string &background_path);
  void GenGrid();

  void ClearBotButtonHighlight();

  void DrawGrid(sf::RenderWindow &window);
  void DrawCells(sf::RenderWindow &window);
  void DrawCell(sf::RenderWindow &window, sfml_window::Assets id,
                unsigned position);

  sf::Texture &Texture(Assets cell);
  sf::Sprite &Sprite(Assets cell);

  bool AddBotToGame(const Coord &mouse_position, const sf::Event &event);

  bool RotateBot(const Coord &mouse_position,const sf::Event &event);

  bool FlipSquareLock(const Coord &mouse_position,const sf::Event &event);

  ///
  /// \param x the percentage value where object should be placed
  /// \param y the percentage value where object should be placed
  /// \return the position on the screen corresponding to given relative
  /// position
  unsigned Align(double x);

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

  sf::RectangleShape button_background_;

  std::string level_directory_;

  LevelInfo level_;

  /// size of a square cell
  unsigned cell_size_;

  std::array<Button *, (unsigned)LevelCreatorButton::SIZE> buttons_;

  /// current bot user puts down
  BotType brush_ = BotType::EMPTY;

  std::array<std::pair<sf::Texture, sf::Sprite>, (unsigned)Assets::SIZE> cells_;

  std::vector<sf::RectangleShape> grid_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_CREATOR_H_
