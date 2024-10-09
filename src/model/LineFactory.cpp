#include "LineFactory.h"
#include "Line.h"

// Line 도형 생성 함수의 구현부
Shape *LineFactory::createShape(const sf::Vector2f &position) {
  return new Line(sf::Vector2f(position.x, position.y),
                  sf::Vector2f(200.0f, 200.0f)); // Line(startPoint, endPoint)
}
