// Rectangle.cpp
#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height) {
  shape.setPosition(x, y);
  shape.setSize(sf::Vector2f(width, height));
  shape.setFillColor(sf::Color::Green);
}

float Rectangle::get_width() const { return shape.getSize().x; }

float Rectangle::get_height() const { return shape.getSize().y; }

void Rectangle::set_size(float width, float height) {
  shape.setSize(sf::Vector2f(width, height));
}

sf::Vector2f Rectangle::getPosition() const { return shape.getPosition(); }

void Rectangle::setPosition(const sf::Vector2f &position) {
  shape.setPosition(position);
}

sf::Vector2f Rectangle::getSize() const { return shape.getSize(); }

void Rectangle::setSize(const sf::Vector2f &size) { shape.setSize(size); }

void Rectangle::highlight() {
  shape.setOutlineThickness(5.0f);
  shape.setOutlineColor(sf::Color::Red);
}

void Rectangle::unhighlight() {
  shape.setOutlineThickness(0.0f);
  shape.setOutlineColor(sf::Color::Black);
}

sf::Color Rectangle::getColor() const { return shape.getFillColor(); }

void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(shape, states);
}
