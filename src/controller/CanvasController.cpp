#include "CanvasController.h"
#include "../command/HighlightCommand.h"
#include "../command/MoveCommand.h"
#include "../command/ResizeCommand.h"
#include <iostream>

CanvasController::CanvasController(Shape_factory *rectangle_factory,
                                   Shape_factory *ellipse_factory,
                                   Shape_factory *line_factory,
                                   Shape_factory *text_factory,
                                   Shape_factory *image_factory,
                                   Canvas_view *canvas_view,
                                   StatusView *statusView, Sidebar *sidebar)
    : single_selected_shape(nullptr), rectangle_factory{rectangle_factory},
      ellipse_factory{ellipse_factory}, line_factory{line_factory},
      text_factory{text_factory}, image_factory{image_factory},
      canvas_view(canvas_view), status_view(statusView), sidebar(sidebar),
      selected_shapes(std::make_shared<CompositeShape>()) {}

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
    shapes.push_back(new_shape);
    canvas_view->render(shapes);
  }

  selectedShapeType = "";
}

void CanvasController::select_shape(const sf::Vector2f &click_position,
                                    bool multiSelect) {
  static sf::Vector2f reference_position;

  if (!multiSelect) {
    bool clickedOnSelectedShape = selected_shapes->isSelected(click_position);

    if (clickedOnSelectedShape) {
      is_dragging = true;
      return;
    } else {
      deselect_shape();
      shape_offsets.clear();
    }
  }

  bool shapeClicked = false;

  for (auto &shape : shapes) {
    if (shape->isSelected(click_position)) {
      shapeClicked = true;

      if (multiSelect) {
        if (single_selected_shape &&
            !selected_shapes->contains(single_selected_shape)) {
          reference_position = single_selected_shape->getPosition();

          selected_shapes->add(single_selected_shape);
          shape_offsets[single_selected_shape] =
              single_selected_shape->getPosition() - reference_position;
          auto highlightCommand = std::make_shared<HighlightCommand>(
              single_selected_shape, true); // Highlighting
          executeCommand(highlightCommand);
          single_selected_shape = nullptr;
        }

        if (selected_shapes->empty()) {
          reference_position = shape->getPosition();
        }

        if (selected_shapes->contains(shape)) {
          selected_shapes->remove(shape);
          auto unhighlightCommand =
              std::make_shared<HighlightCommand>(shape, false);
          executeCommand(unhighlightCommand);
        } else {
          selected_shapes->add(shape);
          shape_offsets[shape] = shape->getPosition() - reference_position;
          auto highlightCommand =
              std::make_shared<HighlightCommand>(shape, true);
          executeCommand(highlightCommand);
        }
      } else {
        if (selected_shapes->contains(shape)) {
          single_selected_shape = nullptr;
        } else {
          single_selected_shape = shape;
          offset = shape->getPosition() - click_position;
          auto highlightCommand =
              std::make_shared<HighlightCommand>(shape, true);
          executeCommand(highlightCommand);
        }
      }
      isStatusViewDirty = true;
      return;
    }
  }

  if (!multiSelect && !shapeClicked) {
    status_view->clear();
    isStatusViewDirty = true;
  }
}

void CanvasController::move_shape(const sf::Vector2f &new_position) {
  if (single_selected_shape) {
    auto moveCommand = std::make_shared<MoveCommand>(single_selected_shape,
                                                     new_position + offset);
    executeCommand(moveCommand);
    isStatusViewDirty = true;
  } else if (!selected_shapes->empty()) {
    for (const auto &pair : shape_offsets) {
      auto shape = pair.first;
      auto initial_offset = pair.second;

      auto moveCommand =
          std::make_shared<MoveCommand>(shape, new_position + initial_offset);
      executeCommand(moveCommand);
    }
    isStatusViewDirty = true;
  }
}

void CanvasController::resize_shape(const sf::Vector2f &new_size) {
  if (single_selected_shape) {
    auto resizeCommand =
        std::make_shared<ResizeCommand>(single_selected_shape, new_size);
    executeCommand(resizeCommand);
    isStatusViewDirty = true;
  } else if (!selected_shapes->empty()) {
    for (auto &shape : selected_shapes->getChildren()) {
      auto resizeCommand = std::make_shared<ResizeCommand>(shape, new_size);
      executeCommand(resizeCommand);
    }
    isStatusViewDirty = true;
  }
}

void CanvasController::deselect_shape() {
  if (single_selected_shape) {
    auto unhighlightCommand =
        std::make_shared<HighlightCommand>(single_selected_shape, false);
    executeCommand(unhighlightCommand);
    single_selected_shape = nullptr;
  }
  if (!selected_shapes->empty()) {
    for (auto &shape : selected_shapes->getChildren()) {
      auto unhighlightCommand =
          std::make_shared<HighlightCommand>(shape, false);
      executeCommand(unhighlightCommand);
    }
    selected_shapes->clear();
    shape_offsets.clear();
  }
  isStatusViewDirty = true;
  status_view->clear();
}

std::shared_ptr<Shape> CanvasController::getSelectedShape() const {
  return single_selected_shape;
}
std::string CanvasController::getSelectedShapeType() const {
  return selectedShapeType;
}

void CanvasController::render_shapes() { canvas_view->render(shapes); }

void CanvasController::end_drag() {
  is_dragging = false;
  offset = sf::Vector2f(0, 0);
}

void CanvasController::sort_shapes_by_z() {
  std::sort(
      shapes.begin(), shapes.end(),
      [](const std::shared_ptr<Shape> &a, const std::shared_ptr<Shape> &b) {
        return a->getZ() < b->getZ();
      });
}

bool CanvasController::isSingleSelection() const {
  return single_selected_shape != nullptr && selected_shapes->empty();
}

bool CanvasController::isSelectionActive() const {
  return single_selected_shape != nullptr || !selected_shapes->empty();
}

sf::Vector2f CanvasController::getCompositeShapePosition() const {
  if (!selected_shapes->empty()) {
    return selected_shapes->getChildren().front()->getPosition();
  }
  return sf::Vector2f(0, 0);
}

void CanvasController::edit_properties(sf::Vector2f mousePos) {
  // Example logic for editing properties
  // This assumes StatusView has methods to check which field is being edited
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
