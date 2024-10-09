#include "Sidebar.h"
#include "../model/EllipseFactory.h"
#include "../model/LineFactory.h"
#include "../model/RectangleFactory.h"

Sidebar::Sidebar(float width, float height) {
  sidebarRect.setSize(sf::Vector2f(width, height));
  sidebarRect.setFillColor(sf::Color(200, 200, 200));
  initializeButtons();
  createPreviews();
}

void Sidebar::initializeButtons() {
  float buttonHeight = 50.0f;
  std::vector<std::string> labels = {"Rectangle", "Ellipse", "Line"};
  buttonLabels = labels;

  for (size_t i = 0; i < labels.size(); ++i) {
    sf::RectangleShape button;
    button.setSize(sf::Vector2f(sidebarRect.getSize().x, buttonHeight));
    button.setPosition(0.0f, i * (buttonHeight + 10.0f));
    button.setFillColor(sf::Color::White);
    buttons.push_back(button);
  }
}

void Sidebar::createPreviews() {
  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;

  // Create a rectangle preview shape
  std::unique_ptr<Shape> rectanglePreview(
      rectangleFactory.createShape({10.0f, 10.0f}));
  rectanglePreview->setSize({30.0f, 20.0f});
  previewShapes.push_back(std::move(rectanglePreview));

  // Create an ellipse preview shape
  std::unique_ptr<Shape> ellipsePreview(
      ellipseFactory.createShape({10.0f, 70.0f}));
  ellipsePreview->setSize({30.0f, 20.0f});
  previewShapes.push_back(std::move(ellipsePreview));

  // Create a line preview shape
  std::unique_ptr<Shape> linePreview(lineFactory.createShape({10.0f, 130.0f}));
  linePreview->setSize({30.0f, 2.0f});
  previewShapes.push_back(std::move(linePreview));
}

void Sidebar::render(sf::RenderWindow &window) {
  window.draw(sidebarRect);

  for (size_t i = 0; i < buttons.size(); ++i) {
    window.draw(buttons[i]);
    if (i < previewShapes.size()) {
      window.draw(*previewShapes[i]);
    }
  }
}

std::string Sidebar::handleClick(const sf::Vector2f &clickPosition) {
  for (size_t i = 0; i < buttons.size(); ++i) {
    if (buttons[i].getGlobalBounds().contains(clickPosition)) {
      return buttonLabels[i];
    }
  }
  return "";
}
