#ifndef TEXT_FACTORY_H
#define TEXT_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

class TextFactory : public Shape_factory {
public:
  sf::Drawable *createShape() override;
};

#endif
