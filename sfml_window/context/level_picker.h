//
// Created by studio25 on 03.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_
#define BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "context.h"
#include "text_button.h"
#include "image_button.h"
/// displays the content of the levels directory, and enables user to choose
/// witch level they want to play

namespace sfml_window {
struct LevelInfo{

  LevelInfo(Coord position,std::string level_path,unsigned text_size,sf::Color color);
  void DrawToWindow(sf::RenderWindow &window);

  TextButton level;
  // throfeas
};


enum class LevelPickerButton { EXIT, SIZE };

class LevelPicker : public Context {

  /// open chose level screen
  /// \param window_height of the window
  /// \param window_width of the window
  LevelPicker(unsigned int window_width, unsigned int window_height);

  void LoadColors() override;
  void DrawToWindow(sf::RenderWindow &window) override;

  sfml_window::ContextEvent HandleEvent(sf::Event &event,
                                        const sf::RenderWindow &window) override ;

  void LoadButtons();

  void LoadLevelInfo();
public:
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

  std::array<Button *, (unsigned)LevelPickerButton::SIZE> buttons_;
};
} // namespace sfml_window
#endif // BLOCK_V2_SFML_WINDOW_CONTEXT_LEVEL_PICKER_H_
