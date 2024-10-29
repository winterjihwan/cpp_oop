#include "CanvasView.h"
#include <vector>

Canvas_view::Canvas_view(sf::RenderWindow *window) : window{window} {}

void Canvas_view::render(const std::vector<Shape *> &shapes) {

  for (Shape *shape : shapes) {
    if (shape != nullptr) {
      window->draw(*shape);
    }
  }
}

void Canvas_view::update_view(const std::vector<Shape *> &shapes) {

  for (Shape *shape : shapes) {
    if (shape != nullptr) {
      window->draw(*shape);
    }
  }
}
