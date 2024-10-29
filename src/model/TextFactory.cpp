#include "TextFactory.h"

Shape *TextFactory::createShape() {
  return new Text(10.0f, 30.0f, "Hello world!");
}
