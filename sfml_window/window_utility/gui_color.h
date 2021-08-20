//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_GUI_COLOR_H_
#define BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_GUI_COLOR_H_
#include "SFML/Graphics/Color.hpp"
#include <corecrt_math.h>
#define YELLOW sf::Color::Yellow
#define RED sf::Color::Red
#define BLUE sf::Color::Blue
#define GREEN sf::Color::Green
#define WHITE sf::Color::White


/// \param color primary color, to be lighten
/// \return light/ brighter  version of the primary color
sf::Color Light(const sf::Color& color);
/// generates rainbow gradient
/// \param value wanted color
/// \param max_value the rainbow colors will be generated in range 0 - max_value
/// \return the color corresponding to the specific value from range 0 - max_value
sf::Color Rainbow(unsigned value, unsigned max_value);
#endif // BLOCK_V2_SFML_WINDOW_WINDOW_UTILITY_GUI_COLOR_H_
