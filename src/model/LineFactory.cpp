#include "LineFactory.h"
#include "Line.h"

Shape *LineFactory::createShape() {
  return new Line(sf::Vector2f(10.0f, 10.0f), sf::Vector2f(200.0f, 200.0f));
}
