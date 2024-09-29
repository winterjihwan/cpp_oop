#include "Rectangle.h"

Rectangle::Rectangle(float width, float height, float x_coor, float y_coor,
                     int z)
    : shape(sf::RectangleShape(sf::Vector2f(width, height))) {
  shape.setPosition(x_coor, y_coor);

  // TODO: color
  /*shape.setFillColor();*/
}

float Rectangle::get_width() { return shape.getSize().x; }
float Rectangle::get_height() { return shape.getSize().y; }

void Rectangle::set_size(Rectangle &rect, float width, float height) {
  shape.setPosition(width, height);
};

void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(shape, states);
}
