#ifndef STATE_H
#define STATE_H

#include "../controller/CanvasController.h"
#include "../view/StatusView.h"
#include <SFML/Graphics.hpp>

class UIContext;

class State {
public:
  virtual ~State() = default;
  virtual void handleMousePress(sf::Vector2f mousePos,
                                CanvasController &controller,
                                UIContext &context) = 0;
  virtual void handleMouseRelease(sf::Vector2f mousePos,
                                  CanvasController &controller,
                                  UIContext &context) = 0;
  virtual void handleMouseMove(sf::Vector2f mousePos,
                               CanvasController &controller,
                               UIContext &context) = 0;
  virtual void handleKeyPress(sf::Keyboard::Key key,
                              CanvasController &controller,
                              StatusView &statusView) = 0;
  virtual void handleTextInput(char character, StatusView &statusView,
                               UIContext &context) = 0;
};

#endif // STATE_H
