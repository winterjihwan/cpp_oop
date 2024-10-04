#ifndef ELLIPSE_FACTORY_H
#define ELLIPSE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

// EllipseFactory class definition
class EllipseFactory : public Shape_factory {
public:
  // Function prototype (no implementation in the header file)
  sf::Drawable *createShape() override;
};

#endif // ELLIPSE_FACTORY_H
