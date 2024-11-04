#include "ImageFactory.h"
#include "Image.h"

ImageFactory::ImageFactory(const std::string &filepath) : filepath(filepath) {}

Shape *ImageFactory::createShape(const sf::Vector2f &position) {
  Image *image = new Image(position.x, position.y, filepath);

  image->setSize({image->getSize().x * 0.07f, image->getSize().y * 0.07f});

  return image;
}
