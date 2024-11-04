#include "Image.h"
#include <stdexcept>

Image::Image(float x, float y, const std::string &filepath) {
  if (!texture.loadFromFile(filepath)) {
    throw std::runtime_error("Failed to load image");
  }

  sprite.setTexture(texture);
  sprite.setPosition(x, y);
}

bool Image::isSelected(const sf::Vector2f &point) const {
  return sprite.getGlobalBounds().contains(point);
}

void Image::setPosition(const sf::Vector2f &position) {
  sprite.setPosition(position);
}

sf::Vector2f Image::getPosition() const { return sprite.getPosition(); }

void Image::setSize(const sf::Vector2f &size) {
  sprite.setScale(size.x / sprite.getLocalBounds().width,
                  size.y / sprite.getLocalBounds().height);
}

sf::Vector2f Image::getSize() const {
  return {sprite.getGlobalBounds().width, sprite.getGlobalBounds().height};
}

void Image::highlight() { sprite.setColor(sf::Color(255, 255, 255, 150)); }

void Image::unhighlight() { sprite.setColor(sf::Color(255, 255, 255, 255)); }

void Image::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(sprite, states);
}

sf::Color Image::getColor() const { return sprite.getColor(); }
