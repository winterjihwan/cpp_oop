#ifndef CANVAS_CONTROLLER_H
#define CANVAS_CONTROLLER_H

#include "../model/Shape.h"
#include "../model/ShapeFactory.h"
#include "../view/CanvasView.h"
#include "../view/StatusView.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Shape_factory;
class Canvas_view;
class StatusView;

class Canvas_controller {
private:
  Shape_factory *rectangle_factory;
  Shape_factory *ellipse_factory;
  Shape_factory *line_factory;
  Shape_factory *text_factory;
  Canvas_view *canvas_view;
  StatusView *status_view;

  std::vector<Shape *> shapes;
  Shape *selected_shape = nullptr;

  sf::Vector2f offset;
  bool is_selected = false;
  bool is_dragging = false;

public:
  Canvas_controller(Shape_factory *rectangle_factory,
                    Shape_factory *ellipse_factory, Shape_factory *line_factory,
                    Shape_factory *text_factory, Canvas_view *canvas_view,
                    StatusView *status_view);

  void create_rectangle();
  void create_ellipse();
  void create_line();
  void create_text();

  void select_shape(const sf::Vector2f &click_position);
  void move_shape(const sf::Vector2f &new_position);

  void deselect_shape();
  void end_drag();

  Shape *getSelectedShape() const;

  bool isStatusViewDirty = true;

  void render_shapes();
};

#endif // CANVAS_CONTROLLER_H
