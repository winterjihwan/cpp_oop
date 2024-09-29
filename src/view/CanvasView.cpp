#include "CanvasView.h"
#include <vector>

Canvas_view::Canvas_view(int width, int height)
    : window{sf::VideoMode(width, height), "Oop cpp"} {};

void Canvas_view::render(std::vector<sf::Drawable *> shapes) {
  sf::Drawable *draggedShape = nullptr;
  sf::Vector2f offset;
  bool isDragging = false;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Handle mouse button press for dragging
      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          for (sf::Drawable *shape : shapes) {
            sf::Shape *shapePtr = dynamic_cast<sf::Shape *>(shape);
            if (shapePtr &&
                shapePtr->getGlobalBounds().contains(
                    window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
              isDragging = true;
              draggedShape = shapePtr;
              offset = shapePtr->getPosition() -
                       window.mapPixelToCoords(sf::Mouse::getPosition(window));
              break;
            }
          }
        }
      }

      // Handle mouse button release to stop dragging
      if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          isDragging = false;
          draggedShape = nullptr;
        }
      }

      // Handle mouse movement to drag the shape
      if (event.type == sf::Event::MouseMoved && isDragging && draggedShape) {
        sf::Shape *shapePtr = dynamic_cast<sf::Shape *>(draggedShape);
        if (shapePtr) {
          shapePtr->setPosition(
              window.mapPixelToCoords(sf::Mouse::getPosition(window)) + offset);
        }
      }
    }

    window.clear(sf::Color::Black);

    for (sf::Drawable *shape : shapes) {
      window.draw(*shape);
    }

    window.display();
  }
}

void update_view(std::vector<sf::Drawable *> shapes) {}
