#include "EllipseFactory.h"
#include "Ellipse.h"

// Ellipse 도형 생성 함수의 구현부
Shape *EllipseFactory::createShape() {
  return new Ellipse(100.0f, 100.0f, 50.0f,
                     30.0f); // Ellipse(x, y, radiusX, radiusY)
}
