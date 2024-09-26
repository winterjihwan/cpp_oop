#include "RectangleFactory.h"
#include <SFML/Graphics.hpp>

sf::Drawable *RectangleFactory::createShape() {
  return new Rectangle(0, 0, 0.0, 0.0, 0);
}
