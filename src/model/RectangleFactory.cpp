#include "RectangleFactory.h"
#include "Rectangle.h"

// Rectangle 도형 생성 함수의 구현부
Shape *RectangleFactory::createShape(const sf::Vector2f &position) {
  return new Rectangle(position.x, position.y, 50.0f, 30.0f);
}
