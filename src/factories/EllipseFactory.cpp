#include "EllipseFactory.h"
#include "../model/Ellipse.h"

std::shared_ptr<Shape>
EllipseFactory::createShape(const sf::Vector2f &position) {
  return std::make_shared<Ellipse>(position.x, position.y, 50.0f, 30.0f);
}
