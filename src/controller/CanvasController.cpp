#include "CanvasController.h"

Canvas_controller::Canvas_controller(Shape_factory *shape_factory,
                                     Canvas_view *canvas_view)
    : shape_factory{shape_factory}, canvas_view(canvas_view) {};

void Canvas_controller::create_rectangle() {
  sf::Drawable *new_shape = shape_factory->createShape();
  shapes.push_back(new_shape);

  canvas_view->render(shapes);
}
