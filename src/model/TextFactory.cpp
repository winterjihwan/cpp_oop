#include "TextFactory.h"

Shape *TextFactory::createShape(const sf::Vector2f &position) {
  return new Text(position.x, position.y, "Hello world!");
}
