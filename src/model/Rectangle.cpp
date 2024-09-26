#include "Rectangle.h"

int Rectangle::get_height() { return height; }
int Rectangle::get_width() { return width; }

void Rectangle::set_size(Rectangle *rect, int height) {
  rect->height = height;
};
