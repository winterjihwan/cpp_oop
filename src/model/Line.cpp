#include "Line.h"
#include <cmath>

Line::Line(const sf::Vector2f &start, const sf::Vector2f &end) {
  line.setPrimitiveType(sf::Lines);
  line.resize(2);
  line[0].position = start;
  line[1].position = end;
  line[0].color = sf::Color::Red;
  line[1].color = sf::Color::Red;
}

sf::Vector2f Line::getPosition() const { return line[0].position; }

sf::Vector2f Line::getSize() const {
  return line[1].position - line[0].position;
}

void Line::setPosition(const sf::Vector2f &position) {
  sf::Vector2f offset = position - line[0].position;
  line[0].position += offset;
  line[1].position += offset;
}

void Line::setSize(const sf::Vector2f &size) {
  line[1].position = line[0].position + size;
}

bool Line::isSelected(const sf::Vector2f &point) const {
  sf::Vector2f p1 = line[0].position;
  sf::Vector2f p2 = line[1].position;
  float line_length_squared =
      (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
  float t =
      ((point.x - p1.x) * (p2.x - p1.x) + (point.y - p1.y) * (p2.y - p1.y)) /
      line_length_squared;

  if (t >= 0.0f && t <= 1.0f) {
    sf::Vector2f projection = p1 + t * (p2 - p1);
    float distance = sqrt((point.x - projection.x) * (point.x - projection.x) +
                          (point.y - projection.y) * (point.y - projection.y));

    return distance <= 5.0f;
  }

  return false;
}

void Line::highlight() {
  line[0].color = sf::Color::Yellow;
  line[1].color = sf::Color::Yellow;
}

void Line::unhighlight() {
  line[0].color = sf::Color::Red;
  line[1].color = sf::Color::Red;
}

sf::Color Line::getColor() const { return line[0].color; }

void Line::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(line, states);
}
