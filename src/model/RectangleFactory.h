#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

// RectangleFactory class definition
class RectangleFactory : public Shape_factory {
public:
  // Function prototype (no implementation in the header file)
  Shape *createShape(const sf::Vector2f &position);
};

#endif // RECTANGLE_FACTORY_H
