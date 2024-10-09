#include "Text.h"

// Constructor definition
Text::Text(float x, float y, const std::string &content,
           unsigned int characterSize) {
  if (!font.loadFromFile("FiraCode-Regular.ttf")) {
    throw std::runtime_error("Failed to load font");
  }

  text.setFont(font);
  text.setString(content);
  text.setCharacterSize(characterSize);
  text.setPosition(x, y);
  text.setFillColor(sf::Color::Black); // Default color
}

bool Text::isSelected(const sf::Vector2f &point) const {
  return text.getGlobalBounds().contains(point);
}

void Text::setPosition(const sf::Vector2f &position) {
  text.setPosition(position);
}

sf::Vector2f Text::getPosition() const { return text.getPosition(); }

void Text::setSize(const sf::Vector2f &size) {
  // Approximate scaling for text size adjustment.
  text.setScale(size.x / text.getLocalBounds().width,
                size.y / text.getLocalBounds().height);
}

sf::Vector2f Text::getSize() const {
  return {text.getGlobalBounds().width, text.getGlobalBounds().height};
}

void Text::setContent(const std::string &content) { text.setString(content); }

void Text::setCharacterSize(unsigned int size) { text.setCharacterSize(size); }

void Text::highlight() {
  text.setOutlineThickness(2.0f);
  text.setOutlineColor(sf::Color::Red);
}

void Text::unhighlight() {
  text.setOutlineThickness(0.0f);
  text.setOutlineColor(sf::Color::Transparent);
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(text, states);
}
