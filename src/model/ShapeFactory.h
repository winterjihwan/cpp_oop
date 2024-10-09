#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

// Abstract factory class
class Shape_factory {
public:
  virtual ~Shape_factory() = default;

  // Pure virtual function: must be implemented by child classes
  virtual Shape *createShape(const sf::Vector2f &position) = 0;
};

#endif // SHAPE_FACTORY_H
