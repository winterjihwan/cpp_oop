#include "Rectangle.h"

#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "ShapeFactory.h"

#endif // SHAPE_FACTORY_H

class RectangleFactory : public Shape_factory {
public:
  RectangleFactory();
  sf::Drawable *createShape() override;
};
