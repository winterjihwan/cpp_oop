#include "EllipseFactory.h"
#include "Ellipse.h"

Shape *EllipseFactory::createShape(const sf::Vector2f &position) {
  return new Ellipse(position.x, position.y, 50.0f, 30.0f);
}
