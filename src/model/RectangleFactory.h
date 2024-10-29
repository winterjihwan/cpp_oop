#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include "Rectangle.h"
#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

class RectangleFactory : public Shape_factory {
public:
  Shape *createShape() override;
};

#endif // RECTANGLE_FACTORY_H
