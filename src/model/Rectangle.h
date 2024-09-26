#include <SFML/Graphics.hpp>

#ifndef SHAPE_H
#define SHAPE_H

#include "Shape.h"

#endif // SHAPE_H

class Rectangle : public sf::Drawable {
  sf::RectangleShape shape;

public:
  Rectangle(float width, float height, float x_coor, float y_coor, int z)
      : shape(sf::RectangleShape(sf::Vector2f(width, height))) {
    shape.setPosition(x_coor, y_coor);

    // TODO: color
    /*shape.setFillColor();*/
  }

  float get_width();
  float get_height();

  void set_size(Rectangle &rect, float width, float height);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
