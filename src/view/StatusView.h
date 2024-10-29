#ifndef STATUSVIEW_H
#define STATUSVIEW_H

#include "../model/Shape.h"
#include <SFML/Graphics.hpp>
#include <string>

class StatusView {
public:
  StatusView(sf::RenderWindow *window);

  enum class FocusedField { None, PosX, PosY, SizeX, SizeY };

  void render(const Shape *shape);
  void clear();
  void handleTextInput(char inputChar);
  void applyChanges(Shape *shape);
  void setFocusedField(FocusedField field);

  const sf::Text &getPosXEntry() const { return posXEntryText; }
  const sf::Text &getPosYEntry() const { return posYEntryText; }
  const sf::Text &getSizeXEntry() const { return sizeXEntryText; }
  const sf::Text &getSizeYEntry() const { return sizeYEntryText; }

private:
  sf::RenderWindow *window;
  sf::Font font;
  sf::RectangleShape statusBar;

  FocusedField focusedField = FocusedField::None;

  sf::Text positionLabel;
  sf::Text colorLabel;
  sf::Text sizeLabel;

  sf::Text posXEntryText;
  sf::Text posYEntryText;
  sf::Text sizeXEntryText;
  sf::Text sizeYEntryText;

  std::string posXEntryValue;
  std::string posYEntryValue;
  std::string sizeXEntryValue;
  std::string sizeYEntryValue;

  sf::Text colorValue;

  void displayText(const std::string &text, const sf::Vector2f &position);
  void updateEntryFields(const Shape *shape);
};

#endif // STATUSVIEW_H
