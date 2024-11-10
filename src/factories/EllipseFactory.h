#ifndef ELLIPSE_FACTORY_H
#define ELLIPSE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>
#include <memory>

class EllipseFactory : public Shape_factory
{
public:
  std::shared_ptr<Shape> createShape(const sf::Vector2f &position) override;
};

#endif // ELLIPSE_FACTORY_H
