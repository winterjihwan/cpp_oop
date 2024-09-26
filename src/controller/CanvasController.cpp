#include "CanvasController.h"

void Canvas_controller::create_rectangle() {
  sf::Drawable *new_shape = shape_factory->createShape();
  shapes.push_back(new_shape);

  canvas_view->update_view(shapes);
}
