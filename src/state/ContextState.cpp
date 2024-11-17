#include "ContextState.h"

void ContextState::handleMousePress(sf::Vector2f mousePos,
                                    CanvasController &controller,
                                    UIContext &context) {
  std::string selectedShapeType = controller.getSelectedShapeType();

  if (!selectedShapeType.empty()) {
    controller.create_shape(selectedShapeType, mousePos);
    context.setShouldCreateShape(false);
  } else {
    context.setInitialClickPosition(mousePos);
    context.setDragAttempted(false);

    bool multiSelect = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                       sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
    controller.select_shape(mousePos, multiSelect);

    if (controller.isSelectionActive()) {
      sf::Vector2f selectedPos =
          controller.isSingleSelection()
              ? controller.getSelectedShape()->getPosition()
              : controller.getCompositeShapePosition();
      context.setOffset(mousePos - selectedPos);
      context.setDragAttempted(true);
    } else {
      controller.deselect_shape();
    }
  }
}

void ContextState::handleMouseMove(sf::Vector2f mousePos,
                                   CanvasController &controller,
                                   UIContext &context) {
  if (!context.isDragging() && context.isDragAttempted()) {
    if (std::abs(mousePos.x - context.getInitialClickPosition().x) > 0.5f ||
        std::abs(mousePos.y - context.getInitialClickPosition().y) > 0.5f) {
      context.setDragging(true);
    }
  }

  if (context.isDragging()) {
    controller.move_shape(mousePos - context.getOffset());
  }
}

void ContextState::handleMouseRelease(sf::Vector2f mousePos,
                                      CanvasController &controller,
                                      UIContext &context) {
  context.setDragging(false);
  context.setDragAttempted(false);
  controller.end_drag();
}

void ContextState::handleKeyPress(sf::Keyboard::Key key,
                                  CanvasController &controller,
                                  StatusView &statusView) {
  if (key == sf::Keyboard::Enter && controller.getSelectedShape()) {
    statusView.applyChanges(controller.getSelectedShape());
  }
}
