
#include "Sidebar.h"
#include "../model/EllipseFactory.h"
#include "../model/ImageFactory.h"
#include "../model/LineFactory.h"
#include "../model/RectangleFactory.h"
#include "../model/TextFactory.h"

Sidebar::Sidebar(float width, float height) {
  sidebarRect.setSize(sf::Vector2f(width, height));
  sidebarRect.setFillColor(sf::Color(200, 200, 200));
  initializeButtons();
  createPreviews();
}

void Sidebar::initializeButtons() {
  float buttonHeight = 50.0f;
  std::vector<std::string> labels = {"Rectangle", "Ellipse", "Line", "Text",
                                     "Image"};
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
  TextFactory textFactory;
  ImageFactory imageFactory("apple.png");

  std::unique_ptr<Shape> rectanglePreview(
      rectangleFactory.createShape({10.0f, 10.0f}));
  previewShapes.push_back(std::move(rectanglePreview));

  std::unique_ptr<Shape> ellipsePreview(
      ellipseFactory.createShape({10.0f, 70.0f}));
  ellipsePreview->setSize({30.0f, 20.0f});
  previewShapes.push_back(std::move(ellipsePreview));

  std::unique_ptr<Shape> linePreview(lineFactory.createShape({10.0f, 130.0f}));
  previewShapes.push_back(std::move(linePreview));

  std::unique_ptr<Shape> textPreview(textFactory.createShape({10.0f, 190.0f}));
  previewShapes.push_back(std::move(textPreview));

  std::unique_ptr<Shape> imagePreview(
      imageFactory.createShape({10.0f, 210.0f}));
  previewShapes.push_back(std::move(imagePreview));
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
