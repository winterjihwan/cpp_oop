#ifndef LINE_FACTORY_H
#define LINE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>
#include <memory>

class LineFactory : public Shape_factory {
public:
  std::shared_ptr<Shape> createShape(const sf::Vector2f &position) override;
};

#endif // LINE_FACTORY_H
