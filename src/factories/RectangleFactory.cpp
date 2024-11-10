#include "RectangleFactory.h"
#include "../model/Rectangle.h"

std::shared_ptr<Shape> RectangleFactory::createShape(const sf::Vector2f &position)
{
  return std::make_shared<Rectangle>(position.x, position.y, 100.0f, 50.0f);
}
