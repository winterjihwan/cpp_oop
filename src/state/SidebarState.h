#ifndef SIDEBARSTATE_H
#define SIDEBARSTATE_H

#include "State.h"
#include "UIContext.h"

class SidebarState : public State {
public:
  void handleMousePress(sf::Vector2f mousePos, CanvasController &controller,
                        UIContext &context) override;
  void handleMouseMove(sf::Vector2f mousePos, CanvasController &controller,
                       UIContext &context) override;
  void handleMouseRelease(sf::Vector2f mousePos, CanvasController &controller,
                          UIContext &context) override;
  void handleKeyPress(sf::Keyboard::Key key, CanvasController &controller,
                      StatusView &statusView) override;
};

#endif // SIDEBARSTATE_H
