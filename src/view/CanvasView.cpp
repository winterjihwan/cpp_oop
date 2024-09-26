#include "CanvasView.h"

void Renderer::render(sf::RenderWindow *window) {
  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      }
    }

    window->clear(sf::Color::Black);

    // render here

    window->display();
  }
}
