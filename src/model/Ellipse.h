#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

class Ellipse : public Shape {
private:
  sf::CircleShape ellipse;

public:
  Ellipse(float x, float y, float radiusX, float radiusY);

  float get_width() const;
  float get_height() const;

  bool isSelected(const sf::Vector2f &point) const override;

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

#endif // ELLIPSE_H
