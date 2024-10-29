#include "EllipseFactory.h"
#include "Ellipse.h"

Shape *EllipseFactory::createShape() {
  return new Ellipse(100.0f, 100.0f, 50.0f, 30.0f);
}
