#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "Shape.h"

#include <SFML/Graphics.hpp>

class Shape_factory {
public:
  virtual ~Shape_factory() = default;

  virtual Shape *createShape() = 0;
};

#endif // SHAPE_FACTORY_H
