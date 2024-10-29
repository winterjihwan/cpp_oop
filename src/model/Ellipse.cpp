#include "Ellipse.h"

Ellipse::Ellipse(float x, float y, float radiusX, float radiusY) {
  ellipse.setPosition(x, y);
  ellipse.setRadius(radiusX);
  ellipse.setScale(1.0f, radiusY / radiusX);

  ellipse.setFillColor(sf::Color::Blue);
}

float Ellipse::get_width() const { return ellipse.getRadius() * 2.0f; }

float Ellipse::get_height() const {
  return ellipse.getRadius() * 2.0f * ellipse.getScale().y;
}

bool Ellipse::isSelected(const sf::Vector2f &point) const {
  sf::Vector2f center = ellipse.getPosition() +
                        sf::Vector2f(ellipse.getRadius(), ellipse.getRadius());
  float dx = (point.x - center.x) / ellipse.getScale().x;
  float dy = (point.y - center.y) / ellipse.getScale().y;
  return (dx * dx + dy * dy) <= ellipse.getRadius() * ellipse.getRadius();
}

void Ellipse::set_size(float width, float height) {
  ellipse.setRadius(width / 2.0f);
  ellipse.setScale(1.0f, height / width);
}

sf::Vector2f Ellipse::getPosition() const { return ellipse.getPosition(); }

void Ellipse::setPosition(const sf::Vector2f &position) {
  ellipse.setPosition(position);
}

sf::Vector2f Ellipse::getSize() const {
  return sf::Vector2f(ellipse.getRadius() * 2.0f,
                      ellipse.getRadius() * 2.0f * ellipse.getScale().y);
}

void Ellipse::setSize(const sf::Vector2f &size) { set_size(size.x, size.y); }

void Ellipse::highlight() {
  ellipse.setOutlineThickness(5.0f);
  ellipse.setOutlineColor(sf::Color::Red);
}

void Ellipse::unhighlight() {
  ellipse.setOutlineThickness(0.0f);
  ellipse.setOutlineColor(sf::Color::Black);
}

sf::Color Ellipse::getColor() const { return ellipse.getFillColor(); }

void Ellipse::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(ellipse, states);
}
