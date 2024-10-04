#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <string>

class Text : public Shape {
private:
  sf::Text text;
  sf::Font font;

public:
  Text(const std::string &content, float x, float y, unsigned int fontSize);

  std::string getText() const;

  void setText(const std::string &content);

  unsigned int getFontSize() const;

  void setFontSize(unsigned int fontSize);

  sf::Vector2f getPosition() const override;

  void setPosition(const sf::Vector2f &position) override;

  sf::Vector2f getSize() const override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif
