// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class Shape : public sf::Drawable {
public:
  virtual ~Shape() = default;

  virtual sf::Vector2f getPosition() const = 0;

  virtual sf::Vector2f getSize() const = 0;

  virtual sf::Color getColor() const = 0;

  virtual void setPosition(const sf::Vector2f &position) = 0;

  virtual void setSize(const sf::Vector2f &size) = 0;

  virtual bool isSelected(const sf::Vector2f &point) const = 0;

  virtual void highlight() = 0;

  virtual void unhighlight() = 0;
};

#endif // SHAPE_H
