#include "ImageFactory.h"
#include "../model/Image.h"

ImageFactory::ImageFactory(const std::string &filepath) : filepath(filepath) {}

std::shared_ptr<Shape> ImageFactory::createShape(const sf::Vector2f &position) {
  auto image = std::make_shared<Image>(position.x, position.y, filepath);

  image->setSize({image->getSize().x * 0.07f, image->getSize().y * 0.07f});

  return image;
}
