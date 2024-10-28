#ifndef CANVAS_CONTROLLER_H
#define CANVAS_CONTROLLER_H

#include "../model/ShapeFactory.h"
#include "../view/CanvasView.h"
#include "../view/StatusView.h"
#include "../model/Shape.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Shape_factory;
class Canvas_view;
class StatusView;

class Canvas_controller
{
private:
  Shape_factory *rectangle_factory;
  Shape_factory *ellipse_factory;
  Shape_factory *line_factory;
  Canvas_view *canvas_view;
  StatusView *status_view;

  std::vector<Shape *> shapes;
  Shape *selected_shape = nullptr;

  sf::Vector2f offset;
  bool is_selected = false;
  bool is_dragging = false;

public:
  // Constructor
  Canvas_controller(Shape_factory *rectangle_factory, Shape_factory *ellipse_factory, Shape_factory *line_factory, Canvas_view *canvas_view, StatusView *status_view);

  // Shape creation and management
  void create_rectangle();
  void create_ellipse();
  void create_line();

  // Shape selection and movement
  void select_shape(const sf::Vector2f &click_position);
  void move_shape(const sf::Vector2f &new_position);

  // Deselect shape and end drag
  void deselect_shape();
  void end_drag();

  // Getter for the selected shape
  Shape *getSelectedShape() const;

  bool isStatusViewDirty = true; // Set to true initially because empty statusview should be displayed

  // Render all shapes
  void render_shapes();
};

#endif // CANVAS_CONTROLLER_H
