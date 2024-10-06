#include "ImageFactory.h"
#include "Image.h"

sf::Drawable *ImageFactory::createShape() {
  Image *image = new Image("/Users/anjihwan/cpp/cpp_oop/a.png", 50.0f, 50.0f);
  return image;
}
