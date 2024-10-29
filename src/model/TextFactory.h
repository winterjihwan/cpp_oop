#ifndef TEXT_FACTORY_H
#define TEXT_FACTORY_H

#include "ShapeFactory.h"
#include "Text.h"
#include <SFML/Graphics.hpp>

class TextFactory : public Shape_factory {
public:
  Shape *createShape() override;
};

#endif // TEXT_FACTORY_H
