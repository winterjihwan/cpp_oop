#include "CompositeShape.h"

CompositeShape::CompositeShape() = default;

CompositeShape::~CompositeShape() = default;

void CompositeShape::add(std::shared_ptr<Shape> shape) {
  children.push_back(shape);
}

void CompositeShape::remove(std::shared_ptr<Shape> shape) {
  children.erase(std::remove(children.begin(), children.end(), shape),
                 children.end());
}

void CompositeShape::clear() { children.clear(); }

bool CompositeShape::empty() const { return children.empty(); }

bool CompositeShape::isSelected(const sf::Vector2f &point) const {
  for (const auto &child : children) {
    if (child->isSelected(point)) {
      return true;
    }
  }
  return false;
}

std::shared_ptr<Shape> CompositeShape::getChild(int index) const {
  if (index >= 0 && index < children.size()) {
    return children[index];
  }
  return nullptr;
}

const std::vector<std::shared_ptr<Shape>> &CompositeShape::getChildren() const {
  return children;
}

void CompositeShape::setPosition(const sf::Vector2f &newPosition) {
  if (!children.empty()) {
    sf::Vector2f currentCompositePosition = getPosition();

    sf::Vector2f delta = newPosition - currentCompositePosition;

    for (auto &child : children) {
      child->setPosition(child->getPosition() + delta);
    }
  }
}

sf::Vector2f CompositeShape::getPosition() const {
  if (children.empty())
    return sf::Vector2f(0, 0);

  float minX = children[0]->getPosition().x;
  float minY = children[0]->getPosition().y;
  float maxX = minX;
  float maxY = minY;

  for (const auto &child : children) {
    sf::Vector2f pos = child->getPosition();
    minX = std::min(minX, pos.x);
    minY = std::min(minY, pos.y);
    maxX = std::max(maxX, pos.x);
    maxY = std::max(maxY, pos.y);
  }

  return sf::Vector2f((minX + maxX) / 2.0f, (minY + maxY) / 2.0f);
}

void CompositeShape::setSize(const sf::Vector2f &size) {
  for (auto &child : children) {
    child->setSize(size);
  }
}

sf::Vector2f CompositeShape::getSize() const {
  if (!children.empty()) {
    return children[0]->getSize();
  }
  return sf::Vector2f(0, 0);
}

void CompositeShape::highlight() {
  for (auto &child : children) {
    child->highlight();
  }
}

void CompositeShape::unhighlight() {
  for (auto &child : children) {
    child->unhighlight();
  }
}

sf::Color CompositeShape::getColor() const {
  if (!children.empty()) {
    return children[0]->getColor();
  }
  return sf::Color::Black;
}

void CompositeShape::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
  for (const auto &child : children) {
    target.draw(*child, states);
  }
}

bool CompositeShape::contains(const std::shared_ptr<Shape> &shape) const {
  return std::find(children.begin(), children.end(), shape) != children.end();
}
