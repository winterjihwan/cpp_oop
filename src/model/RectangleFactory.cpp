#include "RectangleFactory.h"
#include <SFML/Graphics.hpp>

RectangleFactory::RectangleFactory() {}

sf::Drawable *RectangleFactory::createShape() {
  return new Rectangle(50, 50, 30, 30, 0);
}
