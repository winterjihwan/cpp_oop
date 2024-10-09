#include "LineFactory.h"
#include "Line.h"

// Line 도형 생성 함수의 구현부
Shape *LineFactory::createShape()
{
    return new Line(sf::Vector2f(10.0f, 10.0f), sf::Vector2f(200.0f, 200.0f)); // Line(startPoint, endPoint)
}
