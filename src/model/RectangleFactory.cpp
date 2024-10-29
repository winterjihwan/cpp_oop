#include "RectangleFactory.h"

Shape *RectangleFactory::createShape() {
  return new Rectangle(100.0f, 100.0f, 50.0f, 30.0f);
}
