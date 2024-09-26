#include "Shape.h"

class Rectangle : public Shape {
  int width, height;

public:
  Rectangle(int width, int height, double x_coor, double y_coor, int z)
      : Shape(x_coor, y_coor, z), width{width}, height{height} {}

  int get_height();
  int get_width();

  void set_size(Rectangle *rect, int height);
};
