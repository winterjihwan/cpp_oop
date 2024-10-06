#ifndef IMAGE_H
#define IMAGE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

class Image : public Shape {
private:
  sf::Texture texture;
  sf::Sprite sprite;

public:
  Image(const std::string &imagePath, float x, float y);

  sf::Vector2f getPosition() const override;

  void setPosition(const sf::Vector2f &position) override;

  sf::Vector2f getSize() const override;

  void setSize(const sf::Vector2f &size) override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  bool isSelected(const sf::Vector2f &point) const override;
};

#endif
