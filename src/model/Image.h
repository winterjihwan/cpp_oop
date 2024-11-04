#ifndef IMAGE_H
#define IMAGE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <string>

class Image : public Shape {
private:
  sf::Sprite sprite;
  sf::Texture texture;

public:
  Image(float x, float y, const std::string &filepath);

  bool isSelected(const sf::Vector2f &point) const override;
  void setPosition(const sf::Vector2f &position) override;
  sf::Vector2f getPosition() const override;
  void setSize(const sf::Vector2f &size) override;
  sf::Vector2f getSize() const override;

  void highlight() override;
  void unhighlight() override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  sf::Color getColor() const override;
};

#endif // IMAGE_H
