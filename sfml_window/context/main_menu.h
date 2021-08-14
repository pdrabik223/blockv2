//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_
#define BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_

#include "../window_utility/text_box.h"
#include "../window_utility/text_button.h"
#include "context.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <array>
#include <vector>
namespace sfml_window {

enum class MainMenuButton {
  PLAY_LEVEL,
  CREATE_LEVEL,
  MULTIPLAYER,
  CREDITS,
  EXIT,
  SIZE
};
/// first screen player sees after lunching game
/// contains basic info as well as
class MainMenu : public Context {
public:
  MainMenu(unsigned int window_width, unsigned int window_height);

  void DrawToWindow(sf::RenderWindow &window) override;
  ContextEvent HandleEvent(sf::Event &event,
                           const sf::RenderWindow &window) override;

  ~MainMenu();

private:
  void LoadColors() override;
  ///
  /// \param x the percentage value where object should be placed
  /// \param y the percentage value where object should be placed
  /// \return the position on the screen corresponding to given relative
  /// position
  Coord Align(double x, double y);

  /// creates shape of an object centered around x,y point
  /// \param x the percentage value where object should be placed
  /// \param y the percentage value where object should be placed
  /// \param width of the returned object
  /// \param height of the returned object
  /// \return the shape of centered object
  Rect Align(double x, double y, unsigned int width, unsigned int height);

  /// load pre-defined buttons to memory
  void LoadButtons();

  void LoadBackground();
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

  std::array<Button *, (unsigned)MainMenuButton::SIZE> buttons_;
  TextBox game_name_;
  TextBox author_name_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_
