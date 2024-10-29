#ifndef ELLIPSE_FACTORY_H
#define ELLIPSE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

class EllipseFactory : public Shape_factory {
public:
  Shape *createShape(const sf::Vector2f &position) override;
};

#endif // ELLIPSE_FACTORY_H
