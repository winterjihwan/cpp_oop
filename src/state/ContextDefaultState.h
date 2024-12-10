#ifndef CONTEXTDEFAULTSTATE_H
#define CONTEXTDEFAULTSTATE_H

#include "State.h"

class ContextDefaultState : public State {
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

#endif // CONTEXTDEFAULTSTATE_H
