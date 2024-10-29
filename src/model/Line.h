#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

class Line : public Shape {
private:
  sf::VertexArray line;

public:
  Line(const sf::Vector2f &start, const sf::Vector2f &end);

  sf::Vector2f getPosition() const override;
  sf::Vector2f getSize() const override;
  void setPosition(const sf::Vector2f &position) override;
  void setSize(const sf::Vector2f &size) override;
  bool isSelected(const sf::Vector2f &point) const override;

  void highlight() override;
  void unhighlight() override;

  sf::Color getColor() const override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // LINE_H
