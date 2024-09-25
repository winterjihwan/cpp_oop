#include "Rectangle.h"

class ShapeFactory {
public:
  virtual Shape *createShape() = 0;
};

class RectangleFactory : public ShapeFactory {
public:
  Shape *createShape() override { return new Rectangle(); }
};
