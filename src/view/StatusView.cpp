#include "StatusView.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

StatusView::StatusView(sf::RenderWindow *window) : window(window) {
  if (!font.loadFromFile("FiraCode-Regular.ttf"))
    throw std::runtime_error("Failed to load font");

  statusBar.setSize(
      {window->getSize().x * 0.3f, static_cast<float>(window->getSize().y)});
  statusBar.setPosition(window->getSize().x * 0.7f, 0);
  statusBar.setFillColor(sf::Color(220, 220, 220, 255));

  positionLabel.setFont(font);
  positionLabel.setString("Position:");
  positionLabel.setCharacterSize(14);
  positionLabel.setFillColor(sf::Color::Black);
  positionLabel.setPosition(window->getSize().x * 0.7f + 10, 20);

  colorLabel.setFont(font);
  colorLabel.setString("Color:");
  colorLabel.setCharacterSize(14);
  colorLabel.setFillColor(sf::Color::Black);
  colorLabel.setPosition(window->getSize().x * 0.7f + 10, 60);

  sizeLabel.setFont(font);
  sizeLabel.setString("Size:");
  sizeLabel.setCharacterSize(14);
  sizeLabel.setFillColor(sf::Color::Black);
  sizeLabel.setPosition(window->getSize().x * 0.7f + 10, 100);

  posXEntryText.setFont(font);
  posYEntryText.setFont(font);
  sizeXEntryText.setFont(font);
  sizeYEntryText.setFont(font);

  posXEntryText.setCharacterSize(14);
  posYEntryText.setCharacterSize(14);
  sizeXEntryText.setCharacterSize(14);
  sizeYEntryText.setCharacterSize(14);

  posXEntryText.setFillColor(sf::Color::Black);
  posYEntryText.setFillColor(sf::Color::Black);
  sizeXEntryText.setFillColor(sf::Color::Black);
  sizeYEntryText.setFillColor(sf::Color::Black);

  posXEntryText.setPosition(window->getSize().x * 0.7f + 80, 20);
  posYEntryText.setPosition(window->getSize().x * 0.7f + 140, 20);
  sizeXEntryText.setPosition(window->getSize().x * 0.7f + 80, 100);
  sizeYEntryText.setPosition(window->getSize().x * 0.7f + 140, 100);

  colorValue.setFont(font);
  colorValue.setCharacterSize(14);
  colorValue.setFillColor(sf::Color::Black);
  colorValue.setPosition(window->getSize().x * 0.7f + 80, 60);
}

void StatusView::render(const Shape *shape) {

  window->draw(statusBar);
  window->draw(positionLabel);
  window->draw(colorLabel);
  window->draw(sizeLabel);

  if (shape != nullptr) {

    if (focusedField == FocusedField::None) {
      updateEntryFields(shape);
    }

    posXEntryText.setString(posXEntryValue);
    posYEntryText.setString(posYEntryValue);
    sizeXEntryText.setString(sizeXEntryValue);
    sizeYEntryText.setString(sizeYEntryValue);

    posXEntryText.setFillColor(focusedField == FocusedField::PosX
                                   ? sf::Color::Blue
                                   : sf::Color::Black);
    posYEntryText.setFillColor(focusedField == FocusedField::PosY
                                   ? sf::Color::Blue
                                   : sf::Color::Black);
    sizeXEntryText.setFillColor(focusedField == FocusedField::SizeX
                                    ? sf::Color::Blue
                                    : sf::Color::Black);
    sizeYEntryText.setFillColor(focusedField == FocusedField::SizeY
                                    ? sf::Color::Blue
                                    : sf::Color::Black);

    window->draw(posXEntryText);
    window->draw(posYEntryText);
    window->draw(sizeXEntryText);
    window->draw(sizeYEntryText);

    sf::Color shapeColor = shape->getColor();
    std::ostringstream colorStream;
    colorStream << "R: " << static_cast<int>(shapeColor.r)
                << ", G: " << static_cast<int>(shapeColor.g)
                << ", B: " << static_cast<int>(shapeColor.b);
    colorValue.setString(colorStream.str());
    window->draw(colorValue);
  } else {

    clear();
  }
}

void StatusView::clear() {
  posXEntryValue.clear();
  posYEntryValue.clear();
  sizeXEntryValue.clear();
  sizeYEntryValue.clear();
  colorValue.setString("");
}

void StatusView::updateEntryFields(const Shape *shape) {
  posXEntryValue = std::to_string(static_cast<int>(shape->getPosition().x));
  posYEntryValue = std::to_string(static_cast<int>(shape->getPosition().y));
  sizeXEntryValue = std::to_string(static_cast<int>(shape->getSize().x));
  sizeYEntryValue = std::to_string(static_cast<int>(shape->getSize().y));
}

void StatusView::setFocusedField(FocusedField field) { focusedField = field; }

void StatusView::handleTextInput(char inputChar) {
  std::string *currentEntry = nullptr;

  switch (focusedField) {
  case FocusedField::PosX:
    currentEntry = &posXEntryValue;
    break;
  case FocusedField::PosY:
    currentEntry = &posYEntryValue;
    break;
  case FocusedField::SizeX:
    currentEntry = &sizeXEntryValue;
    break;
  case FocusedField::SizeY:
    currentEntry = &sizeYEntryValue;
    break;
  default:
    std::cout << "No field is focused." << std::endl;
    return;
  }

  if (inputChar == '\b' && currentEntry != nullptr) {
    if (!currentEntry->empty()) {
      currentEntry->pop_back();
      std::cout << "Backspace pressed. Updated field: " << *currentEntry
                << std::endl;
    }
  } else if (std::isdigit(inputChar)) {
    *currentEntry += inputChar;
    std::cout << "Digit entered: " << inputChar
              << " Updated field: " << *currentEntry << std::endl;
  }
}

void StatusView::applyChanges(Shape *shape) {
  if (shape == nullptr)
    return;

  int newX = std::stoi(posXEntryValue);
  int newY = std::stoi(posYEntryValue);
  int newWidth = std::stoi(sizeXEntryValue);
  int newHeight = std::stoi(sizeYEntryValue);

  shape->setPosition(sf::Vector2f(newX, newY));
  shape->setSize(sf::Vector2f(newWidth, newHeight));
}
