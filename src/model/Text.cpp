#include "Text.h"

Text::Text(const std::string &content, float x, float y,
           unsigned int fontSize) {

  text.setFont(font);
  text.setString(content);
  text.setCharacterSize(fontSize);
  text.setPosition(x, y);
}

std::string Text::getText() const { return text.getString(); }

void Text::setText(const std::string &content) { text.setString(content); }

unsigned int Text::getFontSize() const { return text.getCharacterSize(); }

void Text::setFontSize(unsigned int fontSize) {
  text.setCharacterSize(fontSize);
}

sf::Vector2f Text::getPosition() const { return text.getPosition(); }

void Text::setPosition(const sf::Vector2f &position) {
  text.setPosition(position);
}

sf::Vector2f Text::getSize() const {
  sf::FloatRect bounds = text.getGlobalBounds();
  return sf::Vector2f(bounds.width, bounds.height);
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(text, states);
}
