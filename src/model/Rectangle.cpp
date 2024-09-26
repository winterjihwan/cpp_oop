#include "Rectangle.h"

float Rectangle::get_width() { return shape.getSize().x; }
float Rectangle::get_height() { return shape.getSize().y; }

void Rectangle::set_size(Rectangle &rect, float width, float height) {
  shape.setPosition(width, height);
};
