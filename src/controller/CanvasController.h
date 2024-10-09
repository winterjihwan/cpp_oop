#ifndef CANVAS_CONTROLLER_H
#define CANVAS_CONTROLLER_H

#include "../model/Shape.h"
#include "../model/ShapeFactory.h"
#include "../view/CanvasView.h"
#include "Sidebar.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Shape_factory;
class Canvas_view;

class Canvas_controller {
private:
  Shape_factory *rectangle_factory;
  Shape_factory *ellipse_factory;
  Shape_factory *line_factory;
  Canvas_view *canvas_view;
  Sidebar *sidebar;

  std::string
      selectedShapeType; // Stores the selected shape type from the sidebar

  std::vector<Shape *> shapes; // Stores all shapes on the canvas

  Shape *selected_shape = nullptr; // The shape currently selected for dragging

  sf::Vector2f offset;      // Offset for dragging
  bool is_selected = false; // Indicates if a shape is selected for dragging
  bool is_dragging = false; // Indicates if a shape is being dragged

public:
  // Constructor
  Canvas_controller(Shape_factory *rectangle_factory,
                    Shape_factory *ellipse_factory, Shape_factory *line_factory,
                    Canvas_view *canvas_view, Sidebar *sidebar);

  void handleSidebarClick(const sf::Vector2f &clickPosition);

  // Create shapes based on selected type
  void create_shape(const std::string &shapeType, const sf::Vector2f &position);

  // Shape selection and movement
  void select_shape(const sf::Vector2f &click_position);
  void move_shape(const sf::Vector2f &new_position);

  // Shape deselection and drag end
  void deselect_shape();
  void end_drag();

  // 선택된 도형을 반환하는 메서드 (Shape* 타입으로 변경)
  Shape *getSelectedShape() const;

  // Get the currently selected shape type
  std::string getSelectedShapeType() const;

  // Redraw all shapes
  void render_shapes();
};

#endif // CANVAS_CONTROLLER_H
