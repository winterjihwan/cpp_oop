#ifndef LINE_FACTORY_H
#define LINE_FACTORY_H

#include "ShapeFactory.h"
#include <SFML/Graphics.hpp>

class LineFactory : public Shape_factory {
public:
  Shape *createShape() override;
};

#endif // LINE_FACTORY_H
