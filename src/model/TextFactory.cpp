#include "TextFactory.h"

Shape *TextFactory::createShape() {
  return new Text(100.0f, 30.0f, "Hello world!");
}
