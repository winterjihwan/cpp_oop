#ifndef CONTEXTDRAGGINGSTATE_H
#define CONTEXTDRAGGINGSTATE_H

#include "State.h"

class ContextDraggingState : public State {
public:
  void handleMousePress(sf::Vector2f, CanvasController &, UIContext &) override;
  void handleMouseMove(sf::Vector2f mousePos, CanvasController &controller,
                       UIContext &context) override;
  void handleMouseRelease(sf::Vector2f mousePos, CanvasController &controller,
                          UIContext &context) override;
  void handleKeyPress(sf::Keyboard::Key key, CanvasController &controller,
                      StatusView &statusView) override;
  void handleTextInput(char character, StatusView &statusView,
                       UIContext &context) override;
};

#endif // CONTEXTDRAGGINGSTATE_H
