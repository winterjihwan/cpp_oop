#ifndef IMAGE_FACTORY_H
#define IMAGE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>
#include <string>

class ImageFactory : public Shape_factory {
private:
  std::string filepath;

public:
  explicit ImageFactory(const std::string &filepath);

  Shape *createShape(const sf::Vector2f &position) override;
};

#endif // IMAGE_FACTORY_H
