#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <string>

// Text class definition inheriting from Shape
class Text : public Shape {
private:
  sf::Text text; // SFML's text object
  sf::Font font; // SFML font for rendering the text

public:
  Text(float x, float y, const std::string &content,
       unsigned int characterSize = 24);

  // Override methods from Shape class
  bool isSelected(const sf::Vector2f &point) const override;
  void setPosition(const sf::Vector2f &position) override;
  sf::Vector2f getPosition() const override;
  void setSize(const sf::Vector2f &size) override;
  sf::Vector2f getSize() const override;

  void setContent(const std::string &content);
  void setCharacterSize(unsigned int size);

  void highlight() override;
  void unhighlight() override;

  // Override draw method from SFML's Drawable class
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  sf::Color getColor() const override;
};

#endif // TEXT_H
