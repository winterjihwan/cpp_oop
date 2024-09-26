#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "../model/ShapeFactory.h"

#endif // SHAPE_FACTORY_H

#ifndef CANVAS_VIEW_H
#define CANVAS_VIEW_H

#include "../view/CanvasView.h"

#endif // CANVAS_VIEW_H

#include <vector>

class Canvas_controller {
  Shape_factory *shape_factory;
  Canvas_view *canvas_view;
  std::vector<sf::Drawable *> shapes;

public:
  Canvas_controller(Shape_factory *shape_factory, Canvas_view *canvas_view)
      : shape_factory{shape_factory}, canvas_view(canvas_view){};
  ~Canvas_controller() = default;

  void create_rectangle();
};
