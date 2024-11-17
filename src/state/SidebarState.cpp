#include "SidebarState.h"

void SidebarState::handleMousePress(sf::Vector2f mousePos,
                                    CanvasController &controller,
                                    UIContext &context) {
  controller.handleSidebarClick(mousePos);
  context.setShouldCreateShape(true);
}

void SidebarState::handleMouseMove(sf::Vector2f, CanvasController &,
                                   UIContext &) {}

void SidebarState::handleMouseRelease(sf::Vector2f, CanvasController &,
                                      UIContext &) {}

void SidebarState::handleKeyPress(sf::Keyboard::Key, CanvasController &,
                                  StatusView &) {}
