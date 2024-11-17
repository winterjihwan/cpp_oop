#include "PropertyState.h"

void PropertyState::handleMousePress(sf::Vector2f mousePos,
                                     CanvasController &controller,
                                     UIContext &context) {
  controller.setFocusField(mousePos);
}

void PropertyState::handleMouseMove(sf::Vector2f, CanvasController &,
                                    UIContext &) {}

void PropertyState::handleMouseRelease(sf::Vector2f, CanvasController &,
                                       UIContext &) {}

void PropertyState::handleKeyPress(sf::Keyboard::Key key,
                                   CanvasController &controller,
                                   StatusView &statusView) {
  if (key == sf::Keyboard::Enter) {
    if (controller.getSelectedShape() && controller.isSingleSelection()) {
      statusView.applyChanges(controller.getSelectedShape());
    }
  }
}

void PropertyState::handleTextInput(char character, StatusView &statusView,
                                    UIContext &) {
  statusView.handleTextInput(character);
}
