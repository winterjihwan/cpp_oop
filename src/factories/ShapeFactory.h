#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "../model/Shape.h"
#include <memory>
#include <SFML/Graphics.hpp>

class Shape_factory
{
public:
  virtual ~Shape_factory() = default;
  virtual std::shared_ptr<Shape> createShape(const sf::Vector2f &position) = 0;
};

#endif // SHAPE_FACTORY_H
