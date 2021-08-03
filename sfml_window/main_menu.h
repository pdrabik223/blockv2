//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_
#define BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_

#include "button.h"
#include "context.h"
#include "text_box.h"
#include "text_button.h"
#include <array>
#include <vector>
namespace sfml_window {

enum class MainMenuButton {
  EXIT,
  PLAY_LEVEL,
  CREATE_LEVEL,
  MULTIPLAYER,
  CREDITS,
  SIZE
};
/// first screen player sees after lunching game
/// contains basic info as well as
class MainMenu : public Context {
public:
  MainMenu(unsigned int window_width, unsigned int window_height);

  void DrawToWindow(sf::RenderWindow &window) override;
  sfml_window::ContextEvent HandleEvent(sf::Event &event, const sf::RenderWindow &window) override;
  void ResizeWindow(unsigned int new_width, unsigned int new_height) override;

  ~MainMenu();

public:
  void LoadColors() override;

private:
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

protected:
  /// \format in pixels
  /// x axis domain = <0,window_width_>
  unsigned window_width_;

  /// \format in pixels
  /// y axis domain = <0,window_height_>
  unsigned window_height_;

  std::array<Button *, (unsigned)MainMenuButton::SIZE> buttons_;
  TextBox game_name_;
  TextBox author_name_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_MAIN_MENU_H_
