#include "EllipseFactory.h"
#include "Ellipse.h"

// Ellipse 도형 생성 함수의 구현부
Shape *EllipseFactory::createShape(const sf::Vector2f &position) {
  return new Ellipse(position.x, position.y, 50.0f, 30.0f);
}
