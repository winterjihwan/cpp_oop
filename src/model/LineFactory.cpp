#include "LineFactory.h"
#include "Line.h"

Shape *LineFactory::createShape(const sf::Vector2f &position) {
  return new Line(sf::Vector2f(position.x, position.y),
                  sf::Vector2f(position.x + 200.0f, position.y + 100.0f));
}
