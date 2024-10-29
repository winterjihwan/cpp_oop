#include "CanvasController.h"
#include <iostream>

Canvas_controller::Canvas_controller(Shape_factory *rectangle_factory,
                                     Shape_factory *ellipse_factory,
                                     Shape_factory *line_factory,
                                     Shape_factory *text_factory,
                                     Canvas_view *canvas_view,
                                     StatusView *statusView, Sidebar *sidebar)
    : rectangle_factory{rectangle_factory}, ellipse_factory{ellipse_factory},
      line_factory{line_factory}, text_factory{text_factory},
      canvas_view(canvas_view), status_view(statusView), sidebar(sidebar) {}

void Canvas_controller::handleSidebarClick(const sf::Vector2f &clickPosition) {
  std::string shapeType = sidebar->handleClick(clickPosition);
  std::cout << "ShapeType: " << shapeType << "\n";
  if (!shapeType.empty()) {
    selectedShapeType = shapeType;
  }
}

void Canvas_controller::create_rectangle() {
  Shape *new_shape = rectangle_factory->createShape();
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::create_ellipse() {
  Shape *new_shape = ellipse_factory->createShape();
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::create_line() {
  Shape *new_shape = line_factory->createShape();
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::create_text() {
  Shape *new_shape = text_factory->createShape();
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::select_shape(const sf::Vector2f &click_position) {
  if (selected_shape != nullptr) {
    selected_shape->unhighlight();
    selected_shape = nullptr;
    is_selected = false;
  }

  for (auto &shape : shapes) {
    if (shape->isSelected(click_position)) {
      selected_shape = shape;
      is_selected = true;
      selected_shape->highlight();
      isStatusViewDirty = true;
      return;
    }
  }

  if (!is_selected) {
    isStatusViewDirty = true;
    status_view->clear();
  }
}

void Canvas_controller::move_shape(const sf::Vector2f &new_position) {
  if (selected_shape && is_selected) {
    selected_shape->setPosition(new_position - offset);
    isStatusViewDirty = true;
  }
}

void Canvas_controller::deselect_shape() {
  if (selected_shape != nullptr) {
    selected_shape->unhighlight();
    selected_shape = nullptr;
    is_selected = false;
    isStatusViewDirty = true;
    status_view->clear();
  }
}

Shape *Canvas_controller::getSelectedShape() const { return selected_shape; }

void Canvas_controller::render_shapes() { canvas_view->render(shapes); }

void Canvas_controller::end_drag() { is_dragging = false; }
