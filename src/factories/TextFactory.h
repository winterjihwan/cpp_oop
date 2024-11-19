#ifndef TEXT_FACTORY_H
#define TEXT_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>
#include <memory>

class TextFactory : public Shape_factory {
public:
  std::shared_ptr<Shape> createShape(const sf::Vector2f &position) override;
};

#endif // TEXT_FACTORY_H
