#ifndef IMAGE_FACTORY_H
#define IMAGE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

class ImageFactory : public Shape_factory {
public:
  sf::Drawable *createShape() override;
};

#endif
