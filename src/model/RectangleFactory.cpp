#include "RectangleFactory.h"

// Rectangle 도형 생성 함수의 구현부
sf::Drawable *RectangleFactory::createShape() {
  sf::RectangleShape *rectangle =
      new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f));
  rectangle->setFillColor(sf::Color::Green);
  return rectangle;
}
