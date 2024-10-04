#include "TextFactory.h"

sf::Drawable *TextFactory::createShape() {
  sf::Text *text = new sf::Text();

  sf::Font *font = new sf::Font();
  if (!font->loadFromFile("FiraCode-Regular.ttf")) {

    return nullptr;
  }

  text->setFont(*font);
  text->setString("Hello, World!");
  text->setCharacterSize(24);
  text->setFillColor(sf::Color::White);
  text->setPosition(50.f, 50.f);

  return text;
}
