#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

class RectangleFactory : public Shape_factory {
public:
  Shape *createShape(const sf::Vector2f &position) override;
};

#endif // RECTANGLE_FACTORY_H
