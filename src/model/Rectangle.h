// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

class Rectangle : public Shape {
private:
  sf::RectangleShape shape;

public:
  Rectangle(float x, float y, float width, float height);

  float get_width() const;
  float get_height() const;

  bool isSelected(const sf::Vector2f &point) const override {
    return shape.getGlobalBounds().contains(point);
  }

  void set_size(float width, float height);

  sf::Vector2f getPosition() const override;

  void setPosition(const sf::Vector2f &position) override;

  sf::Vector2f getSize() const override;

  void setSize(const sf::Vector2f &size) override;

  void highlight() override;

  void unhighlight() override;

  sf::Color getColor() const override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // RECTANGLE_H
