#include "LineFactory.h"
#include "../model/Line.h"

std::shared_ptr<Shape> LineFactory::createShape(const sf::Vector2f &position)
{
  return std::make_shared<Line>(position, sf::Vector2f(position.x + 100.0f, position.y));
}
