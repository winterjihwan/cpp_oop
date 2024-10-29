#ifndef CANVAS_CONTROLLER_H
#define CANVAS_CONTROLLER_H

#include "../model/Shape.h"
#include "../model/ShapeFactory.h"
#include "../view/CanvasView.h"
#include "../view/Sidebar.h"
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
  Sidebar *sidebar;

  std::vector<Shape *> shapes;
  Shape *selected_shape = nullptr;

  std::string selectedShapeType;

  sf::Vector2f offset;
  bool is_selected = false;
  bool is_dragging = false;

public:
  Canvas_controller(Shape_factory *rectangle_factory,
                    Shape_factory *ellipse_factory, Shape_factory *line_factory,
                    Shape_factory *text_factory, Canvas_view *canvas_view,
                    StatusView *status_view, Sidebar *sidebar);

  void handleSidebarClick(const sf::Vector2f &clickPosition);

  void create_shape(const std::string &shapeType, const sf::Vector2f &position);

  void create_rectangle(const sf::Vector2f &position);
  void create_ellipse(const sf::Vector2f &position);
  void create_line(const sf::Vector2f &position);
  void create_text(const sf::Vector2f &position);

  void select_shape(const sf::Vector2f &click_position);
  void move_shape(const sf::Vector2f &new_position);

  void deselect_shape();
  void end_drag();

  Shape *getSelectedShape() const;
  std::string getSelectedShapeType() const;

  bool isStatusViewDirty = true;

  void render_shapes();
};

#endif // CANVAS_CONTROLLER_H
