#include "Image.h"
#include <iostream>

Image::Image(const std::string &imagePath, float x, float y) {
  if (!texture.loadFromFile(imagePath)) {
    std::cerr << "Error: Failed to load image from file: " << imagePath
              << std::endl;
    throw std::runtime_error("Failed to load image from file: " + imagePath);
  }

  std::cout << "Image loaded successfully from: " << imagePath << std::endl;

  sprite.setTexture(texture);
  sprite.setPosition(x, y);

  std::cout << "Sprite position set to: (" << x << ", " << y << ")"
            << std::endl;
}

sf::Vector2f Image::getPosition() const { return sprite.getPosition(); }

void Image::setPosition(const sf::Vector2f &position) {
  sprite.setPosition(position);
}

sf::Vector2f Image::getSize() const {
  sf::FloatRect bounds = sprite.getGlobalBounds();
  return sf::Vector2f(bounds.width, bounds.height);
}

void Image::setSize(const sf::Vector2f &size) {
  sf::Vector2f currentSize = getSize();
  if (currentSize.x != 0 && currentSize.y != 0) {
    sprite.setScale(size.x / currentSize.x, size.y / currentSize.y);
  }
}

void Image::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(sprite, states);
}

bool Image::isSelected(const sf::Vector2f &point) const {
  return sprite.getGlobalBounds().contains(point);
}
