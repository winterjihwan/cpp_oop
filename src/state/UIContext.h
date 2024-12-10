#ifndef UICONTEXT_H
#define UICONTEXT_H

#include "State.h"
#include <SFML/Graphics.hpp>

class UIContext {
private:
  State *sidebarState;
  State *contextDefaultState;
  State *contextDraggingState;
  State *propertyState;
  State *currentState;

  sf::Vector2f offset;
  sf::Vector2f initial_click_position;
  bool is_dragging = false;
  bool shouldCreateShape = false;
  bool drag_attempted = false;

public:
  UIContext(State *sidebar, State *contextDefault, State *contextDragging,
            State *property);

  void updateState(float cursorX, float windowWidth);
  State *getState();

  // Getters and setters
  sf::Vector2f getOffset() const;
  void setOffset(const sf::Vector2f &value);

  sf::Vector2f getInitialClickPosition() const;
  void setInitialClickPosition(const sf::Vector2f &value);

  bool isDragging() const;
  void setDragging(bool value);

  bool getShouldCreateShape() const;
  void setShouldCreateShape(bool value);

  bool isDragAttempted() const;
  void setDragAttempted(bool value);
};

#endif // UICONTEXT_H
