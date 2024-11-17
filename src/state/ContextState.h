#ifndef CONTEXTSTATE_H
#define CONTEXTSTATE_H

#include "State.h"
#include "UIContext.h"

class ContextState : public State {
public:
  void handleMousePress(sf::Vector2f mousePos, CanvasController &controller,
                        UIContext &context) override;
  void handleMouseMove(sf::Vector2f mousePos, CanvasController &controller,
                       UIContext &context) override;
  void handleMouseRelease(sf::Vector2f mousePos, CanvasController &controller,
                          UIContext &context) override;
  void handleKeyPress(sf::Keyboard::Key key, CanvasController &controller,
                      StatusView &statusView) override;
  void handleTextInput(char character, StatusView &statusView,
                       UIContext &context) override;
};

#endif // CONTEXTSTATE_H
