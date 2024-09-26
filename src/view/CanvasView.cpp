#include "CanvasView.h"
#include <vector>

Canvas_view::Canvas_view(int width, int height)
    : window{sf::VideoMode(width, height), "oop cpp"} {};

void Canvas_view::render(std::vector<sf::Drawable *> shapes) {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear(sf::Color::Black);

    for (sf::Drawable *shape : shapes) {
      window.draw(*shape);
    }

    window.display();
  }
}

void update_view(std::vector<sf::Drawable *> shapes) {}
