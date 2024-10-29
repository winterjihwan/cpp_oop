#include "RectangleFactory.h"

Shape *RectangleFactory::createShape(const sf::Vector2f &position) {
  return new Rectangle(position.x, position.y, 50.0f, 30.0f);
}
