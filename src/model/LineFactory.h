#ifndef LINE_FACTORY_H
#define LINE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

// LineFactory class definition
class LineFactory : public Shape_factory {
public:
  // Function prototype (no implementation in the header file)
  Shape *createShape(const sf::Vector2f &position) override;
};

#endif // LINE_FACTORY_H
