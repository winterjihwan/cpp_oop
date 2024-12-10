#include "ContextDraggingState.h"
#include "ContextDefaultState.h"
#include "UIContext.h"

void ContextDraggingState::handleMousePress(sf::Vector2f, CanvasController &,
                                            UIContext &) {}

void ContextDraggingState::handleMouseMove(sf::Vector2f mousePos,
                                           CanvasController &controller,
                                           UIContext &context) {
  controller.move_shape(mousePos - context.getOffset());
}

void ContextDraggingState::handleMouseRelease(sf::Vector2f mousePos,
                                              CanvasController &controller,
                                              UIContext &context) {
  context.setDragging(false);
  controller.end_drag();
  context.updateState(mousePos.x, 0);
}

void ContextDraggingState::handleKeyPress(sf::Keyboard::Key, CanvasController &,
                                          StatusView &) {}

void ContextDraggingState::handleTextInput(char, StatusView &, UIContext &) {}
