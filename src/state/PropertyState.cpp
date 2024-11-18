#include "PropertyState.h"

void PropertyState::handleMousePress(sf::Vector2f mousePos,
                                     CanvasController &controller,
                                     UIContext &context)
{
  controller.setFocusField(mousePos);
}

void PropertyState::handleMouseMove(sf::Vector2f, CanvasController &,
                                    UIContext &) {}

void PropertyState::handleMouseRelease(sf::Vector2f, CanvasController &,
                                       UIContext &) {}

void PropertyState::handleKeyPress(sf::Keyboard::Key key,
                                   CanvasController &controller,
                                   StatusView &statusView)
{
  bool isCtrlPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
                       sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);

  if (isCtrlPressed)
  {
    if (key == sf::Keyboard::Z)
    {
      controller.undo();
    }
    else if (key == sf::Keyboard::Y)
    {
      controller.redo();
    }
  }
  else if (key == sf::Keyboard::Enter)
  {
    // Handle Enter key logic
    if (controller.getSelectedShape() && controller.isSingleSelection())
    {
      statusView.applyChanges(controller.getSelectedShape());
    }
  }
}

void PropertyState::handleTextInput(char character, StatusView &statusView,
                                    UIContext &)
{
  statusView.handleTextInput(character);
}
