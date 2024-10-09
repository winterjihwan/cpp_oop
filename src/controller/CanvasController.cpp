#include "CanvasController.h"
#include "Sidebar.h"
#include <iostream>

Canvas_controller::Canvas_controller(Shape_factory *rectangle_factory,
                                     Shape_factory *ellipse_factory,
                                     Shape_factory *line_factory,
                                     Shape_factory *text_factory,
                                     Canvas_view *canvas_view, Sidebar *sidebar)
    : rectangle_factory{rectangle_factory}, ellipse_factory{ellipse_factory},
      line_factory{line_factory}, text_factory{text_factory},
      canvas_view{canvas_view}, sidebar{sidebar} {}

void Canvas_controller::handleSidebarClick(const sf::Vector2f &clickPosition) {
  std::string shapeType = sidebar->handleClick(clickPosition);
  std::cout << "ShapeType: " << shapeType << "\n";
  if (!shapeType.empty()) {
    selectedShapeType = shapeType; // Store the selected shape type
  }
}

std::string Canvas_controller::getSelectedShapeType() const {
  return selectedShapeType; // Return the currently selected shape type
}

void Canvas_controller::create_shape(const std::string &shapeType,
                                     const sf::Vector2f &position) {
  if (shapeType.empty())
    return; // No shape type selected, do nothing

  Shape *new_shape = nullptr;
  if (shapeType == "Rectangle") {
    new_shape = rectangle_factory->createShape(position);
  } else if (shapeType == "Ellipse") {
    new_shape = ellipse_factory->createShape(position);
  } else if (shapeType == "Line") {
    new_shape = line_factory->createShape(position);
  } else if (shapeType == "Text") {
    new_shape = text_factory->createShape(position);
  }

  if (new_shape) {
    shapes.push_back(new_shape);
    canvas_view->render(shapes);
  }
}

void Canvas_controller::select_shape(const sf::Vector2f &click_position) {
  // Deselect the currently selected shape, if any
  if (selected_shape != nullptr) {
    selected_shape->unhighlight();
    selected_shape = nullptr;
    is_selected = false;
  }

  // Iterate through shapes to find the one at the click position
  for (auto &shape : shapes) {
    if (shape->isSelected(click_position)) {
      selected_shape = shape;
      is_selected = true;
      selected_shape->highlight(); // Highlight the selected shape
      break;
    }
  }

  if (!is_selected) {
    selected_shape = nullptr;
  }

  canvas_view->render(shapes); // Update the view with changes
}

void Canvas_controller::move_shape(const sf::Vector2f &new_position) {
  if (!selected_shape || !is_selected) {
    return;
  }

  selected_shape->setPosition(new_position - offset);
}

void Canvas_controller::deselect_shape() {
  if (selected_shape != nullptr) {
    selected_shape->unhighlight();
    selected_shape = nullptr;
    is_selected = false;
    canvas_view->render(shapes);
  }
}

void Canvas_controller::end_drag() { is_dragging = false; }

void Canvas_controller::render_shapes() { canvas_view->render(shapes); }

// 선택된 도형 반환
Shape *Canvas_controller::getSelectedShape() const { return selected_shape; }
