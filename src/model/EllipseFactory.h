#ifndef ELLIPSE_FACTORY_H
#define ELLIPSE_FACTORY_H

#include <SFML/Graphics.hpp>
#include "ShapeFactory.h"
#include "../model/Ellipse.h"

// EllipseFactory class definition
class EllipseFactory : public Shape_factory
{
public:
    // Function prototype (no implementation in the header file)
    Shape *createShape() override;
};

#endif // ELLIPSE_FACTORY_H
