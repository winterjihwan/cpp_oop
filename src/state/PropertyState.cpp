#include "PropertyState.h"

void PropertyState::handleMousePress(sf::Vector2f mousePos,
                                     CanvasController &controller,
                                     UIContext &context) {
  controller.edit_properties(mousePos);
}

void PropertyState::handleMouseMove(sf::Vector2f, CanvasController &,
                                    UIContext &) {}

void PropertyState::handleMouseRelease(sf::Vector2f, CanvasController &,
                                       UIContext &) {}

void PropertyState::handleKeyPress(sf::Keyboard::Key key, CanvasController &,
                                   StatusView &statusView) {
  if (key == sf::Keyboard::Enter) {
    statusView.confirmInput();
  }
}
