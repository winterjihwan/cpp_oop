#include "CanvasController.h"
#include "../command/HighlightCommand.h"
#include "../command/MoveCommand.h"
#include "../command/ResizeCommand.h"
#include <iostream>

CanvasController::CanvasController(
    Shape_factory *rectangle_factory, Shape_factory *ellipse_factory,
    Shape_factory *line_factory, Shape_factory *text_factory,
    Shape_factory *image_factory, Canvas_view *canvas_view,
    StatusView *statusView, Sidebar *sidebar, Model *model)
    : rectangle_factory(rectangle_factory), ellipse_factory(ellipse_factory),
      line_factory(line_factory), text_factory(text_factory),
      image_factory(image_factory), canvas_view(canvas_view),
      status_view(statusView), sidebar(sidebar), selected_shape(nullptr),
      model(model) {}

void CanvasController::executeCommand(
    std::shared_ptr<CommandInterface> command) {
  commandManager.executeCommand(command);
}

void CanvasController::undo() { commandManager.undo(); }

void CanvasController::redo() { commandManager.redo(); }

void CanvasController::handleSidebarClick(const sf::Vector2f &clickPosition) {
  std::string shapeType = sidebar->handleClick(clickPosition);
  std::cout << "ShapeType: " << shapeType << "\n";
  if (!shapeType.empty()) {
    selectedShapeType = shapeType;
  }
}

void CanvasController::create_shape(const std::string &shapeType,
                                    const sf::Vector2f &position) {
  std::shared_ptr<Shape> new_shape = nullptr;
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
    model->addShape(new_shape);
  }

  selectedShapeType = "";
}

void CanvasController::select_shape(const sf::Vector2f &click_position,
                                    bool multiSelect) {
  static sf::Vector2f reference_position;

  if (selected_shape && selected_shape->isSelected(click_position)) {
    is_dragging = true;
    return;
  }

  if (!multiSelect) {
    deselect_shape();
    shape_offsets.clear();
  } else {
    if (!selected_shape) {
      selected_shape = std::make_shared<CompositeShape>();
    } else {
      auto composite =
          std::dynamic_pointer_cast<CompositeShape>(selected_shape);
      if (!composite) {
        composite = std::make_shared<CompositeShape>();
        composite->add(selected_shape);
        selected_shape = composite;
      }
    }

    auto composite = std::dynamic_pointer_cast<CompositeShape>(selected_shape);
    if (!composite) {
      throw std::runtime_error("Selected shape != CompositeShape");
    }

    for (auto &shape : model->getShapes()) {
      if (shape->isSelected(click_position)) {
        if (composite->contains(shape)) {
          composite->remove(shape);
          auto unhighlightCommand =
              std::make_shared<HighlightCommand>(shape, false);
          executeCommand(unhighlightCommand);
        } else {
          if (composite->empty()) {
            reference_position = shape->getPosition();
          }
          composite->add(shape);
          shape_offsets[shape] = shape->getPosition() - reference_position;

          auto highlightCommand =
              std::make_shared<HighlightCommand>(shape, true);
          executeCommand(highlightCommand);
        }
        isStatusViewDirty = true;
        return;
      }
    }
  }

  for (auto &shape : model->getShapes()) {
    if (shape->isSelected(click_position)) {
      selected_shape = shape;
      offset = shape->getPosition() - click_position;

      auto highlightCommand =
          std::make_shared<HighlightCommand>(selected_shape, true);
      executeCommand(highlightCommand);

      isStatusViewDirty = true;
      return;
    }
  }

  if (!multiSelect) {
    status_view->clear();
    isStatusViewDirty = true;
  }
}

void CanvasController::move_shape(const sf::Vector2f &new_position) {
  if (selected_shape) {
    auto moveCommand =
        std::make_shared<MoveCommand>(selected_shape, new_position);
    executeCommand(moveCommand);
    isStatusViewDirty = true;
    model->notify(model->getShapes());
  }
}

void CanvasController::resize_shape(const sf::Vector2f &new_size) {
  if (selected_shape) {
    auto resizeCommand =
        std::make_shared<ResizeCommand>(selected_shape, new_size);
    executeCommand(resizeCommand);
    isStatusViewDirty = true;
  }
}

void CanvasController::deselect_shape() {
  if (selected_shape) {
    auto unhighlightCommand =
        std::make_shared<HighlightCommand>(selected_shape, false);
    executeCommand(unhighlightCommand);
    selected_shape = nullptr;
  }
  isStatusViewDirty = true;
  status_view->clear();
  model->notify(model->getShapes());
}

std::shared_ptr<Shape> CanvasController::getSelectedShape() const {
  return selected_shape;
}

std::string CanvasController::getSelectedShapeType() const {
  return selectedShapeType;
}

void CanvasController::render_shapes() {
  canvas_view->update(model->getShapes());
}

void CanvasController::end_drag() {
  is_dragging = false;
  offset = sf::Vector2f(0, 0);
}

void CanvasController::sort_shapes_by_z() {
  std::sort(
      (model->getShapes()).begin(), (model->getShapes()).end(),
      [](const std::shared_ptr<Shape> &a, const std::shared_ptr<Shape> &b) {
        return a->getZ() < b->getZ();
      });
}

bool CanvasController::isSingleSelection() const {
  return selected_shape &&
         std::dynamic_pointer_cast<CompositeShape>(selected_shape) == nullptr;
}

bool CanvasController::isSelectionActive() const {
  return selected_shape != nullptr;
}

sf::Vector2f CanvasController::getCompositeShapePosition() const {
  if (selected_shape) {
    return selected_shape->getPosition();
  }
  return sf::Vector2f(0, 0);
}

void CanvasController::setFocusField(sf::Vector2f mousePos) {
  if (status_view->getPosXEntry().getGlobalBounds().contains(mousePos)) {
    status_view->setFocusedField(StatusView::FocusedField::PosX);
  } else if (status_view->getPosYEntry().getGlobalBounds().contains(mousePos)) {
    status_view->setFocusedField(StatusView::FocusedField::PosY);
  } else if (status_view->getSizeXEntry().getGlobalBounds().contains(
                 mousePos)) {
    status_view->setFocusedField(StatusView::FocusedField::SizeX);
  } else if (status_view->getSizeYEntry().getGlobalBounds().contains(
                 mousePos)) {
    status_view->setFocusedField(StatusView::FocusedField::SizeY);
  } else if (status_view->getZEntry().getGlobalBounds().contains(mousePos)) {
    status_view->setFocusedField(StatusView::FocusedField::Z);
  } else {
    status_view->setFocusedField(StatusView::FocusedField::None);
  }
}
