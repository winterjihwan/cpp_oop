#include "UIContext.h"
#include <iostream>

UIContext::UIContext(State *sidebar, State *contextDefault,
                     State *contextDragging, State *property)
    : sidebarState(sidebar), contextDefaultState(contextDefault),
      contextDraggingState(contextDragging), propertyState(property),
      currentState(contextDefault) {}

void UIContext::updateState(float cursorX, float windowWidth) {
  if (cursorX < 200.0f) {
    currentState = sidebarState;
  } else if (cursorX < windowWidth * 0.7f) {
    if (isDragging()) {
      currentState = contextDraggingState;
    } else {
      currentState = contextDefaultState;
    }
  } else {
    currentState = propertyState;
  }
}

State *UIContext::getState() { return currentState; }

sf::Vector2f UIContext::getOffset() const { return offset; }

void UIContext::setOffset(const sf::Vector2f &value) { offset = value; }

sf::Vector2f UIContext::getInitialClickPosition() const {
  return initial_click_position;
}

void UIContext::setInitialClickPosition(const sf::Vector2f &value) {
  initial_click_position = value;
}

bool UIContext::isDragging() const { return is_dragging; }

void UIContext::setDragging(bool value) { is_dragging = value; }

bool UIContext::getShouldCreateShape() const { return shouldCreateShape; }

void UIContext::setShouldCreateShape(bool value) { shouldCreateShape = value; }

bool UIContext::isDragAttempted() const { return drag_attempted; }

void UIContext::setDragAttempted(bool value) { drag_attempted = value; }
