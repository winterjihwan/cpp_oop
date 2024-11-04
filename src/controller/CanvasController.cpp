#include "CanvasController.h"
#include <iostream>

Canvas_controller::Canvas_controller(Shape_factory *rectangle_factory,
                                     Shape_factory *ellipse_factory,
                                     Shape_factory *line_factory,
                                     Shape_factory *text_factory,
                                     Shape_factory *image_factory,
                                     Canvas_view *canvas_view,
                                     StatusView *statusView, Sidebar *sidebar)
    : rectangle_factory{rectangle_factory}, ellipse_factory{ellipse_factory},
      line_factory{line_factory}, text_factory{text_factory},
      image_factory{image_factory}, canvas_view(canvas_view),
      status_view(statusView), sidebar(sidebar) {}

void Canvas_controller::handleSidebarClick(const sf::Vector2f &clickPosition) {
  std::string shapeType = sidebar->handleClick(clickPosition);
  std::cout << "ShapeType: " << shapeType << "\n";
  if (!shapeType.empty()) {
    selectedShapeType = shapeType;
  }
}

void Canvas_controller::create_shape(const std::string &shapeType,
                                     const sf::Vector2f &position) {
  if (shapeType.empty())
    return;

  Shape *new_shape = nullptr;
  if (shapeType == "Rectangle") {
    new_shape = rectangle_factory->createShape(position);
  } else if (shapeType == "Ellipse") {
    new_shape = ellipse_factory->createShape(position);
  } else if (shapeType == "Line") {
    new_shape = line_factory->createShape(position);
  } else if (shapeType == "Text") {
    new_shape = text_factory->createShape(position);
  } else if (shapeType == "Image") {
    new_shape = image_factory->createShape(position);
  }

  if (new_shape) {
    shapes.push_back(new_shape);
    canvas_view->render(shapes);
  }
}

void Canvas_controller::create_rectangle(const sf::Vector2f &position) {
  Shape *new_shape = rectangle_factory->createShape(position);
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::create_ellipse(const sf::Vector2f &position) {
  Shape *new_shape = ellipse_factory->createShape(position);
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::create_line(const sf::Vector2f &position) {
  Shape *new_shape = line_factory->createShape(position);
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::create_text(const sf::Vector2f &position) {
  Shape *new_shape = text_factory->createShape(position);
  shapes.push_back(new_shape);
  isStatusViewDirty = true;
}

void Canvas_controller::create_image(const sf::Vector2f &position) {
  Shape *new_shape = image_factory->createShape(position);
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

std::string Canvas_controller::getSelectedShapeType() const {
  return selectedShapeType;
}

void Canvas_controller::render_shapes() { canvas_view->render(shapes); }

void Canvas_controller::end_drag() { is_dragging = false; }

void Canvas_controller::sort_shapes_by_z() {
  std::sort(shapes.begin(), shapes.end(),
            [](Shape *a, Shape *b) { return a->getZ() < b->getZ(); });
}
