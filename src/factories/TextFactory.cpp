#include "TextFactory.h"
#include "../model/Text.h"

std::shared_ptr<Shape> TextFactory::createShape(const sf::Vector2f &position)
{
  return std::make_shared<Text>(position.x, position.y, "Sample Text");
}
