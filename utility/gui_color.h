//
// Created by studio25 on 01.08.2021.
//

#ifndef BLOCK_V2_UTILITY_GUI_COLOR_H_
#define BLOCK_V2_UTILITY_GUI_COLOR_H_
#include "../sfml/include/SFML/Graphics/Color.hpp"

/// \param color primary color, to be lighten
/// \return light/ brighter  version of the primary color
sf::Color& Light(sf::Color& color);

#endif // BLOCK_V2_UTILITY_GUI_COLOR_H_
