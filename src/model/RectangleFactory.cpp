#include "RectangleFactory.h"

// Rectangle 도형 생성 함수의 구현부
Shape *RectangleFactory::createShape()
{
  return new Rectangle(100.0f, 100.0f, 50.0f, 30.0f); // Rectangle(x, y, width, height)
}
