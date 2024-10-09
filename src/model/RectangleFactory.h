#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>
#include "Rectangle.h"

// RectangleFactory class definition
class RectangleFactory : public Shape_factory
{
public:
  // Function prototype (no implementation in the header file)
  Shape *createShape() override;
};

#endif // RECTANGLE_FACTORY_H
